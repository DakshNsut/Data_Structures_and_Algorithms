#include <stdio.h>

int main()
{
    long long int val =1;
    int B, A;
    printf("Enter the base number: ");
    scanf("%d", &A);
    printf("Enter the exponentiation: ");
    scanf("%d", &B);
    // val = A;  // if we want this statement then dont put val =1 and put i<B instead of i<=B.
    for (int i = 1; i <= B; i++) // if val = A not used then i=1 means power 1 then i=2 means squared ... //if val = A used then i=1 means squared then i=2 means cube power and so on...
    {
        val *= A;
    }
    printf("The calculation for %d to the power of %d is: %lld.", A, B, val);
}

// Time Complexity: O(B)
// Auxiliary space: O(1)