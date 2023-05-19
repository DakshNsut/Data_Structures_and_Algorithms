#include <iostream>
#include <vector>
using namespace std;

// ---------- Vertex Cover problem ------------

struct Graph{
    int V; // number of vertices
    vector<int> *adj; // adjacency list for each vertex

    Graph(int n){
        V = n;
        adj = new vector<int>[n];
    }

    // Adds edge between u and v
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printVertexCover(){
        vector<bool> visited(V, 0);

        for(int u=0; u<V; u++){
            if(!visited[u]){
                for(int v: adj[u]){
                    if(!visited[v]){
                        cout << u << " " << v << " ";
                        visited[u] = 1;
                        visited[v] = 1;
                        break;
                        // this "break" command is necessary because now 'u' has been visited
                        // means all edges connecting u to any vertex is now broken
                        // thus next 'v' of the loop supposed to be having a connection with 'u' is actually not connected
                    }
                }
            }
        }
    }
};

// Time Complexity: O(V+E)
// Auxiliary space: O(V)

int main(){

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.printVertexCover();

    return 0;
}