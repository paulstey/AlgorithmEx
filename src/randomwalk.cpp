// Random Walk
// Compute probability of particle returning to origin in N dimensions
// Author: Paul Stey
// Date: 2017-03-25
// CXXFLAGS: -std=c++11 -Wall

#include <iostream>
#include <vector>
#include <random>


bool at_origin(std::vector<int> coords, int dim) {
    bool res = true;

    for (size_t i = 0; i < dim; i++) {
        if (coords[i] != 0) {
            res = false;
            break;
        }
    }
    return res;
}


double rand_unif(std::default_random_engine& generator) {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double number = distribution(generator);
    return number;
}


int random_walk(int nstep, int dim, std::default_random_engine& generator) {
    std::vector<int> coords {0, 0, 0};
    bool res = 0;
    int step;

    for (size_t i = 0; i < nstep; i++) {
        for (size_t j = 0; j < dim; j++) {
            step = rand_unif(generator) < 0.5 ? -1 : 1;
            coords[j] += step;
        }
        if (at_origin(coords, dim)) {
            res = 1;
            break;
        }
    }
    return res;
}


double simulate(int nsim, int nstep, int dim) {
    int origin_visits = 0;
    std::random_device rd;
    std::default_random_engine generator(rd());
    
    for (size_t i = 0; i < nsim; i++) {
        origin_visits += random_walk(nstep, dim, generator);
    }

    double res = origin_visits/static_cast<double>(nsim);
    return res;
}


int get_input(std::string request_string) {
    int res;
    std::cout << request_string;
    std::cin >> res;
    return res;
}


int main() {
    int nsim, nstep, dim;

    nsim = get_input("Enter number of simulations: ");
    nstep = get_input("Enter number of steps: ");
    dim = get_input("Enter dimensions: ");

    double pr = simulate(nsim, nstep, dim);
    std::cout << "Pr(return to origin) = " << pr << std::endl;
}
