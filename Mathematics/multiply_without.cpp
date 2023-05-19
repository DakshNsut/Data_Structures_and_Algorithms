#include <iostream>
using namespace std;

// multiply two numbers without using *, /, %, bitwise operators, loops

// ---------------- Method 1 ----------------
int multiply(int a, int b){

    if(b == 0 || a == 0){
        return 0;
    }

    if(b>0){
        return a + multiply(a, b-1);
    }

    else{
        return -multiply(a, -b);
    }
}

// Time Complexity: O(b)
// Auxiliary space: O(b)

// --------------- Method 2 (can use bitwise and loops) ---------------------
int multiply(int a, int b){
    int sign = 1;
    if(b<0){
        sign = -1;
        b = -b;
    }
    // RUSSIAN PEASANT ALGORITHM
    int product = 0;
    while(b>0){
        if(b & 1){
            product += a;
        }

        a <<= 1; // a = 2a
        b >>= 1; // b = b/2
    }

    return sign == -1 ? -product : product;
}

// Time Complexity: O(log(b))
// Auxiliary space: O(1)

int main(){
    cout << multiply(9,3);
    return 0;
}