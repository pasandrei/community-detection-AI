#include "Population.h"

void Population::generate_individuals(int no_individuals, const std::vector<std::vector<int>> &adjacency_list) {
    for (int i = 0; i < no_individuals; i++) {
        Individual individual(adjacency_list);
        population_vector_.push_back(individual);
    }
}

Population::Population(int no_individuals, const Graph &graph) {
    const std::vector<std::vector<int>> &adjacency_list = graph.get_adjacency_list();

    generate_individuals(no_individuals, adjacency_list);
}

std::ostream &operator<<(std::ostream &os, const Population &population) {
    for (const Individual &individual : population.population_vector_) {
        os << "individual: " << "\n";
        os << individual << "\n";
    }

    return os;
}

