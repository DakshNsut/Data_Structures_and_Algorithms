#include <iostream>
#include <climits>
using namespace std;

// To Convert array to zig-zag form
// a < b > c < d > e ......
void zig_zag(int arr[], int n){
    bool flag = true;

    for(int i=0; i<n-1; i++){
        if(flag){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        else{
            if(arr[i] < arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }

        flag = !flag;
    }
}

// To print the array
void print_array(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    zig_zag(arr, n);
    print_array(arr, n);
}