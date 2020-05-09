#ifndef COMMUNITY_DETECTION_AI_GRAPH_H
#define COMMUNITY_DETECTION_AI_GRAPH_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Graph {
private:
    std::vector<std::vector<int>> adjacency_list_;

    void read_adjacency_list_from_file(const std::string &file_name, const std::string &graph_type);

public:
    Graph();

    Graph(const std::string &file_name, const std::string &graph_type);

    int size() const;

    void print_graph() const;

    const std::vector<int> &operator[](int index) const; // Overload the access operator
};

#endif
