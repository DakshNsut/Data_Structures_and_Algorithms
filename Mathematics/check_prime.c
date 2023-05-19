#include <stdio.h>

int isPrime(int n){
    static int i = 2;

    // corner cases
    if (n == 0 || n == 1) {
        return 0;
    }

    // Checking Prime
    if (n == i)
        return 1;

    // base cases
    if (n % i == 0) {
        return 0;
    }
    i++;
    return isPrime(n);
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// Driver Code
int main()
{
    printf("%d", isPrime(7));
    return 0;
}