#include <iostream>
#include "Graph.h"
#include "Population.h"
#include "KMeans.h"

void evolutionary_algorithm(std::ifstream &config_file, Graph &graph, Evaluator &evaluator) {
    int no_individuals, no_generations;
    double mutation_probability;

    config_file >> no_individuals >> mutation_probability >> no_generations;

    Population population(no_individuals, graph, mutation_probability, evaluator);

    for (int i = 0; i < no_generations; i++) {
        population.generate_offsprings();
        population.generate_next_generation();

        std::cout << "current best fitness: " << population[0].get_fitness() << "\n";
    }

    Individual best_individual = population[0];

    std::cout << "best fitness: " << best_individual.get_fitness();
}

void KMeans_algorithm(std::ifstream &config_file, Graph &graph, Evaluator &evaluator) {
    int no_tests, no_clusters, no_generations;

    config_file >> no_tests >> no_clusters >> no_generations;

    for (int _ = 0; _ < no_tests; ++_) {
        std::cout << "TEST " << _ << "\n\n";
        KMeans k_means(graph, no_clusters);

        std::cout << evaluator(k_means.get_clusters()) << '\n';

        for (int iter = 0; iter < no_generations; ++iter) {
            k_means.step();

            std::cout << evaluator(k_means.get_clusters()) << '\n';
        }
    }
}

int main() {
    std::string config_path;

    std::cout << "Which config file do you want to use?\n";
    std::cin >> config_path;

    std::ifstream config_file(config_path);

    std::string algorithm_type, graph_type, graph_file_path;
    config_file >> algorithm_type >> graph_file_path >> graph_type;

    Graph graph(graph_file_path, graph_type);
    Evaluator evaluator(graph);

    if (algorithm_type == "evolutionary") {
        evolutionary_algorithm(config_file, graph, evaluator);
    } else {
        KMeans_algorithm(config_file, graph, evaluator);
    }

    return 0;
}
