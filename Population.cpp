#include "Population.h"

void Population::generate_individuals(int no_individuals, const Graph &graph) {
    for (int i = 0; i < no_individuals; i++) {
        Individual individual(graph);
        population_vector_.push_back(individual);
    }
}

Population::Population(int no_individuals, const Graph &graph) {
    generate_individuals(no_individuals, graph);
}

std::ostream &operator<<(std::ostream &os, const Population &population) {
    for (const Individual &individual : population.population_vector_) {
        os << individual << "\n";
    }

    return os;
}

