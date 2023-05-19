#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// to find median of sorted arrays of equal size

int Getmedian(int arr[], int n){
    if(n&1 == 0)
        return (arr[n/2-1] + arr[n/2])>>1;
    return arr[n/2];
}

int median(int arr1[], int arr2[], int n){
    if(n <= 0){
        return -1;
    }
    else if(n == 1){
        return (arr1[0] + arr2[0]) >> 1;
    }
    else if (n == 2){
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) >> 1;
    }

    int m1 = Getmedian(arr1,n);
    int m2 = Getmedian(arr2,n);

    if(m1 == m2){
        return m1;
    }

    else if(m1<m2){
        if(n&1 == 0)
            return median(arr1+(n/2)-1,arr2,n-(n/2)+1);
        return median(arr1+n/2,arr2,n-n/2);
    }

    else{
        if(n&1==0)
            return median(arr2+(n/2)-1,arr1,n-(n/2)+1);
        return median(arr2+(n/2),arr1,n-n/2);
    }
}

// Time Complexity: O(log(n))
// Auxiliary space: O(1)

int main(){
    int ar1[] = { 1, 12, 15, 26, 38 };
    int ar2[] = { 2, 13, 17, 30, 45 };
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    cout << median(ar1,ar2,n1);

    return 0;
}