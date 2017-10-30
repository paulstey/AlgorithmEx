// Sieve of Eratosthenes
// Prime sieve for quickly obtaining
// prime numbers less than some value n;
// Author: Paul Stey
// Date: 2017-03-14
// CXXFLAGS: -Wall -O3 -std=c++11 

#include <iostream>
#include <vector>

std::vector<int> get_nums(int n) {
    std::vector<int> nums(n+1);
    for (int i = 0; i <= n; i++) {
    	nums[i] = i;
    }
    return nums;
}


std::vector<int> primes(int n) {
    std::vector<bool> prime_flag (n+1, true);
    int i, j;

    // Cross out non-primes by removing all multiples
    // of our existing primes. The incrementing of the
    // loop index `j` in the nested loop is the key.
    for (i = 2; i*i <= n; i++) {
    	if (prime_flag[i] == true) {
            for (j = i*2; j <= n; j += i) {
                prime_flag[j] = false;
            }
        }
    }

    // collect the non-crossed out integers (i.e., primes)
    std::vector<int> res;
    for (i = 2; i <= n; i++) {
    	if (prime_flag[i] == true) {
    	    res.push_back(i);
    	}
    }

    return res;
}

int get_input() {
    int n;
    std::cout << "Enter maximum number to check for primality: ";
    std::cin >> n;
    std::cout << "Okay. Checking up to " << n;
    return n;
}


int main() {
    int n = get_input();
    std::vector<int> prime_vec;
    prime_vec = primes(n);

    int nprimes = prime_vec.size();

    for (auto p : prime_vec) {
    	std::cout << p << std::endl;
    }
    std::cout << "Found " << nprimes << " primes less than " << n << std::endl;
}
