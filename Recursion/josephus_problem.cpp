#include <iostream>
#include <list>
#include <climits>
using namespace std;

// to find kth permutation of string with sequence 1 to n.

// ------------------- Using list ----------------
int josephus(int n, int k){
    list<int> l;
    for(int i=1; i<=n; i++){
        l.push_back(i);
    }

    auto it = l.begin();
    while(l.size()>1){
        for(int count=1; count < k; count++){
            it++;
            if(it == l.end()){
                it = l.begin();
            }
        }

        it = l.erase(it);
        if(it == l.end()){
            it = l.begin();
        }
    }
    
    return *(l.begin());
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(n)

// ------------------ Recursion ---------------
int josephus(int n, int k){
    if(n==1){
        return 1;
    }

    return ((josephus(n-1,k)+k-1)%n)+1;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)

// ------------------- Iterative Version -------------------
int josephus(int n, int k){
    int ans = 1, i = 2;
    while(i <= n){
        ans = (ans + k-1) % i + 1;
        i++;
    }

    return ans;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

int main(){
    cout << josephus(5,2);
}