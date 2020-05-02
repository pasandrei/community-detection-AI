//
// Created by Ale on 5/2/2020.
//

#ifndef COMMUNITY_DETECTION_AI_GRAPH_H
#define COMMUNITY_DETECTION_AI_GRAPH_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Graph {
private:
    std::vector<std::vector<int>> adjacency_list_;

public:
    Graph(const std::string& file_name, const std::string& graph_type);

    const std::vector<std::vector<int>> &get_adjacency_list() const;

    void print_graph() const;
};

#endif
