#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {4,1,11,-8,0,10};
    // int arr[]={1,2,3,4,5,6};
    int size = 6; 
    int IsSorted = 0;

    for (int j = 1; j < size; j++) // j is the pass number and k is the number of  comparisons
    {
        IsSorted = 1;
        for (int i = 0; i < size-j; i++) // i is the various comparison indices to be compared
        {
            if(arr[i] > arr[i+1]){
                // swapping
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                IsSorted = 0;
            }
        }

        if (IsSorted)
        {
            printf("Already sorted array for %d pass... Algo is Adaptive\n",j);
            break;
        }   
    }

    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

// Time Complexity: O(n^2), n is the total number of pages
// Auxiliary space: O(1)