#include <vector>
#include "Individual.h"

// locus based representation is used for an individual
void Individual::generate_neighbour_vector(const Graph &graph) {
    int no_nodes = graph.size();

    chosen_neighbour_vector_.resize(no_nodes);

    for (int i = 0; i < no_nodes; i++) {
        const std::vector<int> &current_node_neighbours = graph[i];
        int no_neighbours = current_node_neighbours.size();

        if (no_neighbours > 0) {
            int random_neighbour_index = rand() % no_neighbours;

            chosen_neighbour_vector_[i] = current_node_neighbours[random_neighbour_index];
        } else {
            chosen_neighbour_vector_[i] = i;
        }
    }
}

Individual::Individual(const Graph &graph) {
    generate_neighbour_vector(graph);
}

std::ostream &operator<<(std::ostream &os, const Individual &individual) {
    for (int i : individual.chosen_neighbour_vector_) {
        os << i << " ";
    }
    os << "\n";

    return os;
}
