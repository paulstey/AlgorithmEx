// Generate Length of Pisano Period for a Given Modulo
// Date: May 15, 2016
// CXXFLAGS: -Wall -std=c++11
// Author: Paul Stey (translation of Jared Forsyth's Python code)

#include <iostream>
#include <vector>

int len_period(int mod) {
    int first, second, a, b, tmp;
    int gotfirst, count;
    first = second = a = b = 1;
    gotfirst = count = 0;
    while (count < 100000000) {
        tmp = (a + b) % mod;
        a = b;
        b = tmp;
        if (gotfirst == 1) {
            if (a == second) {
                break;
            }
            gotfirst = 0;
        }
        else if (a == first) {
            gotfirst = 1;
        }
        count = count + 1;
    }
    return count;
}

int main() {
    int m;
    std::cout << "Enter the modulo for which you want the lenght of its Pisano period: " << std::endl;
    std::cin >> m;
    std::cout << len_period(m) << '\n';
}
