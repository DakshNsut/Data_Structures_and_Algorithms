#include <iostream>
#include <algorithm>
using namespace std;

// count frequency of x in sorted array

// -------------- Method - 1 ----------------
int freq_x1(int* a, int n, int x){
    int res = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == x){
            res++;
        }
    }
    return res;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// -------------- Method - 2 ----------------
int binary_search(int *a,int n,int x){
    int low = 0;
    int high = n-1;
    int mid = (low+high)/2;

    while (low < high){ 
        if (a[mid] == x){
            return mid;
        }
        else if(a[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        mid = (low+high)/2;
    }
    return -1;
}

int freq_x2(int* a, int n, int x){
    int ind = binary_search(a,n,x);

    if(ind == -1)
        return 0;
    
    // not 0 because i have found that before once
    int count = 1;
    
    // checking number of elements in left array
    int left = ind-1;
    while(left >= 0 && a[left] == x){
        count++;
        left--;
    }

    // checking number of elements in right array
    int right = ind+1;
    while(right<n && a[right]==x){
        count++;
        right++;
    }

    return count;
}

// Time Complexity: O(log(n) + frequency)
// Auxiliary space: O(1)

// -------------- Using STL ----------------
int freq_x3(int* a,int n, int x){
    //c++ code
    int *low = lower_bound(a,a+n,x);

    // case when ele is not present gives two cases 1. either it gives an ele greater than x ,or 2. it gives a.end()
    if(low == (a+n) || *low != x){
        return 0;
    }

    // always give ele greater than x
    int* high = upper_bound(a,a+n,x);

    return (high-low);
}

// Time Complexity: O(log(n))
// Auxiliary space: O(1)

int main(){
    // given sorted array
    int arr[] = {1,3,4,6,8,8,9,9,9,10,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = 9;

    printf("The frequency of %d in the array is %d.\n",element,freq_x1(arr,size,element));
    printf("The frequency of %d in the array is %d.\n",element,freq_x2(arr,size,element));
    printf("The frequency of %d in the array is %d.",element,freq_x3(arr,size,element));
}