// ---------------- Using DSU -------------------

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// 
//  * Complete the 'journeyToMoon' function below.
//  *
//  * The function is expected to return an INTEGER.
//  * The function accepts following parameters:
//  *  1. INTEGER n
//  *  2. 2D_INTEGER_ARRAY astronaut
// 

class DSU{
    public:
    int n; // number of items
    int *parent; // parent array
    int *rank; // rank array
    // rank[i] = number of nodes below it in the set tree (including itself)

    DSU(int v){
        n = v;
        parent = new int[n];
        rank = new int[n];

        // Initializing parent array
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void Union(int a, int b){
        int u = find(a);
        int v = find(b);
        if(u == v) return;

        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
};

int journeyToMoon(int n, vector<vector<int>> astronaut){
    DSU dsu(n);
    int size = astronaut.size();

    // doing union of people from same country
    for(int i=0; i<size; i++){
        dsu.Union(astronaut[i][0], astronaut[i][1]);
    }

    unordered_map<int,vector<int>> m;
    // Grouping people from each country.
    for(int i=0; i<n; i++){
        int root = dsu.find(i);
        m[root].push_back(i);
    }

    int ans = n*(n-1)/2; // C(n,2)
    for(auto it = m.begin(); it != m.end(); it++){
        int x = (it->second.size());
        ans -= x*(x-1)/2; // C(x,2)
    }

    return ans;
}

// Time Complexity: O(nlogn)
// Auxiliary space: O(n)

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
    int n = stoi(first_multiple_input[0]);
    int p = stoi(first_multiple_input[1]);
    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);
        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);
        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);
            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);
    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

// ---------------------- Using DFS ----------------------
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


//  * Complete the 'journeyToMoon' function below.
//  *
//  * The function is expected to return an INTEGER.
//  * The function accepts following parameters:
//  *  1. INTEGER n
//  *  2. 2D_INTEGER_ARRAY astronaut
 
 
void dfs(vector<int> graph[], int u, vector<bool> &vis, int &count){
    vis[u] = 1;
    count++;
    
    for(int v: graph[u]){
        if(!vis[v]){
            dfs(graph, v, vis, count);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> graph[n];
    int size = astronaut.size();

    for(int i=0; i<size; i++){
        int u = astronaut[i][0];
        int v = astronaut[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = n*(n-1)/2;
    vector<bool> visited(n,0);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int count = 0;
            dfs(graph, i, visited, count);
            ans -= count*(count-1)/2;
        }
    }

    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main()
{	
	string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
    int n = stoi(first_multiple_input[0]);
    int p = stoi(first_multiple_input[1]);
    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);
        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);
        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);
            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);
    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}