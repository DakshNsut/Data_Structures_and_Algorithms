#include <stdio.h>

int main(){
    int arr[] = {1,6,3,2,9,4};
    int size = 6;

    for (int j = 0; j < size; j++){
        int min_index=j;
        for (int i = j+1; i < size; i++){
            if (arr[min_index]>arr[i]){
                min_index=i;
            }
        }

        int temp = arr[j];
        arr[j] = arr[min_index];
        arr[min_index] = temp;
    }

    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(1)