#include <iostream>
#include "Graph.h"
#include "Population.h"

int main() {
    std::string file_name = "facebook_combined.txt", graph_type = "undirected";
    int no_individuals = 10;

    Graph graph(file_name, graph_type);

    Population population(no_individuals, graph);

    Individual offspring(population[0], population[1]);

    std::cout << offspring << "\n\n";

    int mutation_probability = 2;

    offspring.mutate(graph, mutation_probability);

    std::cout << offspring;

    return 0;
}
