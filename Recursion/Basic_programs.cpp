#include <iostream>
#define ELE 1, \
2, \
3, \
4
using namespace std;

// -------------- Find exponentiation -------------------
int pow(int a, int b){
    if(b==0){
        return 1;
    }

    return a * pow(a, b-1);
}

// ---------------------- Find n! ----------------
int factorial(int n){
    if(n<0){
        return -1;
    }
    if(n==0){
        return 1;
    }

    return n * factorial(n-1);
}

// -------------- Find nth fibonacci number ---------------
int fibonacci(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

// ------------------------  Check if array is sorted ------------------------
bool isSorted(int arr[], int ind){
    if(ind == 0 || ind == -1){
        return true;
    }

    return arr[ind]>=arr[ind-1] && isSorted(arr, ind-1);
}

// ------------------------ Sum of items ---------------------------------
int sum(int arr[], int n){
    if(n==-1){
        return 0;
    }

    return arr[n] + sum(arr, n-1);
}

// ---------------------------- Linear Search ----------------------------
int ls(int arr[], int n, int item){
    if(n == -1){
        return -1;
    }
    if(item == arr[n]){
        return n;
    }
    else{
        ls(arr, n-1, item);
    }
}

// ---------------------------- Binary Search ----------------------------
int bs(int arr[], int l, int h, int item){
    if(l>h){
        return -1;
    }

    int mid = l + (h-l)/2;

    if(item == arr[mid]){
        return mid;
    }
    else if(item > arr[mid]){
        bs(arr, mid+1, h, item);
    }
    else{
        bs(arr, l, mid-1, item);
    }
}

int main(){
    int m = 3;
    int n = 3;
    int arr[] = {ELE};
    int size = 4;

    cout << pow(n, m) << endl;
    cout << factorial(n) << endl;
    cout << fibonacci(n) << endl;
    cout << isSorted(arr, size-1) << endl;
    cout << sum(arr, size-1) << endl;
    cout << ls(arr, size-1, 3) << endl;
    cout << bs(arr, 0, size-1, 33) << endl;
}