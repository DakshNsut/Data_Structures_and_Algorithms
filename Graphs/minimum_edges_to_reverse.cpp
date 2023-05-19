// minimum edges to reverse to make a path from source to destination

// ------------------ Using Dijkstra -----------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// for min-heap
struct cmp{
    bool operator()(pair<int,int> &p1, pair<int,int> &p2) {
        return p1.second > p2.second;
    }
};

struct Graph{
    int n;
    vector<pair<int,int>> *graph;

    Graph(int v){
        n = v;
        graph = new vector<pair<int,int>>[n];
    }

    // converts directed unweighted graph to directed weighted graph
    void modifyGraph(int edge[][2], int E){
        for(int i=0; i<E; i++){
            graph[edge[i][0]].push_back({edge[i][1], 0});
            graph[edge[i][1]].push_back({edge[i][0], 1}); // Reverse edge
        }
    }

    int getMinEdgeReversal(int edge[][2], int &E, int &V, int src, int dest){
        modifyGraph(edge, E);
        vector<bool> visited(V, 0);
        vector<int> dist(V, 1e9);
        dijkstra(visited, dist, src, dest);
        return (dist[dest] == 1e9) ? -1 : dist[dest];
    }

    void dijkstra(vector<bool> &vis, vector<int> &dist, int &src, int &dest){
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; // w, v
        dist[src] = 0;
        vis[src] = 1;
        pq.push({0,src});

        while(!pq.empty()){
            auto tp = pq.top(); pq.pop();
            int u = tp.second;

            for(auto t: graph[u]){
                int v = t.first;
                int w = t.second;
                if(vis[v]) continue;
                if(dist[u] == 1e9) continue;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    vis[v] = 1;
                    pq.push({dist[v],v});
                }
            }
        }
    }
};

int main()
{
    int V = 7;
    Graph g(V);

    // directed unweighted edge
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);
 
    int minEdgeToReverse = g.getMinEdgeReversal(edge, E, V, 0, 6);
 
    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not Possible." << endl;
 
    return 0;
}

// Time Complexity: O(E*log(V))
// Auxiliary space: O(V+E)

// --------------- Using 0-1 BFS concept -----------------------
// An optimisation to the dijkstra's algorithm
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> &p1, pair<int,int> &p2) {
        return p1.second > p2.second;
    }
};

struct Graph{
    int n;
    vector<pair<int,int>> *graph;

    Graph(int v){
        n = v;
        graph = new vector<pair<int,int>>[n];
    }

    // converts directed unweighted graph to directed weighted graph
    void modifyGraph(int edge[][2], int E){
        for(int i=0; i<E; i++){
            graph[edge[i][0]].push_back({edge[i][1], 0});
            graph[edge[i][1]].push_back({edge[i][0], 1}); // Reverse edge
        }
    }

    int getMinEdgeReversal(int edge[][2], int &E, int &V, int src, int dest){
        modifyGraph(edge, E);
        vector<bool> visited(V, 0);
        vector<int> dist(V, 1e9);
        dijkstra(visited, dist, src, dest);
        return (dist[dest] == 1e9) ? -1 : dist[dest];
    }

    void dijkstra(vector<bool> &vis, vector<int> &dist, int &src, int &dest){
        deque<int> dq; // vertex
        dist[src] = 0;
        vis[src] = 1;
        dq.push_front({src});

        while(!dq.empty()){
            int u = dq.front(); dq.pop_front();

            for(auto t: graph[u]){
                int v = t.first;
                int w = t.second;
                if(vis[v]) continue;
                if(dist[u] == 1e9) continue;

                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    vis[v] = 1;

                    if(w == 0) dq.push_front(v);
                    else dq.push_back(v);
                }
            }
        }
    }
};

// Time Complexity: O(V+E)
// Space Complexity: O(V+E)

int main()
{
    int V = 7;
    Graph g(V);

    // directed unweighted edge
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);
 
    int minEdgeToReverse = g.getMinEdgeReversal(edge, E, V, 0, 6);
 
    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not Possible." << endl;
 
    return 0;
}