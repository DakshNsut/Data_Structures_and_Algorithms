#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// to find if a2 is a subset of a1

string isSubset(int a1[], int a2[], int n, int m) {
    if(m > n){
        return "No";
    }

    unordered_map<int,int> find;
    for(int i=0; i<n; i++){
        find[a1[i]]++;
    }

    for(int i=0; i<m; i++){
        if(find[a2[i]] == 0){
            return "No";
        }
        else{
            find[a2[i]]--;
        }
    }
    return "Yes";
}

int main(){
    int a1[] = {1,2,3,4,5,6};
    int a2[] = {3,6};
    int n = sizeof(a1)/sizeof(a1[0]);
    int m = sizeof(a2)/sizeof(a2[0]);
    cout << isSubset(a1,a2, n, m);
    return 0;
}

// Time complexity: O(n) 
// Auxiliary Space: O(n)