#ifndef COMMUNITY_DETECTION_AI_INDIVIDUAL_H
#define COMMUNITY_DETECTION_AI_INDIVIDUAL_H

#include <vector>
#include <cstdlib>
#include "Graph.h"

class Individual {
private:
    std::vector<int> chosen_neighbour_vector_;

    void generate_neighbour_vector(const Graph &Graph);

public:
    explicit Individual(const Graph &graph);

    friend std::ostream &operator<<(std::ostream &os, const Individual &individual); // cout << individual;
};

#endif