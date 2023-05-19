#include <iostream>
using namespace std;

// find a missing element and a repeating element in an array of sequence of 1 to n

// ------------------------ Naive --------------------------
int* findTwoElement(int *arr, int n) {
    bool *presence = new bool[n];
    for(int i=0; i<n; i++){
        presence[i] = 0;
    }
    int missing, twice;
    for(int i=0; i<n ;i++){
        if(presence[arr[i]-1] == 0){
            presence[arr[i]-1] = 1;
        }
        else{
            twice = arr[i];
        }
    }
        
    for(int i=0; i<n; i++){
        if(presence[i] == 0){
            missing = i+1;
        }
    }

    int *ans = new int[2];
    ans[0] = twice;
    ans[1] = missing;
    return ans;
}

int main()
{
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int *x =findTwoElement(arr, n);
    cout << "The missing element is " << x[1] << " and the repeating"
         << " number is " << x[0];
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// ------------------------------- Optimal ----------------------------
int *findTwoElement(int *arr, int n) {
    int twice, missing;
    for(int i=0; i<n; i++){
        if(arr[abs(arr[i])-1] > 0){
            // cout << arr[abs(arr[i]-1)] << endl;
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
        else{
            twice = abs(arr[i]);
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i]>0) missing = i+1;
    }

    int *ans = new int[2];
    ans[0] = twice;
    ans[1] = missing;
    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main()
{
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int *x = findTwoElement(arr, n);
    cout << "The missing element is " << x[1] << " and the repeating"
         << " number is " << x[0];
}

// ------------------------- Another optimal approach -----------------------
// C++ program to Find the repeating
// and missing elements

#include <bits/stdc++.h>
using namespace std;

//  The output of this function is stored at *x and *y
void getTwoElements(int arr[], int n,
                    int* x, int* y)
{
    //  Will hold xor of all elementsand numbers from 1 to n
    int xor1;

    //  Will have only single set bit of xor1
    int set_bit_no;

    int i;
    *x = 0;
    *y = 0;

    xor1 = arr[0];

    //  Get the xor of all array elements
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    //  XOR the previous result with numbers from 1 to n// 
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    //  Get the rightmost set bit in set_bit_no
    set_bit_no = xor1 & ~(xor1 - 1);

    // Now divide elements into two sets by comparing a rightmost set bit of xor1 with the bit at the same position in each element.
    // Also, get XORs of two sets. The two XORs are the output elements. The following two for loops serve the purpose
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            //  arr[i] belongs to first set
            *x = *x ^ arr[i];

        else
            //  arr[i] belongs to second set
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            //  i belongs to first set
            *x = *x ^ i;

        else
            //  i belongs to second set
            *y = *y ^ i;
    }

    // *x and *y hold the desired output elements
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main()
{
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);

    getTwoElements(arr, n, x, y);
    cout << "The missing element is " << *x << " and the repeating"
         << " number is " << *y;
}