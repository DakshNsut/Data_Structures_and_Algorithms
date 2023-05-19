#include <iostream>
#include <queue>
using namespace std;

// generate n numbers using only 5 and 6.

void generate56(int n){
    queue<string> q;
    q.push("5");
    q.push("6");

    for(int i=0; i<n; i++){
        string s = q.front(); q.pop();
        cout << s << " ";
        q.push(s+"5");
        q.push(s+"6");
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    generate56(60);
    return 0;
}