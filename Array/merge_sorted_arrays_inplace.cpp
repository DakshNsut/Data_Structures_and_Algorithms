#include <iostream>
#include <algorithm>
using namespace std;

// ------------- Method 1 -------------
void mergeInplace(int* a, int n, int* b, int m){
    make_heap(b, b + m, greater<int>()); // now it is a min-heap

    for(int i=0; i<n; i++){
        if(a[i] > b[0]){
            pop_heap(b, b+m, greater<int>()); // pop from min-heap
            swap(a[i], b[m-1]);
            push_heap(b, b+m, greater<int>());
        }
    }

    make_heap(b, b + m); // now it is a max-heap
    sort_heap(b, b+m); // sort max-heap
}

// Time Complexity: O(N*logM + M*logN)
// Auxiliary Space: O(1)

// ------------- Method 2 (Euclid's Division Lemma) -------------
void mergeInplace(int a[], int b[], int n, int m){
    int i=0; // For arr1 : a
    int j=0; // For arr2 : b
    int k=0; // For result arr : a + b
    int mx = 1e2;

    // Traversing arr1 as result arr
    while(i<n && j<m && k<n){
        int ele1 = a[i] % mx;
        int ele2 = b[j] % mx;

        if(ele1 < ele2){
            a[k++] += (ele1 * mx); i++;
        }
        else{
            a[k++] += (ele2 * mx); j++;
        }
    }

    while(i<n && k<n){
        int ele1 = a[i] % mx;
        a[k++] += (ele1 * mx); i++;
    }

    while(j<m && k<n){
        int ele2 = b[j] % mx;
        a[k++] += (ele2 * mx); j++;
    }

    k = 0; // for arr2's first element
    // Traversing arr2 as result arr
    while(i<n && j<m && k<m){
        int ele1 = a[i] % mx;
        int ele2 = b[j] % mx;

        if(ele1 < ele2){
            b[k++] += (ele1 * mx); i++;
        }
        else{
            b[k++] += (ele2 * mx); j++;
        }
    }

    while(i<n && k<m){
        int ele1 = a[i] % mx;
        b[k++] += (ele1 * mx); i++;
    }

    while(j<m && k<m){
        int ele2 = b[j] % mx;
        b[k++] += (ele2 * mx); j++;
    }

    // restoring back the expected correct values in arr1 : a
    for(int i=0; i<n; i++){
        a[i] /= mx;
    }

    // restoring back the expected correct values in arr2 : b
    for(int i=0; i<m; i++){
        b[i] /= mx;
    }
}

// Time Complexity: O(m+n)
// Auxiliary space: O(1)

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[] =  {1, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 14};
    int n = 4;
    int m = 5;

    mergeInplace(a,b,n,m);
    print(a,n);
    print(b,m);
    return 0;
}