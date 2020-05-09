#ifndef COMMUNITY_DETECTION_AI_POPULATION_H
#define COMMUNITY_DETECTION_AI_POPULATION_H

#include <vector>
#include "Graph.h"
#include "Individual.h"

class Population {
private:
    std::vector<Individual> population_vector_;

    void generate_individuals(int no_individuals, const Graph &graph);

public:
    Population(int no_individuals, const Graph &graph);

    friend std::ostream &operator<<(std::ostream &os, const Population &population); // cout << population;
};

#endif
