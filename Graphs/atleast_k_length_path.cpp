#include <iostream>
#include <vector>
using namespace std;

// find if there is a simple path (without any cycle) starting from given source and
// ending at any other vertex such that the distance from source to that vertex is
// atleast ‘k’ length.

struct Graph{
    int n;
    vector<pair<int,int>> *graph;

    Graph(int v){
        n = v;
        graph = new vector<pair<int,int>>[n];
    }

    void addEdge(int u,int v, int w){
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    bool pathMoreThanK(int src, int k){
        vector<bool> vis(n,0);
        return solve(src, k, vis);
    }

    bool solve(int u, int k, vector<bool> &vis){
        vis[u] = 1;
        if(k <= 0) return 1;

        for(auto tp: graph[u]){
            int v = tp.first;
            int w = tp.second;
            if(vis[v]) continue;
            if(solve(v, k-w, vis)) return 1;
        }

        vis[u] = 0;
        return 0;
    }
};

int main(){
    Graph g(9);
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << g.pathMoreThanK(0, 62) << endl;
    cout << g.pathMoreThanK(0, 60) << endl;
    return 0;
}

// Time Complexity: O(V+E)
// Auxiliary space: O(V)