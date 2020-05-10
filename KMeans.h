#ifndef COMMUNITY_DETECTION_AI_KMEANS_H
#define COMMUNITY_DETECTION_AI_KMEANS_H

#include <queue>
#include <chrono>
#include "Graph.h"

class KMeans {
    /* This class implements the K-Means algorithm. Explanation can be found:
     * https://www.coursera.org/learn/machine-learning/lecture/93VPG/k-means-algorithm
     * In this class I implemented this algorithm for a graph and swapped the
     * Squared Euclidean Distance with the shortest distance between two nodes
     */

private:
    Graph graph_;
    int no_clusters_;
    std::vector<std::vector<int>> clusters_;
    std::vector<int> nodes_to_community_id_;

    std::vector<int> compute_random_centroids(std::vector<int> &centroids);

    std::vector<std::vector<int>> compute_clusters(const std::vector<int> &centroids);

    std::vector<int> breadth_first_search(const std::vector<int> &start_nodes);

    std::vector<int> get_centroids();

    int get_cluster_centroid(const std::vector<int> &cluster);

    int breadth_first_search_distance(int start_node);

public:
    KMeans(Graph &graph, int no_clusters);

    void step();

    const std::vector<std::vector<int>> &get_clusters() const;
};


#endif //COMMUNITY_DETECTION_AI_KMEANS_H
