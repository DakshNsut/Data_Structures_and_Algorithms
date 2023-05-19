#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ------------- BRUTE-FORCE Soln ----------------
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();

    for(int i=0; i<n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        // This interval is already overlapped by the below for loop
        if(!ans.empty() && start <= ans.back()[1]){
            continue;
        }

        for(int j=i+1; j<n; j++){
            if(end >= intervals[j][0]){
                end = max(end,intervals[j][1]);
            }
        }

        ans.push_back({start,end});
    }
    return ans;
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// ------------------- OPTIMAL Soln ------------------
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for(auto interval:intervals){
        if(ans.empty() || ans.back()[1] < interval[0]){
            ans.push_back(interval);
        }
        else{
            ans.back()[1] = max(ans.back()[1],interval[1]);
        }
    }
    return ans;
}

// Time Complexity: O(n*log(n))
// Auxiliary space: O(1)

void print(vector<vector<int>> &intervals){
    for(vector<int> &v: intervals){
        for(int i: v){
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,4},{6,8},{9,10}};
    intervals = merge(intervals);
    print(intervals);
    return 0;
}