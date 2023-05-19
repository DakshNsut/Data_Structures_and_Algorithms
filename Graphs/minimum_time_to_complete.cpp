#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// to find minimum time taken by each job to be completed in a DAG(directed acyclic graph)

// For a directed graph
struct Graph{
    public:
    int V;
    vector<int> *adj;
    int *indegree;

    Graph(int n){
        V = n;
        adj = new vector<int>[n];
        indegree = new int[n];
        for(int i=0; i<n; i++){
            indegree[i] = 0;
        }
    }

    void addEdge(int u, int v){
        adj[u-1].push_back(v-1); // because nodes are given as 1 to V
        indegree[v-1]++;
    }

    // ------------ USING DFS (topological sort) ----------------
    void printOrder1(){
        int time = 0;
        vector<int> executionTime(V);
        vector<bool> visited(V, 0);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                // visited has to be checked here only for those nodes which can't be reached from any node
                DFSutil(i, time, executionTime, visited);
            }
        }

        for(int t : executionTime){
            cout << t << " ";
        }
        cout << endl;
    }

    void DFSutil(int u, int time, vector<int> &res, vector<bool> &vis){
        vis[u] = 1;
        // if this node needs more time to be executed, then no updation will be done
        res[u] = max(res[u], time+1);

        for(int v: adj[u]){
            // we are not seeing here that node is visited or not because even if it is visited
            // but node can be visited on a node 'u' whose execution time is higher than the expected execution time of 'v'
            // since 'v' is dependent on 'u', the execution time of 'v' and other nodes dependent on 'v' is to be updated to time[u] + 1
            DFSutil(v, time+1, res, vis);
        }
    }

    // ------------------ USING BFS (topological sort) -----------------
    void printOrder2(){
        queue<int> q;
        int *res = new int[V];

        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
                res[i] = 1;
            }
        }

        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int v: adj[u]){
                indegree[v]--;
                // we are not seeing here that node is visited or not because even if it is visited
                // but node can be visited on a node 'u' whose execution time is higher than the
                // expected execution time of 'v' since 'v' is dependent on 'u', the execution time
                // of 'v' and other nodes dependent on 'v' is to be updated to time[u] + 1
                if(indegree[v] == 0){
                    q.push(v);
                    res[v] = (res[u] + 1);
                }
            }
        }

        for(int i=0; i<V; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
};

// Time Complexity: O(V+E)
// Auxiliary space: O(V+E)

int main(){
    // Given Nodes N and edges M
    int n, m;
    n = 7;
    m = 7;

    Graph g(n);

    // Given Directed Edges of graph
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.addEdge(5, 7);

    g.printOrder1();
    g.printOrder2();
    return 0;
}