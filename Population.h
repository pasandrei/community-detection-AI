#ifndef COMMUNITY_DETECTION_AI_POPULATION_H
#define COMMUNITY_DETECTION_AI_POPULATION_H

#include <vector>
#include <random>
#include<algorithm>
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

    int select_parent();

    void generate_offsprings();

    void generate_next_generation();
};

#endif
