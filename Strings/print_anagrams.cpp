#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// -------------------- Method-1 -------------------
struct Key{
    string s;
    int index;
    bool operator < (const Key &k) const{
        return s.compare(k.s)<0;
    }
};

bool cmpByCol(const vector<string> &v1, const vector<string> &v2){
    return (v1[0]).compare(v2[0])>0;
}
    
vector<vector<string> > PrintAnagrams(vector<string>& string_list) {
    int n = string_list.size();

    // Sorting each string into a temp array
    vector<string> tempS = string_list;
    for(int i=0; i<n; i++){
        sort(tempS[i].begin(),tempS[i].end());
    }

    priority_queue<Key> pq;
    for(int i=0; i<n; i++){
        pq.push(Key{tempS[i],i});
    }

    Key prev = {"#",-1};
    vector<string> v;
    vector<vector<string>> ans;
    while(!pq.empty()){
        Key k = pq.top();
        pq.pop();
        if(prev.index >= 0){
            if(prev.s == k.s){
                v.push_back(string_list[k.index]);
                continue;
            }
            else{
                ans.push_back(v);
                v.clear();
                prev = {"#",-1};
            }
        }
        prev = k;
        v.push_back(string_list[k.index]);
    }
    if(!v.empty()){
        ans.push_back(v);
    }

    int r = ans.size();
    for(int i=0; i<r; i++){
        sort(ans[i].begin(),ans[i].end());
    }
    return ans;
}

// Time Complexity: O(n^2 * log(n))
// Auxiliary Space: O(n)

// ------------------- Method-2 ----------------------

void mentionPresence(string &str, bool pr[]){
    int n = str.size();
    for(int i=0; i<n; i++){
        pr[str[i]-'a']++;
    }
}

bool CheckEqualPresence(bool* pr1, bool *pr2){
    for(int i=0; i<26; i++){
        if(pr1[i]!=pr2[i]){
            return 0;
        }
    }
    return 1;
}

vector<vector<string>> PrintAnagrams(vector<string> &w){
    int n = w.size();
    vector<vector<string>> ans;
    for(int i=0; i<n; i++){
        bool present1[26] = {0};
        vector<string> v;
        if(w[i].empty()) continue;
        v.push_back(w[i]);
        mentionPresence(w[i],present1);
        for(int j=i+1;j<n; j++){
            bool present2[26] = {0};
            mentionPresence(w[j],present2);
            if(CheckEqualPresence(present1,present2)){
                v.push_back(w[j]);
                w[j] = "";
            }
        }
        ans.push_back(v);
    }

    return ans;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(1)

// ------------------- Method-3 ----------------------

vector<vector<string>> PrintAnagrams(vector<string>& string_list) {
    int n = string_list.size();
    vector<vector<string> > ans;

    // Sorting each string into a temp array
    vector<string> tempS = string_list;
    for(int i=0; i<n; i++){
        sort(tempS[i].begin(),tempS[i].end());
    }

    vector<pair<string,int>> v;
    for(int i=0; i<n; i++){
        v.push_back(make_pair(tempS[i],i));
    }

    sort(v.begin(),v.end());
        
    vector<string> VS;
    string prev;
    for(int i=0; i<n; i++){
        if(prev.empty() || prev == v[i].first){
            int ind = v[i].second;
            VS.push_back(string_list[ind]);
            prev = v[i].first;
        }
        else if(prev != v[i].first){
            ans.push_back(VS);
            VS.clear();
            prev.clear();
            i--;
        }
    }

    if(!VS.empty()){
        ans.push_back(VS);
    }
    return ans;
}

// Time Complexity: O(n*log(n))
// Auxiliary Space: O(n)

int main(){
    vector<string> words = {"on","no","is","tac","cat","atc"};
    vector<vector<string>> res = PrintAnagrams(words);

    for(vector<string> &v: res){
        for(string s:v){
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}