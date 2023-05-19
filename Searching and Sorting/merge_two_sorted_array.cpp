#include <iostream>
using namespace std;

void PrintArray(int *arr,int n){
    printf("The merged array elements are:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int *arr1,int n1,int *arr2,int n2,int *merged_arr){
    int i=0,j=0,k=0;
    // i-> arr1
    // j-> arr2
    // k-> arr_merged
    
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            merged_arr[k] = arr1[i];
            k++;
            i++;
        }
        
        else{
            merged_arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    
    while(i<n1){
        merged_arr[k] = arr1[i];
        k++;
        i++;
    }
    
    while(j<n2){
        merged_arr[k] = arr2[j];
        k++;
        j++;
    }
}

int main()
{
    int arr1[] = {1,5,8,10,18,20};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    
    int arr2[] = {2,3,6,7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    int merged[n1+n2];
    merge(arr1,n1,arr2,n2,merged);

    PrintArray(merged,n1+n2);

    // if (n1+n2) is odd
    if((n1+n2)&1){
        printf("The median is: %d ", merged[(n1+n2+1)/2-1]);
    }
    // if (n1+n2) is even
    else{
        printf("The median is: %0.1f ", (merged[(n1+n2)/2]+merged[(n1+n2)/2-1])/2.0);
    }
    
    return 0;
}