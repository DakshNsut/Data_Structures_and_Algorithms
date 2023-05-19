#include <stdio.h>

// Prints element of odd occurence, with only one such element
void printTwoOdd(int arr[], int arr_size){
    int res=0;
    for (int i = 0; i < arr_size; i++){
        res=res^arr[i];
    }
    if (res){
        printf("%d",res);
    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

int main(){
    int arr[] = {4, 2, 4, 5, 2, 3, 3, 3, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printTwoOdd(arr, arr_size);
    return 0;
}