#include <iostream>
#include <climits>
#include <vector>
#include <math.h>
using namespace std;

// ---------------------------- METHOD 1 ---------------------
long long catalan(int n){
    if(n<0){
        return -1;
    }

    else if(n<=1){
        return 1;
    }

    long long res = 0;

    for (int i = 0; i < n; i++){
        res += catalan(i) * catalan(n - i - 1);
    }

    return res;
}

// Time Complexity: O(exponential)
// Auxiliary space: O(n)

// ------------------------------- METHOD 2 -------------------------------

unsigned long int binomialCoeff(unsigned long int n, unsigned long int k){
    if(k > n-k){
        k = n - k;
    }

    unsigned long int res = 1;

    for (unsigned long int i = 0; i < k; i++){
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

unsigned long int catalan(unsigned long int n){
    unsigned long int c = binomialCoeff(2*n, n);
    return c / (n + 1);
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    cout << catalan(6) << endl;
    cout << catalan(8) << endl;
}