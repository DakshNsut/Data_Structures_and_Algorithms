#include<iostream>
#include<vector>
using namespace std;

// ----------------------------- RECURSIVE -----------------------------
int minEle(vector<int> &arr, int s, int e){
    int mid = s + (e - s) / 2;
    if(s>=e){
        return mid;
    }
    if(arr[s]<arr[e]){
        return s;
    }

    if(arr[mid] >= arr[s]){
        return minEle(arr, mid + 1, e);
    }
    else{
        return minEle(arr, s, mid);
    }
}

// Time Complexity: O(logn)
// Auxiliary Space: O(n) - recursion call stack

int main(){
    vector<int> arr = {2,3,4,5,6,1};
    int s = 0;
    int e = arr.size()-1;
    cout << arr[minEle(arr, s, e)] << endl;

    // ------------------- ITERATIVE --------------------
    int mid = s + (e-s)/2;

    while(s<e){
        // 360 deg rotation
        if(arr[s]<=arr[e]){
            mid = s;
            break;
        }

        // min element at left side
        if(arr[mid]<=arr[s]){
            e = mid;
        }

        else{
            s = mid+1;
        }

        mid = s + (e-s)/2;
    }

    cout << arr[mid];

	// Time Complexity: O(logn)
	// Auxiliary Space: O(1)
}