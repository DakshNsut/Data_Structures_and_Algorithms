#include <iostream>
#define ELE 1,\
2,\
3,\
7,\
7,\
7,\
13,\
13,\
13,\
99
using namespace std;

// ------------------------ Leftmost occurrence ----------------------------
int min_ind(int arr[], int l, int h, int item, int save){
    if(l>h){
        // returning the found index till now
        return save;
    }

    int mid = l + (h-l)/2;

    if(arr[mid] == item){
        // Saving the found element
        // and, moving to the left side to find minimum index occurence
        min_ind(arr, l, mid-1, item, mid);
    }

    else if(arr[mid] > item){
        min_ind(arr, l, mid-1, item, save);
    }

    else{
        min_ind(arr, mid+1, h, item, save);
    }
}

// ------------------------ Rightmost occurrence ----------------------------
int max_ind(int arr[], int l, int h, int item, int save){
    if(l>h){
        // returning the found index till now
        return save;
    }

    int mid = l + (h-l)/2;

    if(arr[mid] == item){
        // Saving the found element
        // and, moving to the left side to find minimum index occurence
        max_ind(arr, mid+1, h, item, mid);
    }

    else if(arr[mid] > item){
        max_ind(arr, l, mid-1, item, save);
    }

    else{
        max_ind(arr, mid+1, h, item, save);
    }
}

// Time Complexity: O(log(n))
// Auxiliary space: O(log(n))

int main(){
    int arr[] = { ELE };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << min_ind(arr, 0, n-1, 13, -1) << endl;
    cout << max_ind(arr, 0, n-1, 13, -1) << endl;
    return 0;
}