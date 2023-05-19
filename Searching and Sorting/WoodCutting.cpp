#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &heights, int m, int mid){
    int total_wood = 0;
    for(int i=0; i<heights.size(); i++){
        int wood = heights[i]-mid;
        if(wood>0){
            total_wood+=wood;
        }
    }

    if(total_wood >= m){
        return true;
    }
    return false;
}

int getmaxheight(vector<int> &heights, int m){
    int maxi = -1;
    for(int i: heights){
        maxi = max(maxi, i);
    }

    int s = 0;
    int e = maxi-1;
    int mid = s+(e-s)/2;

    int ans = -1;

    while(s<=e){
        if(isPossible(heights,m,mid)){
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

// Time Complexity: O(n * Log2m), where m is the maximum element of the given array
// Auxiliary Space: O(1)

int main(){
    vector<int> v = {4, 42, 40, 26, 46};
    int m = 20;

    cout << getmaxheight(v,m);
}