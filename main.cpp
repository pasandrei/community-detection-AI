#include <iostream>
#include "Graph.h"
#include "Population.h"

int main() {
    std::string file_name = "facebook_combined.txt", graph_type = "undirected";
    int no_individuals = 1000;
    double mutation_probability = 0.05;
    int no_generations = 1000;

    Graph graph(file_name, graph_type);

    Evaluator evaluator(graph);

    Population population(no_individuals, graph, mutation_probability, evaluator);

    for (int i = 0; i < no_generations; i++) {
        population.generate_offsprings();
        population.generate_next_generation();

        std::cout << "current best fitness: " << population[0].get_fitness() << "\n";
    }

    Individual best_individual = population[0];

    std::cout << "best fitness: " << best_individual.get_fitness();

    return 0;
}
