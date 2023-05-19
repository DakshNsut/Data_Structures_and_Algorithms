#include <iostream>
#include <vector>
using namespace std;

// to find number of triangles in a directed and an undirected graph

struct Graph{
    int V; // number of vertices
    int isDirected; // to identify if the graph if directed or not
    vector<vector<int>> adj; // adjacency list for each vertex

    // Initializing required variables
    Graph(int n, int isDi, vector<vector<int>> &graph){
        V = n;
        isDirected = isDi;
        adj = graph;
    }

    // Prints the count of triangles that can be found in the graph
    int printTriangles(){
        vector<bool> visited; // just giving a visited array so that memory reference is used rather than allocating new memory
        int countTriangles = 0;

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                for(int k=0; k<V; k++){
                    if(adj[i][j] && adj[j][k] && adj[k][i]) countTriangles++;
                }
            }
        }

        return (isDirected) ? (countTriangles/3) : (countTriangles/6);
    }
};

// Time Complexity: O(V^3)
// Auxiliary Space: O(V)

int main(){
    vector<vector<int>> graph1 = { {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    Graph g1(4, 0, graph1);
    cout << g1.printTriangles() << endl;

    vector<vector<int>> graph2 = { {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };

    Graph g2(4, 1, graph2);
    cout << g2.printTriangles() << endl;

    return 0;
}