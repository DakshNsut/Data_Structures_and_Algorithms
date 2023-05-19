#include<iostream>
#include<vector>
using namespace std;

// Ranks of cooks are available in rank vector
// 1 <= rank[i] <= 10
// m = no. of dishes
// Cook with rank 'r'
// for one dish takes = 'r' minutes
// for second dish takes = '2*r' minutes

bool isPossible(vector<int> &rank, int n, int m, int mid){
    int cookCount = 1;
    int timeTaken = 0;
    int j = 0;

    for(int i = 1; i<=m; i++){
        int t = rank[cookCount-1] * i;

        if(timeTaken+t <= mid){
            timeTaken+=t;
        }
        else{
            cookCount++;
            timeTaken = 0;
            j+=(i-1);
            i = 0;

            if(cookCount > n && j<m){
                return false;
            }
        }
    }

    return true;
}

int allocate_dishes(vector<int> &rank, int n, int m){
    int s = 0;
    int e = 5*m*(m+1);
    int ans = -1;

    int mid = s+(e-s)/2;
    while(s <= e){
        if(isPossible(rank, n, m, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }

    return ans;
}

// Time Complexity: O(n*log(n)), n = no. of cooks
// Auxiliary space: O(1)

int main(){
    vector<int> v = {10};
    int n = 1;
    int m = 1;

    cout << allocate_dishes(v, n, m);
}