#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// smallest window of string s that contains all characters (with occurence) of string p

string smallestWindow (string s, string p)
{
    int m = p.size();
    int n = s.size();
    if(m>n) return "-1";
    int pat_map[256] = {0};
    for(int i=0; i<m; i++){
        pat_map[p[i]]++;
    }

    int txt_map[256] = {0};
    int count = 0;
    int tail = 0;
    int ans = INT_MAX;
    int start = -1; // start and end of the answer substring
    for(int head = 0; head<n; head++){
        txt_map[s[head]]++;
        if(pat_map[s[head]]>0 && txt_map[s[head]]<=pat_map[s[head]]){
            count++;
        }
        if(count == m){
            // Minimize this substring to get minimum result
            // Either the character present should not be present, or it number of occurence is more than what is expected
            while(pat_map[s[tail]] == 0 || txt_map[s[tail]] > pat_map[s[tail]]){
                    txt_map[s[tail]]--;
                tail++;
            }

            // Store this length if it is lesser
            int len = head-tail+1;
            if(ans > len){
                ans = len;
                start = tail;
            }
        }
    }

    if(start == -1) return "-1";
    string res = s.substr(start,ans);
    return res;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    cout << smallestWindow("this is a test string", "tist");
    return 0;
}