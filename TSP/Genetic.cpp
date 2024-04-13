#include "Genetic.h"
#include <iostream>
#include <random>
#include <map>
using namespace std;
// Constructor
GeneticAlgorithm::GeneticAlgorithm(const DistanceMatrix& matrix, int populationSize, int generations, double mutationRate)
    : matrix(matrix), populationSize(populationSize), generations(generations), mutationRate(mutationRate) {
    initializePopulation();
}

void GeneticAlgorithm::initializePopulation() {
    for (int i = 0; i < populationSize; ++i) {
        population.push_back(createRandomChromosome());
    }
}

vector<int> GeneticAlgorithm::createRandomChromosome() {
    vector<int> chromosome(matrix.size());
    iota(chromosome.begin(), chromosome.end(), 0);  // Fill vector with 0, 1, 2, ..., n-1
    // Ensure that the first city (0) is always starting and not shuffled
    random_shuffle(chromosome.begin() + 1, chromosome.end());  // Only shuffle from the second element
    return chromosome;
}


double GeneticAlgorithm::calculateFitness(const vector<int>& chromosome) {
    double totalDistance = 0.0;
    for (size_t i = 0; i < chromosome.size() - 1; ++i) {
        totalDistance += matrix.getDistance(chromosome[i], chromosome[i + 1]);
    }
    totalDistance += matrix.getDistance(chromosome.back(), chromosome.front());
    return totalDistance;
}

void GeneticAlgorithm::solve() {
    vector<int> bestChromosome;
    double bestFitness = numeric_limits<double>::max();

    cout << "Genetic Algorithm: " << endl;

    for (int generation = 0; generation < generations; ++generation) {
        selection();
        crossover();
        for (auto& chrom : population) {
            mutate(chrom);
        }

        for (const auto& chrom : population) {
            double fitness = calculateFitness(chrom);
            if (fitness < bestFitness) {
                bestFitness = fitness;
                bestChromosome = chrom;
            }
        }
        cout << "the he thu " << generation << ", do dai duong di ngan nhat la : " << bestFitness << endl;
    }

    cout << "Best Path: " << bestChromosome[0] ;
    for (size_t i = 1; i < bestChromosome.size(); ++i) {
        cout << " -> " << bestChromosome[i] ;
    }
    cout << " -> " << bestChromosome[0] << endl;  // Ensure the path is cyclic, ending at the starting city
    cout << "Total Distance: " << bestFitness << endl;
}

void GeneticAlgorithm::selection() {
    vector<vector<int>> newPopulation;
    int tournamentSize = 5;  // Có thể điều chỉnh kích thước này

    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, population.size() - 1);

    for (int i = 0; i < populationSize; ++i) {
        double bestFitness = numeric_limits<double>::max();
        vector<int> bestChromosome;

        for (int j = 0; j < tournamentSize; ++j) {
            int idx = distribution(generator);
            double currentFitness = calculateFitness(population[idx]);
            if (currentFitness < bestFitness) {
                bestFitness = currentFitness;
                bestChromosome = population[idx];
            }
        }

        newPopulation.push_back(bestChromosome);
    }

    population = newPopulation;
}

void GeneticAlgorithm::crossover() {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, populationSize - 1);
    uniform_int_distribution<int> crossoverPoint1(1, matrix.size() / 2);
    uniform_int_distribution<int> crossoverPoint2(matrix.size() / 2 + 1, matrix.size() - 1);

    vector<vector<int>> newPopulation;

    while (newPopulation.size() < populationSize) {
        int parent1Index = distribution(generator);
        int parent2Index = distribution(generator);
        vector<int> parent1 = population[parent1Index];
        vector<int> parent2 = population[parent2Index];
        int cp1 = crossoverPoint1(generator);
        int cp2 = crossoverPoint2(generator);

        vector<int> child1 = parent1;
        vector<int> child2 = parent2;

        // Apply PMX
        map<int, int> mapping1, mapping2;
        for (int i = cp1; i < cp2; i++) {
            child1[i] = parent2[i];
            child2[i] = parent1[i];
            mapping1[parent2[i]] = parent1[i];
            mapping2[parent1[i]] = parent2[i];
        }

        // Correct children to ensure no duplicate cities
        for (int i = 0; i < matrix.size(); i++) {
            if (i < cp1 || i >= cp2) {
                while (mapping1.find(child1[i]) != mapping1.end())
                    child1[i] = mapping1[child1[i]];

                while (mapping2.find(child2[i]) != mapping2.end())
                    child2[i] = mapping2[child2[i]];
            }
        }

        newPopulation.push_back(child1);
        newPopulation.push_back(child2);
    }

    population = newPopulation;
}


void GeneticAlgorithm::mutate(vector<int>& chromosome) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, matrix.size() - 1);
    uniform_real_distribution<double> chance(0.0, 1.0);

    if (chance(generator) < mutationRate) {  // Xác suất đột biến
        int index1 = distribution(generator);
        int index2 = distribution(generator);

        swap(chromosome[index1], chromosome[index2]);
    }
}


vector<int> GeneticAlgorithm::selectParent() {
    // Tính tổng fitness của quần thể để làm mẫu cho roulette wheel
    double totalFitness = 0.0;
    vector<double> fitnesses(population.size());

    for (int i = 0; i < population.size(); ++i) {
        fitnesses[i] = 1.0 / calculateFitness(population[i]);  // Sử dụng nghịch đảo của fitness vì ta cần giá trị thấp hơn là tốt hơn
        totalFitness += fitnesses[i];
    }

    // Tạo roulette wheel
    vector<double> cumulativeFitnesses(population.size());
    cumulativeFitnesses[0] = fitnesses[0];
    for (int i = 1; i < population.size(); ++i) {
        cumulativeFitnesses[i] = cumulativeFitnesses[i - 1] + fitnesses[i];
    }

    // Chọn ngẫu nhiên một số từ 0 đến totalFitness
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, totalFitness);
    double randomValue = dis(gen);

    // Tìm parent dựa trên giá trị ngẫu nhiên
    for (int i = 0; i < population.size(); ++i) {
        if (randomValue <= cumulativeFitnesses[i]) {
            return population[i];
        }
    }

    // Trường hợp bất thường nếu không tìm được phụ huynh (không nên xảy ra)
    return population.back();
}
