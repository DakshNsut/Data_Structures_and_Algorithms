// SEVEN BRIDGES OF KONIGSBERG

// ~~~~~~~~~~~ Find Euler Path in an undirected graph ~~~~~~~~~~
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

    // Removes edge between u and v
    void rmvEdge(int u, int v){
        vector<int>::iterator iu = find(adj[u].begin(), adj[u].end(), v);
        vector<int>::iterator iv = find(adj[v].begin(), adj[v].end(), u);
        *iu = -1;
        *iv = -1;
    }

    void printEulerTour(){
        // as per Euler if no. of odd degree vertices is not 0 or 2,
        // then Euler path is not possible
        // count number of odd degree vertices
        int count = 0;
        for(int u=0; u<V; u++){
            if(adj[u].size() & 1){
                count++;
            }
        }

        if(count != 0 && count != 2){
            cout << "Euler Path not possible" << endl;
            return;
        }

        // Euler path starts from an odd degree vertex (if exists)
        cout << "Possible Euler Path is as follows: " << endl;
        int u = 0;
        for(int i=0; i<V; i++){
            if(adj[i].size() & 1){
                u = i;
                break;
            }
        }

        printEulerTourUtil(u);
    }

    // Helper function to print Euler Tour
    void printEulerTourUtil(int u){
        for(int v: adj[u]){
            if(v != -1 && isValidNextEdge(u,v)){
                cout << u << " - " << v << endl;
                rmvEdge(u,v);
                printEulerTourUtil(v);
            }
        }
    }

    // Checks if the specified edge between u-v can be added to the Euler path
    bool isValidNextEdge(int u, int v){
        int count = 0; // count of adjacents of u
        // 1. if v is the only adjacent of u
        for(int v: adj[u]){
            if(v != -1){
                count++;
            }
        }

        if(count == 1) return 1;

        vector<bool> visited(V, 0);
        // 2. if u-v is not a bridge edge
        int count1; // count of vertices reachable from u
        count1 = DFSCount(u, visited);

        int count2; // count of vertices reachable from u, without having edge u-v
        rmvEdge(u,v);
        visited = vector<bool>(V,0); // re-initializing visited vector
        count2 = DFSCount(u, visited);

        addEdge(u,v);

        return (count1 > count2) ? false : true;
    }

    // returns the number of vertices reachable from u
    int DFSCount(int u, vector<bool> &vis){
        vis[u] = 1;
        int count = 1; // u is reachable from itself
        for(int v: adj[u]){
            if(v != -1 && !vis[v]){
                count += DFSCount(v, vis);
            }
        }
        return count;
    }
};

// Time Complexity: O(V*E)
// Space Complexity: O(V+E)

int main(){

    cout << "Example 1: " << endl;
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.printEulerTour();
    cout << endl;

    cout << "Example 2: " << endl;
    Graph g2(5);
    g2.addEdge(0,4);
    g2.addEdge(0,1);
    g2.addEdge(0,3);
    g2.addEdge(1,3);
    g2.addEdge(2,3);
    g2.addEdge(2,3);
    g2.addEdge(1,2);
    g2.printEulerTour();
    cout << endl;

    cout << "Example 3: " << endl;
    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(0, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 1);
    g3.printEulerTour();

    return 0;
}