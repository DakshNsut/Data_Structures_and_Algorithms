#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int maxIndex(int dist[], int &n){
    int maxInd = 0;
    for(int i=0; i<n; i++){
        if(dist[i] > dist[maxInd]) maxInd = i;
    }

    return maxInd;
}

void selectKcities(int &n, int weight[][4], int &k){
    // Initializing dist to nearest center for each node
    int *dist = new int[n];
    for(int i=0; i<n; i++) dist[i] = INT_MAX;

    vector<int> centers; // answer
    int max = 0; // randomly selected center

    // Finding K- centers
    for(int i=0; i<k; i++){
        centers.push_back(max);
        // Update dist to nearest center for each node wrt newly added center
        // This is done because we want max of min distance of each node to every center
        for(int j=0; j<n; j++){
            dist[j] = min(dist[j], weight[max][j]);
        }
        max = maxIndex(dist, n);
    }

    // Maximum distance of every node to every center
    cout << dist[max] << endl;

    for(int i : centers) cout << i << " ";
}

// Time Complexity: O(n*k)
// Auxiliary space: O(k)

int main(){
    int n = 4;
    int weights[4][4] = { { 0, 4, 8, 5 }, { 4, 0, 10, 7 }, { 8, 10, 0, 9 }, { 5, 7, 9, 0 } };
    int k = 2;
    selectKcities(n, weights, k);
    return 0;
}