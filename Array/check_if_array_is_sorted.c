#include <stdio.h>

// to check if array is sorted

void array_is_sorted1(int* a,int n){
    for (int i = 1; i < n; i++){
        if(a[i-1] > a[i]){
            printf("Array is not sorted.");
            return ;
        }
    }
    printf("Array is sorted.");
    return ;
}

// Time complexity: O(n) 
// Auxiliary Space: O(1)

void array_is_sorted2(int* a, int n){
    if(n==0||n==1){
        printf("Array is sorted.");
        return;
    }

    if (a[n-1] < a[n-2]){
        printf("Array is not sorted.");
        return;
    }
    
    return array_is_sorted2(a,n-1);
}

// Time complexity: O(n) 
// Auxiliary Space: O(n) - recursion call stack

int array_is_sorted3(int* a,int n){
    if (n==0 || n==1){
        return 1;
    }

    return a[n-1] >= a[n-2] && array_is_sorted3(a,n-1);
}

// Time complexity: O(n) 
// Auxiliary Space: O(n) - recursion call stack

int main(){
    int a[] = {1,4,6,7,9,10};
    int n = 6;
    array_is_sorted1(a,n);
    printf("\n");
    array_is_sorted2(a,n);
    printf("\n");
    if(array_is_sorted3(a,n)){
        printf("Array is sorted.");
    }
    else{
        printf("Array is not sorted.");
    }
}