#ifndef COMMUNITY_DETECTION_AI_EVALUATOR_H
#define COMMUNITY_DETECTION_AI_EVALUATOR_H

#include "Graph.h"

class Evaluator {
private:
    Graph graph_;

public:
    explicit Evaluator(const Graph &graph);

    double evaluate(const std::vector<std::vector<int>> &clusters) const;

    double operator()(const std::vector<std::vector<int>> &clusters) const; // Objects can be used as functions
};

#endif //COMMUNITY_DETECTION_AI_EVALUATOR_H
