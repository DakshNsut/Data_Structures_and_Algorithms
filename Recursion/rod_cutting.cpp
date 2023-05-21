#include <iostream>
#include <climits>
using namespace std;

// Rod Cutting Problem
// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the
// maximum value obtainable by cutting up the rod and selling the pieces.

// ------------ Using Recursion ------------
int rod_cutting(int price[], int n){
    // Base Case:
    // if length of rod = 0
    if(n <= 0) return 0;

    int max_val = INT_MIN;

    // Checking if rod can be cut at different lengths
    for(int i=0; i<n; i++){
        max_val = max(max_val, price[i] + rod_cutting(price, n-i-1));
    }

    return max_val;
}

// Time Complexity: O(n^n)
// Auxiliary space: O(n)

int main(){
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price)/sizeof(price[0]);
    cout << rod_cutting(price, n) << endl;
}