#include <iostream>

class Solution{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int left = 2*i+1, right = 2*i+2;
      int largest= i;
      if(left<n && arr[left]>arr[largest])
          {largest = left;}
      
      if(right<n && arr[right]>arr[largest])
          {largest = right;}
      if(largest != i){
          std::swap(arr[i],arr[largest]);
          heapify(arr,n,largest);
      }
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n){
        // Your Code Here
        for(int i=(n-2)/2;i>=0;i--){
            heapify(arr,n,i);
        }
    }
	// T(n) = O(n)

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n){
        //code here
        // Build the heap
        buildHeap(arr,n);
        
        // Heapify and get the max element at root
        for(int i=n-1;i>=1;i--){
            std::swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
	// T(n) = O(n*log(n))

};

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test above functions
int main(){
    int arr[] = {2,6,3,9,23,88,43};
    int n = sizeof(arr)/sizeof(arr[0]);

    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    return 0;
}