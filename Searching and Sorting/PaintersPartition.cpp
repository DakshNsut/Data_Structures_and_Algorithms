#include<iostream>
#include<vector>
using namespace std;

// We have to paint n boards of length {A1, A2…An}. There are k painters available
// and each takes 1 unit of time to paint 1 unit of the board. The problem is to
// find the minimum time to get this job was done under the constraints that any
// painter will only paint continuous sections of boards.

bool isPossible(vector<int> &arr, int k,  int mid){
    int painterCount = 1;
    int boardSum = 0;
    
    for(int i = 0; i<arr.size() ;i++){
        if(boardSum + arr[i] <= mid){
            boardSum += arr[i];
        }
        else{
            painterCount++;
            boardSum = arr[i];
            
            if(painterCount > k || arr[i]>mid){
                return false;
            }
        }
    }
        return true;
}

int findLargestMinDistance(vector<int> &boards, int k){
    int sum = 0;
    for(int i: boards){
        sum+=i;
    }
    
    int s = 0;
    int e = sum;
    int mid = s+ (e-s)/2;
    
    int ans =-1;
    while(s<=e){
        if(isPossible(boards, k, mid)){
            ans = mid;
            e = mid -1;
        }
        else{
            s = mid+1;
        }
        mid = s+ (e-s)/2;
    }
    
    return ans;
}

// Time Complexity: O(N * log (sum (arr[]))        .
// Auxiliary Space: O(1)

int main(){
    vector<int> arr = { 10, 20, 60, 50, 30, 40 };
    int k = 3;
    cout << findLargestMinDistance(arr, k);
    return 0;
}