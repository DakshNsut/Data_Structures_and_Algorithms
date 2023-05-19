#include <iostream>
#include <climits>
#include <vector>
#include <math.h>
using namespace std;

// -------------------- Count number from 1 to N divisible by either a or b --------------------
int countDivisors(int n, int a, int b){
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);

    return c1+c2-c3;
}

// Time Complexity: O(1)
// Auxiliary space: O(1)

int main(){
    cout << countDivisors(10, 2, 5);
}