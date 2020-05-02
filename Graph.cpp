#include "Graph.h"

const std::vector <std::vector<int>> &Graph::get_adjacency_list() const {
    return adjacency_list_;
}

Graph::Graph(const std::string& file_name, const std::string& graph_type) {
    std::ifstream file(file_name);
    int nodes, edges, current_node, current_neighbour;
    file >> nodes >> edges;
    adjacency_list_.resize(nodes);
    for (int i = 0; i < edges; i++) {
        file >> current_node >> current_neighbour;
        adjacency_list_[current_node].push_back(current_neighbour);
        if (graph_type == "undirected") {
            adjacency_list_[current_neighbour].push_back(current_node);
        }
    }
}

void Graph::print_graph() const {
    for (int i = 0; i < adjacency_list_.size(); i++) {
        std::cout << "neighbours for node " << i << ": ";
        for (int j : adjacency_list_[i]) {
            std::cout << j << ", ";
        }
        std::cout << std::endl;
    }
}

