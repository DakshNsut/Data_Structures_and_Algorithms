#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,string> m = {{2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqr"}, {8,"stw"}, {9,"xyz"}};

void combinations(string str, int index, string curr, vector<string> &ans, int n){
    if(index == n){
        ans.push_back(curr);
        return;
    }

    string pattern = m[int(str[index])-48];
    combinations(str, index+1, curr+pattern[0], ans, n);
    combinations(str, index+1, curr+pattern[1], ans, n);
    combinations(str, index+1, curr+pattern[2], ans, n);
}

// Time Complexity: O(4^n)
// Auxiliary Space: O(n)

int main(){
    string str;
    cout << "Enter a number containing digits 2 to 9: ";
    getline(cin, str);
    int n = str.size();

    int index = 0;
    string curr;
    vector<string> ans;
    combinations(str, index, curr, ans, n);

    for(string s:ans){
        cout << s << " ";
    }
    cout<<endl;

    return 0;
}

// ------------------ Another variation --------------------
// Given a sentence in the form of a string, convert it into its equivalent mobile
// numeric keypad sequence.

unordered_map<string,int> m = {{"ABC",2},{"DEF",3},{"GHI",4},{"JKL",5},{"MNO",6},{"PQRS",7},{"TUV",8},{"WXYZ",9}};
int findValue(char ch){
    for(auto it = m.begin(); it!=m.end(); it++){
        string first = it->first;
        if(first.find(ch) != string::npos){
            return it->second;
        }
    }
    return 0;
}

int dial(string &str){
    int res = 0;
    int n = str.size();
    for(int i=0; i<n; i++){
        int val = findValue(str[i]);
        res = res* 10 + val;
    }
    return res;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    cout << "Enter string of capital letters only: ";
    string s;
    getline(cin, s);
    cout << dial(s);
    return 0;
}

// ------------------- Third variation -----------------
// Given a sentence in the form of a string, convert it into its equivalent mobile
// numeric keypad sequence. Each letter corresponds to each number the number of times equal to its position.

string dial(string &str, vector<int> &m){
    string res;
    int n = str.size();
    for(int i=0; i<n; i++){
        int pos = str[i] - 'A';
        res.append(to_string(m[pos]));
    }
    return res;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    vector<int> m = {2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999};
    cout << "Enter string of capital letters only: ";
    string str;
    getline(cin,str);
    cout << dial(str,m) << endl;
    return 0;
}
