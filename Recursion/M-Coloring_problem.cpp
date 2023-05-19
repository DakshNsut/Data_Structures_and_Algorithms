#include<iostream>
#include<vector>
#include<cstring>
#define V 4
using namespace std;

// col is the colour no. with which the given node 'v'  is coloured
bool isPossible(int (*graph)[V], int m, int *color, int v){
    for(int k=0; k<V; k++){
        if(k!=v && graph[k][v] == 1 && color[k] == color[v]){
            return false;
        }
    }

    return true;
}

bool colourgraph(int (*graph)[V], int m, int *color, int v = 0){

    // All vertices were coloured with 'm' colours
    if(v == V){
        return true;
    }

    for(int i=1; i<=m; i++){
        if(isPossible(graph, m, color, v)){
            color[v] = i;
            // v+1 means going to the next vertex
            if(colourgraph(graph, m, color, v+1)){
                // Just return true because we don't want to go to the other paths,
                // this was possible for one path and that is what we wanted for atleast one solution
                return true;
            }
            // Backtracking because v+1 could be coloured,
            // maybe due to v+2, v+3, ... V
            color[v] = 0;
        }
    }

    return false;
}

// Time Complexity: O(m^V)
// Auxiliary Space: O(V)

int main(){

    int graph[V][V];
    memset(graph, 0, sizeof(graph));

    // Edges are (0, 1), (1, 2), (1, 3), (3, 0), (0, 2)
    graph[0][1] = 1;  graph[1][0] = 1;
    graph[1][2] = 1;  graph[2][1] = 1;
    graph[1][3] = 1;  graph[3][1] = 1;
    graph[3][0] = 1;  graph[0][3] = 1;
    graph[0][2] = 1;  graph[2][0] = 1;

    // The number of colours we have
    int m = 2;
    // This will be used to maintain the color of the vertices
    int color[V] = {0};
    if(colourgraph(graph, m, color)){
        cout<<"POSSIBLE!!"<<endl;
        return 0;
    }
    cout<<"NOT POSSIBLE :("<<endl;
    return 0;
}