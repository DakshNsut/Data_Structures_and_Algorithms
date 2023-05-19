#include <stdio.h>

// to find maximum difference of elements in an array

int max_difference1(int *a,int n){
    // Behaves adversely for -ve elements
    int max_diff = a[1]-a[0];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[j]-a[i] > max_diff){
                max_diff = a[j]-a[i];
            }
        }
    }

    return max_diff;
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

int max_difference2(int *a,int n){
    int max_diff = a[1] - a[0];
    int min_ele = a[0];

    // we can do i=1 because we have covered at posibilities of i=0 in max_diff initial value.
    for (int i = 1; i < n; i++){
        if (a[i]-min_ele>max_diff){
            max_diff = a[i]-min_ele;
        }
        if (a[i]<min_ele){
            min_ele = a[i];
        }
    }
    return max_diff;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int max_difference3(int *a,int n){
    int max_diff = a[1]-a[0];

    // because we are moving from the right
    int max_ele = a[n-1]; 

    for (int i = n-2; i>=0; i--){
        if (max_ele-a[i] > max_diff){
            max_diff = max_ele-a[i];
        }
        if (a[i] > max_ele){
            max_ele = a[i];
        }
    }
    return max_diff;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int max_difference4(int *a,int n){
    int curr_diff = a[1]-a[0];
    int prev_diff = curr_diff;
    int max_sum = prev_diff;

    for (int i = 1; i < n-1; i++){
        int curr_diff = a[i+1]-a[i];
        if (prev_diff>0){
            prev_diff+=curr_diff;
        }

        // if prev is -ve we move to the next element...
        else{
            prev_diff = curr_diff;
        }

        if (prev_diff>max_sum){
            max_sum = prev_diff;
        }
    }
    return max_sum;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int arr[] = {1,6,4,4,23,98,7,8,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d ",max_difference1(arr,n));
    printf("%d ",max_difference2(arr,n));
    printf("%d ",max_difference3(arr,n));
    printf("%d ",max_difference4(arr,n));
}