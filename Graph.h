#ifndef COMMUNITY_DETECTION_AI_GRAPH_H
#define COMMUNITY_DETECTION_AI_GRAPH_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Graph {
private:
    std::vector<std::vector<int>> adjacency_list_, adjacency_matrix_;
    int no_edges_ = 0;
    std::string graph_type_;

    void read_adjacency_list_and_matrix(const std::string &file_name, const std::string &graph_type);

public:
    Graph();

    Graph(const std::string &file_name, const std::string &graph_type);

    explicit Graph(const std::vector<std::pair<int, int>> &edges_list, int no_nodes);

    int size() const;

    const std::vector<int> &operator[](int index) const; // Overload the access operator

    const std::vector<std::vector<int>> &get_adjacency_matrix() const;

    int get_no_edges() const;

    const std::string &get_graph_type() const;
};

#endif
