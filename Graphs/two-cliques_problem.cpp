#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Check if Graph can be divided in two Cliques.
// A Clique is a subgraph of graph such that all
// vertices in subgraph are completely connected with each other.

struct Graph{
    int V; // number of vertices
    vector<int> *adj; // adjacency list for each vertex
    vector<int> color;

    // Initializing required variables
    Graph(int n){
        V = n;
        adj = new vector<int>[V];
        color = vector<int>(V, 1);
    }

    // Two add edge in a directed graph
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    // Checks if graph can be divided into two cliques or not
    bool checkTwoCliquePossible(){
        return isBipartite();
    }

    // Helper function
    bool isBipartite(){
        queue<int> q; // vertex
        vector<bool> visited(V,0);

        q.push(0);
        visited[0] = 1;
        int maxColor = 1;

        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int v: adj[u]){
                if(color[u] == color[v]){
                    color[v]++;
                }
                maxColor = max(maxColor, color[v]);
                if(maxColor > 2) return 0;

                if(!visited[v]){
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
        return 1;
    }
};

// Time Complexity: O(V+E)
// Auxiliary space: O(V)

int main(){
    // Given graph
    int G[][5] = {{0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };

    // Creating complement graph for the given graph
    Graph g(5);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(!G[i][j] && i!=j) g.addEdge(i,j);
        }
    }

    if(g.checkTwoCliquePossible()) cout << "Two Clique Possible !!";
    else cout << "Two Clique not Possible !!";

    return 0;
}