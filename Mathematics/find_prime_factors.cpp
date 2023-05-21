#include <iostream>
using namespace std;

// ------------------ Method -1 ----------------------
void findPrimeFactors(int n){
    int c=2;
    while(n > 1){
        if(n % c == 0){
            cout << c << " ";
            n /= c;
        }
        else{
            c++;
        }
    }
}

// Time Complexity: O(n) - worst case when n is prime number
// Auxiliary space: O(1)

// ------------------ Method -2 ----------------------
void findPrimeFactors(int n){
    // Checking if n has prime factor 2
    while(n%2 == 0){
        cout << 2 << " ";
        n /= 2;
    }

    // Checking if n has prime factor > 2
    // Checking till root(n) only because for any number no prime factors can be found after root(n),
    // except prime numbers
    for(int i=3; i*i<=n; i += 2){
        while(n%i == 0){
            cout << i << " ";
            n /= i;
        }
    }

    // When n is a prime number
    if(n > 2){
        cout << n << " ";
    }
}

// Time Complexity: O(root(n))
// Auxiliary space: O(1)

int main(){
    findPrimeFactors(80);
}