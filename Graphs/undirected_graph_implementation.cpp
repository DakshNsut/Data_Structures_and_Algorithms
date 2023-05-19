#include<iostream>
#include<vector>
using namespace std;

void printGraph(vector<int> graph[], int &V){
    for(int i=0; i<V; i++){
        cout << i << ": ";
        for(int i : graph[i]) cout << i << " ";
        cout << endl;
    }
}

void addEdge(vector<int> graph[], int i, int j){
    // For undirected graph
    graph[i].push_back(j);
    graph[j].push_back(i);
}

int main(){
    int V = 5;
    // vector<int> *graph = new vector<int>[V]; // Dynamic memory allocation
    vector<int> graph[V];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph, V);

    return 0;
}