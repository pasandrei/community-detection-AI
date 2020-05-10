#ifndef COMMUNITY_DETECTION_AI_POPULATION_H
#define COMMUNITY_DETECTION_AI_POPULATION_H

#include <vector>
#include <random>
#include "Graph.h"
#include "Individual.h"

class Population {
private:
    std::vector<Individual> population_vector_;

    Graph graph_;

    double mutation_probability_;

    void generate_individuals(int no_individuals, const Graph &graph);

public:
    Population(int no_individuals, const Graph &graph, double mutation_probability);

    friend std::ostream &operator<<(std::ostream &os, const Population &population); // cout << population;

    const Individual &operator[](int index) const; // Overload the access operator

    Individual generate_individual();

    void calculate_individuals_probabilities(std::vector<double> &individuals_probabilities);

    double calculate_population_fitness();

    void calculate_cumulative_ascending_probabilities(const std::vector<double> &individuals_probabilities, std::vector<double> &cumulative_ascending_probabilities);

    void generate_offsprings();

    void generate_next_generation();
};

#endif
