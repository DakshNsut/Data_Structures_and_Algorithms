#include <stdio.h>

// ---------- Fibonacci Recursively ----------

int fib_recursive(int num){
    if (num ==1){
        return 0;
    }
    if (num ==2){
        return 1;
    }
    else{
        return fib_recursive(num-1) + fib_recursive(num-2);
    }
}

int main(){
    int n;
    printf("Enter the sequence position of the series: ");
    scanf("%d",&n);
    printf("%d",fib_recursive(n));
}

// Time Complexity: O(2^n)
// Auxiliary space: O(n)

// -------- Fibonacci Iteratively --------

int fib_iterative(int num){
    if (num==1){
        return 0;
    }
    if (num ==2){
        return 1;
    }
    else{
        int a = 0;
        int b = 1;
        for (int i = 1; i<num; i++){
            a = b-a;
            b = a+b;
        }
        return a;
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int n;
    printf("Enter the sequence position of the series: ");
    scanf("%d",&n);
    printf("%d",fib_iterative(n));
}