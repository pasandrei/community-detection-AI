#include "Population.h"

void Population::generate_individuals(int no_individuals, const Graph &graph) {
    for (int i = 0; i < no_individuals; i++) {
        Individual individual(graph, evaluator_);
        population_vector_.push_back(individual);
    }
}

Population::Population(int no_individuals, const Graph &graph, double mutation_probability,
                       const Evaluator &evaluator) {
    graph_ = graph;
    mutation_probability_ = mutation_probability;
    evaluator_ = evaluator;

    generate_individuals(no_individuals, graph);
}

std::ostream &operator<<(std::ostream &os, const Population &population) {
    for (const Individual &individual : population.population_vector_) {
        os << individual << "\n";
    }

    return os;
}

const Individual &Population::operator[](int index) const {
    return population_vector_[index];
}

int Population::select_parent() {
    /* This method is used to randomly select a individual from the population
     * to become a parent for the next generation
     */

    return rand() % population_vector_.size();
}

void Population::generate_offsprings() {
    /* Ths method creates a number of offsprings equal to the number of
     * individuals in the population, apply mutation on each on them with
     * a given probability and add the resulting offsprings to the population_vector_
     */

    std::vector<Individual> offsprings;

    std::sort(population_vector_.begin(), population_vector_.end());

    for (int i = 0; i < population_vector_.size(); i++) {
        int parent1_index = select_parent();
        int parent2_index = select_parent();

        while (parent1_index == parent2_index) {
            parent1_index = select_parent();
            parent2_index = select_parent();
        }

        Individual parent1 = population_vector_[parent1_index];
        Individual parent2 = population_vector_[parent2_index];

        Individual offspring(parent1, parent2, evaluator_);

        offspring.mutate(graph_, mutation_probability_);

        offsprings.push_back(offspring);
    }

    for (Individual &offspring : offsprings) {
        population_vector_.push_back(offspring);
    }
}

void Population::generate_next_generation() {
    /*
     * This method selects for the next generation the first n best individuals, where
     * n is the initial number of individuals from population
     */

    std::vector<Individual> next_generation;

    std::sort(population_vector_.begin(), population_vector_.end());

    std::reverse(population_vector_.begin(), population_vector_.end());

    for (int i = 0; i < population_vector_.size() / 2; i++) {
        next_generation.push_back(population_vector_[i]);
    }

    population_vector_ = next_generation;
}