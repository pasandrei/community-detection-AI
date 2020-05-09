#include <vector>
#include "Individual.h"

void Individual::generate_communities_division(const std::vector<std::vector<int>> &adjacency_list) {
    int no_nodes = adjacency_list.size();

    communities_division_.resize(no_nodes);

    for (int i = 0; i < no_nodes; i++) {
        std::vector<int> current_node_neighbours = adjacency_list[i];
        int no_neighbours = current_node_neighbours.size();

        if (no_neighbours > 0) {
            int random_neighbour_index = rand() % no_neighbours;
            int random_neighbour = current_node_neighbours[random_neighbour_index];

            communities_division_[i] = random_neighbour;
        } else {
            communities_division_[i] = i;
        }
    }
}

Individual::Individual(const std::vector<std::vector<int>> &adjacency_list) {
    generate_communities_division(adjacency_list);
}

std::ostream &operator<<(std::ostream &os, const Individual &individual) {
    for (int i : individual.communities_division_) {
        os << i << " ";
    }
    os << "\n";

    return os;
}
