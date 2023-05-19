#include <iostream>
#include <climits>
using namespace std;

// Given a set of cities and the distance between every pair of cities, the problem is to
// find the shortest possible route that visits every city exactly once and returns to
// the starting point (Hamiltonian Cycle).

int n = 4;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};

int VISITED_ALL = (1 << n) - 1;
int dp[16][4]; // dp[2^n][n]

int tsp(int mask, int pos){
    if(mask == VISITED_ALL){
        return dist[pos][0]; // dist from pos to source
    }

    // DP
    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for(int city = 0; city<n; city++){
        // if not visited
        if((mask & (1 << city)) == 0){
            int newAns = dist[pos][city] + tsp(mask|(1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

// Time Complexity : O(n2*2n)
// Auxiliary Space: O(n*2n)

int main(){
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            dp[i][j] = -1;
        }
    }

    int res = tsp(1, 0); // mask = 0, source = 0
    cout << res;
    return 0;
}