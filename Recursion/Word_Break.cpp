#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void word_break(string str, vector<string> &dict, vector<string> &ans, string &result){
    if(str.size() == 0){
        ans.push_back(result);
        result = "";
        return;
    }

    int n = str.length();

    for(int i=0; i<n; i++){
        string left = str.substr(0,i+1);
        vector<string>::iterator it = find(dict.begin(), dict.end(), left);
        if(it != dict.end()){
            result.append(left);
            result.push_back(' ');
            string right = str.substr(i+1);
            word_break(right, dict, ans, result);

            // after this we go to the next interation of the loop, adding one more character to the string
            // because even if we found one we can get a word starting from that string
        }
    }
}

// Time Complexity: O(2^n)
// Auxiliary space: O(n)

int main(){
    vector<string> dictionary = {"mobile","samsung","sam","sung", "man","mango","icecream","and", "go","i","like","ice","cream"};
    string s = "ilikesamsung";
    vector<string> ans;
    string res;
    word_break(s, dictionary, ans, res);
    for(string t : ans) cout << t << " ";

    cout << endl;

    s = "ilikelikeimangoiii";
    ans.clear();
    res = "";
    word_break(s, dictionary, ans, res);
    for(string t : ans) cout << t << " ";

    return 0;
}