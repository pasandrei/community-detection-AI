#include "Graph.h"

// ========== PRIVATE METHODS ==========

void Graph::read_adjacency_list_and_matrix(const std::string &file_name, const std::string &graph_type) {
    std::ifstream file(file_name);

    int no_nodes, current_node, current_neighbour;
    file >> no_nodes >> no_edges_;

    adjacency_list_.resize(no_nodes);
    adjacency_matrix_.resize(no_nodes);

    for (int i = 0; i < no_nodes; ++i) {
        adjacency_matrix_[i].resize(no_nodes);
    }

    for (int i = 0; i < no_edges_; i++) {
        file >> current_node >> current_neighbour;

        adjacency_matrix_[current_node][current_neighbour]++;
        adjacency_list_[current_node].push_back(current_neighbour);

        if (graph_type == "undirected") {
            adjacency_list_[current_neighbour].push_back(current_node);
            adjacency_matrix_[current_neighbour][current_node]++;
        }
    }
}

// ========== PUBLIC METHODS ==========

Graph::Graph() {
    no_edges_ = 0;
    adjacency_list_ = {};
}

Graph::Graph(const std::string &file_name, const std::string &graph_type) {
    graph_type_ = graph_type;

    read_adjacency_list_and_matrix(file_name, graph_type);
}

int Graph::size() const {
    return adjacency_list_.size();
}

const std::vector<int> &Graph::operator[](const int index) const {
    return adjacency_list_[index];
}

const std::vector<std::vector<int>> &Graph::get_adjacency_matrix() const {
    return adjacency_matrix_;
}

int Graph::get_no_edges() const {
    return no_edges_;
}

const std::string &Graph::get_graph_type() const {
    return graph_type_;
}

Graph::Graph(const std::vector<std::pair<int, int>> &edges_list, int no_nodes) {
    adjacency_list_.resize(no_nodes);

    for (auto edge : edges_list) {
        int node = edge.first;
        int neighbour = edge.second;

        adjacency_list_[node].push_back(neighbour);
    }
}
