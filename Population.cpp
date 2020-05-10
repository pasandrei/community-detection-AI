#include "Population.h"

void Population::generate_individuals(int no_individuals, const Graph &graph) {
    for (int i = 0; i < no_individuals; i++) {
        Individual individual(graph);
        population_vector_.push_back(individual);
    }
}

Population::Population(int no_individuals, const Graph &graph, double mutation_probability) {
    graph_ = graph;
    mutation_probability_ = mutation_probability;

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

Individual Population::generate_individual() {
    /* This method is used to create a parent for the next generation of offsprings
     *  or an individual for the next generation using the wheel algorithm
     *  which operates with the partial sums of the probabilities
     *  of the individuals from the populations
     */

    std::vector<double> individuals_probabilities;
    std::vector<double> cumulative_ascending_probabilities;

    calculate_individuals_probabilities(individuals_probabilities);
    calculate_cumulative_ascending_probabilities(individuals_probabilities, cumulative_ascending_probabilities);

    double random_probability = ((double) rand() / (RAND_MAX));

    if (random_probability < cumulative_ascending_probabilities[0]) {
        return population_vector_[0];
    }

    // FUTURE NOTE: change with binary search
    for (int i = 1; i < cumulative_ascending_probabilities.size(); i++) {
        if (random_probability >= cumulative_ascending_probabilities[i - 1]
            && random_probability < cumulative_ascending_probabilities[i]) {
            return population_vector_[i];
        }
    }
}

void Population::calculate_individuals_probabilities(std::vector<double> &individuals_probabilities) {
    // This method calculates the probability of each individual to be selected as a parent for the next generation

    double population_fitness = calculate_population_fitness();

    for (Individual individual : population_vector_) {
        double individual_probability = individual.get_fitness()/population_fitness;

        individuals_probabilities.push_back(individual_probability);
    }
}

double Population::calculate_population_fitness() {
    // This method sums and returns the fitness values of the individuals from the population

    double sum = 0;

    for (Individual individual : population_vector_) {
        sum += individual.get_fitness();
    }

    return sum;
}

void Population::calculate_cumulative_ascending_probabilities(const std::vector<double> &individuals_probabilities, std::vector<double> &cumulative_ascending_probabilities) {
    /* This method is used to calculate the cumulative ascending probabilities corresponding to the fitness
     * values of each individual from the population
     */

    double cumulative_ascending_probability = 0;

    for (double individual_probability : individuals_probabilities) {
        cumulative_ascending_probability += individual_probability;

        cumulative_ascending_probabilities.push_back(cumulative_ascending_probability);
    }
}

void Population::generate_offsprings() {
    /* Ths method creates a number of offsprings equal to the number of
     * individuals in the population, apply mutation on each on them with
     * a given probability and and the resulting offspring to the population_vector_
     */
    std::vector<Individual> offsprings;

    for (int i = 0; i < population_vector_.size(); i++) {
        Individual parent1 = generate_individual();
        Individual parent2 = generate_individual();

        Individual offspring(parent1, parent2);

        offspring.mutate(graph_, mutation_probability_);

        offsprings.push_back(offspring);
    }

    for (Individual offspring : offsprings) {
        population_vector_.push_back(offspring);
    }
}

void Population::generate_next_generation() {
    /*
     * This method selects the next generation of individuals using the wheel
     * algorithm for proportionate selection implemented inside the
     * generate_individual() method
     */
    std::vector<Individual> next_generation;

    for (int i = 0; i < population_vector_.size()/2; i++) {
        Individual individual = generate_individual();

        next_generation.push_back(individual);
    }

    population_vector_ = next_generation;
}



