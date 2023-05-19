#include <stdio.h>

int partition(int arr[], int low, int high){
    int i = low;
    int j = high;
    int pivot = low;
    while (i<j){
        while (arr[i] <= arr[pivot]){
            i++;
        }

        // When 'pivot' == high == 'j', then this condition won't be true
        // so 'j' == high only at the last and, j== high would only be returned everytime, this would make the function go in a forever loop
        while(arr[j]>arr[pivot]){
            j--;
        }

        if (i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // if j<=i
    int temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    
    return j; // because at last pivot will be at high
}

void quicksort(int *arr, int low, int high)
{
    int index_pivot; // index of pivot after partitioning
    if (low < high) // then only the array will have more than one elements
    {
        index_pivot = partition(arr, low, high);
        quicksort(arr, low, index_pivot - 1);  // sorting left side array
        quicksort(arr, index_pivot + 1, high); // sorting right side array
        // we are leaving pivot as it will be sorted automatically, by our condition of choice of pivot
    }
}

// Time Complexity: O(n*log(n))
// Auxiliary space: O(1)

int main(){
    int Arr[] = {3, 6, 1};
    int size = 3;
    printf("Sorted array is:\n");
    quicksort(Arr, 0, size - 1);
    for (int i = 0; i < size; i++){
        printf("%d ", Arr[i]);
    }
    return 0;
}