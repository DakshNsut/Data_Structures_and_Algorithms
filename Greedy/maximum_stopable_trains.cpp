#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int m = 6;

// maximum number of trains for which stoppage can be provided

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    return p1.second < p2.second;
}

int maxStop(int arr[m][3], int m, int n){
    vector<pair<int,int>> vect[n]; // vector for each platform
    for(int i=0; i<m; i++){
        vect[arr[i][2]-1].push_back(make_pair(arr[i][0], arr[i][1]));
    }

    for(int i=0; i<n; i++){
        sort(vect[i].begin(), vect[i].end(), cmp);
    }

    int ansCount = 0;
    for(int i=0; i<n; i++){
        int prevEnd = -1; // previous.second of last pair added to answer
        for(pair<int,int> p : vect[i]){
            if(p.first > prevEnd){
                ansCount++;
                prevEnd = p.second;
            }
        }
    }

    return ansCount;
}

// Time Complexity: O(nlogn)
// Auxiliary space: O(n)

// driver function
int main()
{
    int arr[m][3] = { 1000, 1030, 1, 1010, 1030, 1, 1000, 1020, 2, 1030, 1230, 2, 1200, 1230, 3, 900, 1005, 1};
    int n = 3; // number of platforms
    cout << "Maximum Stopped Trains = " << maxStop(arr, m, n);
    return 0;
}