// Solve Fractional Knapsack Problem
// Date: May 17, 2016
// Author: Paul Stey
// Description:
//   Given a set of items and total capacity of a knapsack, find the maximal value 
//   of fractions of items that that fit into the knapsack.
// Inputs:
//   The  first line of the input contains the number n of items and the capacity
//   W of a knapsack. The next n lines de ne the values and weights of the items.  
//   The i-th line contain integers v_i and w_i, which are the value and the weight 
//   of the i-th item, respectively.
// Sample Input:
//   3 50
//   60 20
//   100 50
//   120 30
// Output:
//   180.000

#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

int maxindx(vector<double> x) {
    int n, i, idx;
    n = x.size();
    double maxval = 0.0;

    for (i = 0; i < n; i++) {
        if (x[i] > maxval) {
            idx = i;
            maxval = x[i];
        }   
    }
    return idx;
}

bool allgone(vector<int> x) {
    int n, i;
    n = x.size();
    bool chk = true;
    for (i = 0; i < n; i++) {
        if (x[i] > 0) {
            chk = false;
            break;
        }
    }
    return chk;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
    vector<double> perunit(n);
    double value = 0.0;
    int i;
    
    for (i = 0; i < n; i++) {
        perunit[i] = (double)values[i]/weights[i];
    }

    int indx;
    double take, frac;

    while (capacity > 0 && !allgone(values)) {
        indx = maxindx(perunit);
        // std::cout << capacity << std::endl;
        
        if (capacity >= weights[indx]) {
            // std::cout << "adding " << values[indx] << std::endl;

            capacity -= weights[indx];
            value += values[indx];
            perunit[indx] = 0.0;             // zero out to avoid revisting this index 
            values[indx] = 0;
        }

        else if (capacity <= weights[indx]) {

            frac = (double)capacity/weights[indx];
            capacity -= frac*weights[indx];
            value += frac*values[indx];
            perunit[indx] = 0;             // zero out to avoid revisting this index
        }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;             // first line is num of items and max capacity
    vector<int> values(n);
    vector<int> weights(n);
    int i;
    for (i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values, n);

    std::cout << std::setprecision(3) << std::fixed << optimal_value << std::endl;
    return 0;
}
