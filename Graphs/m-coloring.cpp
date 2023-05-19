#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class node {
public:
    int color = 1;
    set<int> edges;
    // set is used here because we want adjacent list to be sorted
};

bool canPaint(vector<node> &graph, int n, int m){
    vector<bool> visited(n+1, 0);
    int maxColors = 1;

    // since the graph can have disconnected components,
    // we have to do a BFS taking each node as a source
    for(int uv = 1; uv <= n; uv++){
        if(visited[uv]) continue;

        visited[uv] = 1;
        queue<int> q;
        q.push(uv);

        while(!q.empty()){
            int u = q.front(); q.pop();

            for(auto v = graph[u].edges.begin();
                 v != graph[u].edges.end(); v++){
                // if color of adjacent vertices is same, that's a problem
                if(graph[u].color == graph[*v].color)
                graph[*v].color ++;

                maxColors = max(maxColors, max(graph[u].color, graph[*v].color));
                if(maxColors > m) return 0;

                // if adjacent vertex is not visited
                if(!visited[*v]){
                    visited[*v] = 1;
                    q.push(*v);
                }
            }
        }
    }

    return 1;
}

int main(){
    int n = 4;
    bool graph[n][n] = { { 0, 1, 1, 1 },
                         { 1, 0, 1, 0 },
                         { 1, 1, 0, 1 },
                         { 1, 0, 1, 0 } };
    int m = 3; // Number of colors

    // Transforming adjacency matrix to vector of node
    vector<node> nodes(n + 1);

    // Add edges to each node as per given input
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (graph[i][j]){
                // Connect the undirected graph
                nodes[i].edges.insert(i);
                nodes[j].edges.insert(j);
            }
        }
    }

    cout << canPaint(nodes, n, m) << endl;

    return 0;
}

// Time Complexity: O(V+E)
// Space Complexity: O(V)