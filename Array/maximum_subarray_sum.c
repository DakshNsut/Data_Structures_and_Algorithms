#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int max(int a, int b){
    return (a>b) ? a:b;
}

int kadane(int a[],int n){
    int cursum = 0;
    int maxsum = INT_MIN; // if all elements are negative
    for (int i = 0; i < n; i++){
        cursum = max(cursum+a[i], a[i]);
        maxsum = max(maxsum,cursum);
    }
    return maxsum;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);

    int nonwrapsum = kadane(a,n);
    int totalsum = 0;
    for (int i = 0; i < n; i++){
        totalsum += a[i];
        a[i] *= -1;
    }

    int wrapsum = totalsum + kadane(a,n);
    printf("Maximum sum contiguous subarray: %d",max(wrapsum,nonwrapsum));
}