#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Finding the largest element in the array of natural number

int ReturnMax(int arr[], int n)
{
    int LargerNum = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>LargerNum){
            LargerNum = arr[i];
        }
    }
    return LargerNum;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main()
{
    int LargestNum;
    int ARR[] = {10,2,3,6,2,56,6,32};
    int n = sizeof(ARR)/sizeof(ARR[0]);
    LargestNum = ReturnMax(ARR, n);
    printf("The largest number is: %d",LargestNum);
}