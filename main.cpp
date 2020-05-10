#include <iostream>
#include "Graph.h"
#include "Population.h"

int main() {
    std::string file_name = "facebook_combined.txt", graph_type = "undirected";
    int no_individuals = 10;
    double mutation_probability = 0.02;
    int no_generations = 10;

    Graph graph(file_name, graph_type);

    Population population(no_individuals, graph, mutation_probability);

    std::cout << population.calculate_population_fitness() << "\n";

    for (int i = 0; i < no_generations; i++) {
        population.generate_offsprings();
        population.generate_next_generation();

        std::cout << population.calculate_population_fitness() << "\n";
    }

    return 0;
}
