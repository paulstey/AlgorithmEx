// square_root.cpp
// Calculate the square root of a number using Newton's method.
// Author: Paul Stey
// Date: 2016-08-01
// CXXFLAGS: -Wall -Wpedantic

#include <iostream>
#include <cstdlib>

double square_root(double s, double thresh) {
    double x_n = s;
    double diff = 999999.9;
    double x_tmp;

    while (diff > thresh) {
        x_tmp = (1.0/2.0) * (x_n + (s/x_n));
        diff = x_n - x_tmp;
        std::cout << x_tmp << std::endl;
        x_n = x_tmp;
    }
    return x_n;
}


int main(int argc, char* argv[]) {
    double s = atof(argv[1]);

    double res = square_root(s, 0.0001);
    std::cout << res << std::endl;
}
