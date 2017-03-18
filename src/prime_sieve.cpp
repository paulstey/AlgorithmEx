// Sieve of Eratosthenes
// Prime sieve for quickly obtaining
// prime numbers less than some value n;
// Author: Paul Stey
// Date: 2017-03-14

#include<iostream>
#include<vector>

std::vector<int> get_nums(int n) {
    std::vector<int> nums(n+1);
    for (int i = 0; i <= n; i++) {
    	nums[i] = i;
    }
    return nums;
}


std::vector<int> primes(int n) {
    std::vector<int> nums = get_nums(n);
    int i;

    // cross out non-primes
    for (i = 2; i <= n; i++) {
    	if (nums[i] != -1) {
    	    int j = i+1;

    	    while (j <= n) {
                if (nums[j] != -1) {
                    if (nums[j]%nums[i] == 0) {
                        nums[j] = -1;
                    }
                }
                j++;
    	    }
    	}
    }

    // collect the non-crossed out integers (i.e., primes)
    std::vector<int> res;
    for (i = 2; i <= n; i++) {
    	if (nums[i] != -1) {
    	    res.push_back(nums[i]);
    	}
    }

    return res;
}

int get_input() {
    int n;
    std::cout << "Enter maximum number to check for primality: " << std::endl;
    std::cin >> n;
    std::cout << "Okay. Checking up to " << n << std::endl;
    return n;
}


int main() {
    int n = get_input();
    std::vector<int> prime_vec;
    prime_vec = primes(n);

    int nprimes = prime_vec.size();

    std::cout << "Found " << nprimes << " primes less than " << n << std::endl;

    for (auto p : prime_vec) {
    	std::cout << p << std::endl;
    }
}
