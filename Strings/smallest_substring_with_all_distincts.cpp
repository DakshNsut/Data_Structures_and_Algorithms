#include <iostream>
#include <unordered_map>
using namespace std;

// to find a smallest substring containing all distinct characters

int findSubString(string s){
    int n = s.size();
    unordered_map<char,int> m;
    for(int i=0; i<n; i++){
        m[s[i]]++;
    }
        
    int dis = m.size(); // Total number of distinct characters
    int count = 0; // Count of distinct characters in the current Window
    m.clear();

    int head = -1, tail = 0, ans = n;
    while(tail+1<n && head+1<n){
        while(head+1<n && count<dis){
            m[s[++head]]++;
            // a new element is added
            if(m[s[head]] == 1){
                count++;
            }
        }
        if(count == dis){
            ans = min(ans,head-tail+1);
        }
        while(tail<=head && count==dis){
            m[s[tail]]--;
            if(m[s[tail]] == 0){
                count--;
            }
            tail++;
            if(count==dis){
                ans = min(ans,head-tail+1);
            }
        }
    }
    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    cout << findSubString("AABBBCBBAC");
    return 0;
}