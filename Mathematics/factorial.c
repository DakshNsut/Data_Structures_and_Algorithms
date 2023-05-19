#include <stdio.h>

int IterativeFact(int n){
    int FactorialCalculated = 1;
    for (int i = n; i >= 1; i--){
        FactorialCalculated *= i;
    }
    return FactorialCalculated;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int RecursiveFact(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return n * RecursiveFact(n-1);
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    int number;
    printf("Enter the number you want factorial of: ");
    scanf("%d", &number);
    printf("The factorial of the inputted number is: %d\n", IterativeFact(number));
    printf("The factorial of the inputted number is: %d", RecursiveFact(number));
}