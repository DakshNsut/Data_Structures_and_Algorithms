#include <stdio.h>
#include <limits.h>

void CountSort(int A[], int size){
    // Finding maximum element
    int max = INT_MIN;

    // INT_MIN specifies that an integer variable cannot store any value below this limit.
    // INT_MIN is a macro which represents the minimum integer value
    // These macros are defined in the header file <limits. h> , so you must include it.
    // Values of INT_MAX and INT_MIN may vary from compiler to compiler.
    // Value of INT_MIN = -2147483647 to 1
    // Value of INT_MAX = 2147483647

    for (int i = 0; i < size; i++){
        if (A[i] > max){
            max = A[i];
        }
    }


    int count[max + 1];
    // Initializing all elements of count array to be 0
    for (int i = 0; i < max + 1; i++){
        count[i] = 0;
    }

    // Traversing all elements of input array and creating count array
    // i is traversing input array
    for (int i = 0; i < size && A[i] < max + 1; i++){
        count[A[i]]++;
    }

    // Traversing all elements of count array and replacing elements in input array
    // i is traversing count array and j is traversing input array
    for (int i = 0, j = 0; i < max + 1;){
        if (count[i] == 0){
            i++;
        }

        else{
            count[i]--;
            A[j] = i;
            j++;
        }
    }
}

// Time Complexity: O(N + K) where N is the number of elements in the input array and K is the range of input.
// Auxiliary Space: O(N + K)

int main(){
    int Arr[] = {3,1,9,7,1,2,4};
    int size = 7;
    CountSort(Arr,size);

    // Printing the array
    for (int i = 0; i < size; i++){
        printf("%d ",Arr[i]);
    }
}