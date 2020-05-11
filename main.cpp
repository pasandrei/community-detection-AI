#include <iostream>
#include "Graph.h"
#include "Population.h"

int main() {
    std::string file_name = "facebook_combined.txt", graph_type = "undirected";
    int no_individuals = 100;
    double mutation_probability = 0.02;
    int no_generations = 20;

    Graph graph(file_name, graph_type);

    Population population(no_individuals, graph, mutation_probability);

    for (int i = 0; i < no_generations; i++) {
        population.generate_offsprings();
        population.generate_next_generation();
    }

    Individual best_individual = population[0];

    std::cout << "best fitness: " << best_individual.get_fitness();

    return 0;
}
