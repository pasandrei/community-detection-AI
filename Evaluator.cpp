#include "Evaluator.h"

Evaluator::Evaluator(const Graph &graph) {
    // This constructor takes a Graph and creates the Evaluator functor

    graph_ = graph;
}

double Evaluator::evaluate(const std::vector<std::vector<int>> &clusters) const {
    double fitness = 0;

    for (auto &cluster:clusters) {
        int inside_cluster_edges = 0, total_edges_to_cluster = 0;

        for (int i = 0; i < cluster.size(); ++i) {
            int node1 = cluster[i];
            total_edges_to_cluster += graph_[node1].size();

            for (int j = i; j < cluster.size(); ++j) {
                int node2 = cluster[j];

                if (graph_.get_adjacency_matrix()[node1][node2] == 1) {
                    // We count each edge twice because the edges are undirected
                    inside_cluster_edges += 2;
                }
            }
        }

        double total_edges_proportion = 1.0 * total_edges_to_cluster / (2 * graph_.get_no_edges());
        total_edges_proportion *= total_edges_proportion;

        fitness += 1.0 * inside_cluster_edges / (2 * graph_.get_no_edges()) - total_edges_proportion;
    }

    return fitness;
}

// Overloading the () operator so that we can use the object as a function (so called Functor or Callable Object)
double Evaluator::operator()(const std::vector<std::vector<int>> &clusters) const {
    return evaluate(clusters);
}
