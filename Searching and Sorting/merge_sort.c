#include <stdio.h>

void Merge(int A[],int low,int high,int mid){
    int i = low; // start of first part of the array
    int j = mid+1; // start of second part of the array
    int k = low; // start of aux array
    int B[high+1];

    while (i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }

        else
        {
            B[k]=A[j];
            j++;
            k++;
        }
    }

    while (i<=mid){
        B[k]=A[i];
        i++;
        k++;
    }

    while (j <= high){
        B[k]=A[j];
        j++;
        k++;
    }

    for (int i = low; i <=high; i++){
        A[i]=B[i];
    }

}

void MergeSort(int arr[],int low,int high){
    if (low<high){
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,high,mid);
    }
}

// Time Complexity: O(n*log(n))
// Auxiliary space: O(n)

int main(){
    int Arr[] = {1, 6, 3,22,7,3,2};
    int size=7;
    MergeSort(Arr,0,size-1);

    for (int i = 0; i < size; i++){
        printf("%d ",Arr[i]);
    }
}