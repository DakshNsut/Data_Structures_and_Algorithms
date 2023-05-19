#include<iostream>
#include<vector>
using namespace std;

// To check if S1 is a permutation of S2

bool solve(string &s2, string &s1){
    vector<int>count1(26,0);
    for (char c: s1){
        count1[c-'a']++;
    }

    int s = 0;
    int e = s1.length()-1;

    vector<int>count2(26,0);
    for (int i=s; i<=e; i++){
        count2[s2[i]-'a']++;
    }

    while(e < s2.length()){
        if(count1 == count2){
            return true;
        }

        else{
            count2[s2[s]-'a']--;
            s++;
            e++;
            count2[s2[e]-'a']++;
        }
    }

    return  false;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    string s2;
    cout<<"Enter the string s2: ";
    getline(cin,s2);

    string s1;
    cout<<"Enter the string s1: ";
    getline(cin,s1);

    if(solve(s2,s1)) cout << "Yes!";
    else cout << "No";
}