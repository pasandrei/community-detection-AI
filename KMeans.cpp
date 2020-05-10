#include <algorithm>
#include <random>
#include "KMeans.h"

/* This class implements the K-Means algorithm. Explanation can be found:
 * https://www.coursera.org/learn/machine-learning/lecture/93VPG/k-means-algorithm
 * In this class I implemented this algorithm for a graph and swapped the
 * Squared Euclidean Distance with the shortest distance between two nodes
 */

// ========== Public methods ==========
KMeans::KMeans(Graph &graph, int nr_clusters) {
    graph_ = graph;
    no_clusters_ = nr_clusters;

    std::vector<int> centroids;
    compute_random_centroids(centroids);

    clusters_ = compute_clusters(centroids);
}

void KMeans::step() {
    // This method does one iteration of the K-Means algorithm

    std::vector<int> centroids = get_centroids(); // move centroid step

    clusters_ = compute_clusters(centroids); // cluster assignment step
}

// ========== Private methods ==========
std::vector<int> KMeans::compute_random_centroids(std::vector<int> &centroids) {
    /* We compute no_clusters_ centroids by generating a random permutation
     * of the node indices. I used this method to avoid the collision problem
     * caused by randomly generating no_clusters_ distinct numbers.
     */

    for (int i = 0; i < graph_.size(); ++i) {
        centroids.push_back(i);
    }

    std::shuffle(centroids.begin(), centroids.end(), std::mt19937(std::random_device()()));

    centroids.resize(no_clusters_);
}

std::vector<std::vector<int>> KMeans::compute_clusters(const std::vector<int> &representatives) {
    std::vector<std::vector<int>> clusters(representatives.size());

    // FUTURE: nodes_to_community_id_ will be passed by reference
    nodes_to_community_id_ = breadth_first_search(representatives);

    for (int i = 0; i < nodes_to_community_id_.size(); ++i) {
        int cluster = nodes_to_community_id_[i];

        clusters[cluster].push_back(i);
    }

    return clusters;
}

std::vector<int> KMeans::breadth_first_search(const std::vector<int> &start_nodes) {
    /* In this function, the Breadth First Search (BFS) is used to compute the
     * the clusters formed by each node in start_nodes. Each node is assigned
     * to the group of the start node that was the closest. In order to do this
     * we use the fact that each node is reached first from the start_node that
     * is the closest.
     */

    std::queue<std::pair<int, int> > Q;
    std::vector<int> nodes_to_community_id(graph_.size(), -1);

    for (int i = 0; i < start_nodes.size(); ++i) {
        int start_node = start_nodes[i];

        nodes_to_community_id[start_node] = i;
        Q.push({start_node, i});
    }

    while (!Q.empty()) {
        int node = Q.front().first;
        int group = Q.front().second;
        Q.pop();

        for (auto neighbour:graph_[node]) { // We take every neighbour of the current node
            if (nodes_to_community_id[neighbour] == -1) {
                // Every neighbour that was not assigned to any community will be assigned to
                // the community of the current node and pushed to the queue
                nodes_to_community_id[neighbour] = group;
                Q.push({neighbour, group});
            }
        }
    }

    return nodes_to_community_id;
}

std::vector<int> KMeans::get_centroids() {
    std::vector<int> centroids;

    for (auto &cluster:clusters_) {
        int center = get_cluster_center(cluster);
        centroids.push_back(center);
    }

    return centroids;
}

int KMeans::get_cluster_center(const std::vector<int> &cluster) {
    int best_distance = INT32_MAX, cluster_center = 0;

    for (auto node:cluster) {
        // For each node distance to the farthest node is computer
        int longest_distance = breadth_first_search_distance(node);

        if (longest_distance < best_distance) {
            // We keep the node with the smallest maximum distance
            best_distance = longest_distance;
            cluster_center = node;
        }
    }

    return cluster_center;
}

int KMeans::breadth_first_search_distance(int start_node) {
    /* The Breadth First Search (BFS) is used to compute the minimum distance
     * from the start_node to each other node.
     * Here we use the BFS to get the minimum distance to the node that is the
     * farthest away from the start_node.
     */

    std::queue<std::pair<int, int>> Q({{start_node, 0}});

    std::vector<int> distance_vector(graph_.size(), -1);
    distance_vector[start_node] = 0;

    int current_distance;
    while (!Q.empty()) {
        int node = Q.front().first;
        current_distance = Q.front().second;
        Q.pop();

        for (auto neighbour:graph_[node]) {
            /* We compute the distance to each node that is:
             * A. not visited yet
             * B. in the same community with the start_node
             */

            if (distance_vector[neighbour] == -1 &&
                nodes_to_community_id_[neighbour] == nodes_to_community_id_[start_node]) {
                distance_vector[neighbour] = current_distance + 1;
                Q.push({neighbour, current_distance + 1});
            }
        }
    }

    // current_distance will be the distance to the node that was last visited
    return current_distance;
}
