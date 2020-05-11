#ifndef COMMUNITY_DETECTION_AI_INDIVIDUAL_H
#define COMMUNITY_DETECTION_AI_INDIVIDUAL_H

#include <vector>
#include <random>
#include <cstdlib>
#include "Graph.h"

class Individual {
private:
    std::vector<int> chosen_neighbour_vector_;

    double fitness_ = ((double) rand() / (RAND_MAX));

    void generate_neighbour_vector(const Graph &Graph);

public:
    explicit Individual(const Graph &graph);

    Individual(const Individual &individual1, const Individual &individual2);

    friend std::ostream &operator<<(std::ostream &os, const Individual &individual); // cout << individual;

    int size() const;

    int operator[](int index) const; // Overload the access operator

    void mutate(const Graph &graph, double mutation_probability);

    bool operator<(const Individual &other_individual) const;

    double get_fitness() const;

    const std::vector<int> &get_chosen_neighbour_vector() const;

    bool operator!=(const Individual &other_individual) const;
};

#endif
