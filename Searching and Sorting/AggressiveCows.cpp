#include<iostream>
using namespace std;

// Given an array having positions of stalls. k = no. of cows(n).
// To prevent cows from fighting you need to assign the cows to the stalls,
// such that the min. distance between any two of them is as large as possible.

bool isPossible(vector<int> & stalls, int &k, int &n, int& mid){
    int cowCount = 1;

    // Fixing position of Cow 1
    int lastPos = stalls[0];
    int nextPos = -1;

    for(int i=0; i<n; i++){
        // a position for other Cow
        nextPos = stalls[i];
        if(nextPos - lastPos >= mid){

            // Got a valid position for Cow 2
            cowCount++;

            // If position to all cows could not be allocated, take ** lastpos = last position of cow alloted
            // Because now, distance will be calculated from that cow to the next cow
            // This is for next cow
            lastPos = stalls[i];

            if(cowCount == k){
                return true;
            }
        }
    }
    return false;
}

int allocate_cows(vector<int> &stalls, int &k, int &n){
    sort( stalls.begin(), stalls.end() );
    int maxi = stalls[stalls.size()-1];

    int s = 0;
    int e = maxi;

    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(stalls, k, n, mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }

    return ans;
}

// Time Complexity: O(n*log(m)) = n is number of stalls, m is last stall
// SpaceComplexity: O(1)

int main(){
    vector<int> stalls = {4,3,2,1,6};
    int k = 2;
    int n = stalls.size();

    cout << allocate_cows(stalls, k, n) << endl;
}

// ---------------------------- RECURSIVELY ----------------------------

#include<iostream>
#include<vector>
#include<algorithm>

#define k 2
#define n 5
using namespace std;

bool isPossible(vector<int> &stalls, int mid, int lastPos, int cowCount = 1, int i=0, int nextPos=-1){
    if(i==n){
        return false;
    }

    nextPos = stalls[i];
    if(nextPos-lastPos >= mid){

        if(cowCount+1 == k){
            return true;
        }

        return isPossible(stalls, mid, stalls[i], cowCount + 1, i+1);
    }
    else{
        return isPossible(stalls, mid, lastPos, cowCount, i+1);
    }
}

int allocate_cows(vector<int> &stalls, int s, int e, int ans=-1){
    if(s>e){
        return ans;
    }

    int mid = s + (e - s) / 2;

    if(isPossible(stalls, mid, stalls[0])){
        allocate_cows(stalls, mid + 1, e, mid);
    }
    else{
        allocate_cows(stalls, s, mid - 1, ans);
    }
}

// Time Complexity: O(n*log(m)) = n is number of stalls, m is last stall
// SpaceComplexity: O(m*n)

int main(){
    vector<int> stalls = {4,3,2,1,6};
    sort(stalls.begin(), stalls.end());

    cout<<allocate_cows(stalls, 0, stalls[n-1]);
}