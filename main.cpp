#include <iostream>
#include "Graph.h"
#include "Population.h"

int main() {
    std::string file_name = "facebook_combined.txt", graph_type = "undirected";
    int no_individuals = 100;
    double mutation_probability = 0.02;
    int no_generations = 100;

    Graph graph(file_name, graph_type);

    Population population(no_individuals, graph, mutation_probability);

    std::cout << "initial fitness of the population: " << population.calculate_population_fitness() << "\n";

    for (int i = 0; i < no_generations; i++) {
        std::vector<double> cumulative_ascending_probabilities;
        std::vector<double> individuals_probabilities;

        population.calculate_individuals_probabilities(individuals_probabilities);
        population.calculate_cumulative_ascending_probabilities(individuals_probabilities,
                                                                cumulative_ascending_probabilities);

        population.generate_offsprings(cumulative_ascending_probabilities);
        population.generate_next_generation(cumulative_ascending_probabilities);

        std::cout << "population fitness on iteration " << (i + 1) << ": " << population.calculate_population_fitness()
                  << "\n";
    }

    return 0;
}
