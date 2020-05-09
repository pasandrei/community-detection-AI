#include <iostream>
#include "Graph.h"
#include "Population.h"

int main() {
    std::string file_name = "facebook_combined.txt", graph_type = "undirected";
    int no_individuals = 10;

    Graph graph(file_name, graph_type);

    Population population(no_individuals, graph);

    std::cout << population;

    return 0;
}
