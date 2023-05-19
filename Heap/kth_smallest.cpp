#include <iostream>
using namespace std;

// ---------------- Method - 1 ----------------
int partition(int arr[], int l, int r){
    int piv = l;
    int i = l;
    int j = r;
    while(i<j){
        while(arr[i]<=arr[piv]){
            i++;
        }
        while(arr[j]>arr[piv]){
            j--;
        }
            
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j], arr[piv]);
    return j;
}

int kthSMALLEST(int arr[], int l, int r, int k) {
    int pivot = partition(arr,l,r);
    if(pivot-l == k-1){
        return arr[pivot];
    }
    if(pivot-l > k-1){
        return kthSMALLEST(arr,l,pivot-1,k);
    }
    else{
        return kthSMALLEST(arr,pivot+1,r,k-pivot+l-1);
    }
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// ------------------ Method - 2 ---------------
void minHeapify(int arr[], int i, int n){
    int l = i*2 + 1;
    int r = i*2 + 2;

    int smallest = i;
    if(l<n && arr[l]<arr[smallest]){
        smallest = l;
    }
    if(r<n && arr[r]<arr[smallest]){
        smallest = r;
    }
    if(smallest != i){
        swap(arr[i],arr[smallest]);
        minHeapify(arr,i,n);
    }
}

void bulidMinHeap(int arr[], int n){

  for(int i=(n-2)/2; i>=0; i--){
    minHeapify(arr,i,n);
  }
}

void extractMin(int arr[], int &n){
  if(n==0){
    return;
  }

  if(n>1){
    arr[0] = arr[n-1];
    minHeapify(arr,0,n);
  }
  n--;
}

int kthSmallest(int arr[], int n, int k){
  bulidMinHeap(arr,n);

  for(int i=0; i<k-1; i++){
    extractMin(arr,n);
  }
  return arr[0];
}

// Time Complexity: O(n + k(logn))
// Auxiliary space: O(n)

int main(){
    int arr[] = {5,43,23,25,56,35};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << kthSmallest(arr,n,k) << endl;
    int arr2[] = {5,43,23,25,56,35};
    cout << kthSMALLEST(arr2,0,n-1,k);
    return 0;
}