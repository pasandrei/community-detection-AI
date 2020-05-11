#ifndef COMMUNITY_DETECTION_AI_INDIVIDUAL_H
#define COMMUNITY_DETECTION_AI_INDIVIDUAL_H

#include <vector>
#include <random>
#include <cstdlib>
#include <queue>
#include "Graph.h"
#include "Evaluator.h"

class Individual {
private:
    std::vector<int> chosen_neighbour_vector_;

    std::string graph_type_;

    double fitness_;

    void generate_neighbour_vector(const Graph &Graph);

    std::vector<int> breadth_first_search(int node, const Graph &graph, std::vector<bool> &visited_nodes);


public:
    Individual();

    Individual(const Graph &graph, const Evaluator &evaluator);

    Individual(const Individual &individual1, const Individual &individual2, const Evaluator &evaluator);

    friend std::ostream &operator<<(std::ostream &os, const Individual &individual); // cout << individual;

    int size() const;

    int operator[](int index) const; // Overload the access operator

    void mutate(const Graph &graph, double mutation_probability);

    bool operator<(const Individual &other_individual) const;

    double get_fitness() const;

    const std::vector<int> &get_chosen_neighbour_vector() const;

    bool operator!=(const Individual &other_individual) const;

    void create_graph(Graph &graph);

    const std::string &get_graph_type() const;

    std::vector<std::vector<int>> get_clusters();

};

#endif
