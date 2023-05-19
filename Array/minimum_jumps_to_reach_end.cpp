#include <iostream>
#include <climits>
using namespace std;

// find minimum jumps to reach the end

// -------------- RECURSIVE approach -------------
int min_jumps(int arr[], int n, int curr_pos){
    if(curr_pos >= n-1){
        return 0;
    }
    int minJumps = INT_MAX; // ans
    int maxSteps = arr[curr_pos]; // max number of steps one can take from curr_pos
    while(maxSteps>0){
        minJumps = min(minJumps, 1 + min_jumps(arr, n, curr_pos + maxSteps)); // Going through each possibility
        maxSteps--;
    }
    return minJumps;
}

// Time complexity: O(n^n)
// Auxiliary space: O(n)

// -------------- DP approach ------------
int min_jumps2(int arr[], int n){
    int *temp = new int[n]; // min_jumps array

    temp[0] = 0;
    for(int i=1; i<n; i++){
        temp[i] = INT_MAX;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(j+arr[j]>=i){
                // If i is reachable from j, then only one jump is required, hence temp[j] + 1.
                temp[i] = min(temp[i],temp[j] + 1);
            }
        }
    }

    // Important conditions
    if(temp[n-1] < 0 || temp[n-1] == INT_MAX){
        return -1;
    }

    return temp[n-1];
}

// Time Complexity: O(n2) 
// Auxiliary Space: O(n)

// -------------- OPTIMAL approach -------------
int min_jumps3(int arr[], int n){
    int maxReach = 0;
    int jumps = 0;
    int currEnd = 0;

    for(int i=0; i<n; i++){
        // Everytime we reach an element we are opening a new ladder
        maxReach = max(maxReach,i+arr[i]);

        if(maxReach>=n-1){
            // jump to that ladder and reach n-1
            return 1+jumps;
        }

        // we have reached were we could have reached most possibily
        if(i==maxReach){
            return -1;
        }

        // That ladder is finished, we couldn't reach end
        if(i == currEnd){
            // Jump to new ladder
            jumps++;
            // Jump to that ladder which has max size or which has most possibility to reach the end
            currEnd = maxReach;
        }
    }

    return jumps;
}

// Time Complexity: O(n) 
// Auxiliary Space: O(1)

int main(){
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << min_jumps(arr, n, 0) << endl;
    cout << min_jumps2(arr, n) << endl;
    cout << min_jumps3(arr, n) << endl;
    return 0;
}