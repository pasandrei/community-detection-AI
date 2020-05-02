#include <iostream>
#include "Graph.h"

int main() {
    std::string file_name = "facebook_combined.txt", graph_type = "undirected";

    Graph graph(file_name, graph_type);
    graph.print_graph();

    return 0;
}
