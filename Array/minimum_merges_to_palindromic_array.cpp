#include <iostream>
#include <vector>
using namespace std;

// minimum number of merge operations required to make the array a palindrome

int minimumMergeToPalindrome(int arr[], int n){
    if(n==0 || n==1){
        return 0;
    }

    int s = 0;
    int e = n-1;
    int count = 0;
    while(s<e){
        if(arr[s] < arr[e]){
            arr[s+1] += arr[s]; // try to add the smaller element to reach = to arr[e].
            s++;
            count++;
        }
        else if(arr[s] > arr[e]){
            arr[e-1] += arr[e]; // try to add the smaller element to reach = to arr[s].
            e--;
            count++;
        }
        // if both of them are equal, they both are in their best palindromic state;
        // no need to disturb them
        else{
            s++; e--;
        }
    }
    return count;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

int main(){
    int a[] = {11, 14, 15, 99};
    int n = sizeof(a)/sizeof(a[0]);
    cout << minimumMergeToPalindrome(a,n);
    return 0;
}