#include <stdio.h>

void printLeaders1(int arr[], int size){
	for (int i = 0; i < size; i++){
		int j;
		for (j = i+1; j < size; j++){
			if (arr[i] <arr[j])
				break;
		}
		if (j == size) // the loop didn't break, it came out of loop due to j<size not 
        // being satisfied and that was when j = size.
			printf("%d ",arr[i]);
    }
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

void printLeaders2(int a[], int size){
    int max = a[size-1];
    printf("%d ",max);
    for (int i = size-2; i >-1; i--){
        if(a[i] > max){
            max = a[i];
            printf("%d ",max);
        }
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printLeaders1(arr, n);
    printf("\n");
	printLeaders2(arr, n);
    printf("\n");
	return 0;
}