#include<iostream>
using namespace std;

// given a string check if it is a palindrome, ignore characters other than alphabets
// also convert upper case letters to lower case ones and then check

bool checkpal(string str){
    int s = 0;
    int e = str.size()-1;

    while(s<e){
        if(str[s]>='a' && str[s]<='z'&& str[e]>='a' && str[e]<='z'){
            if(str[s] != str[e]){
                return 0;
            }
            s++;
            e--;
        }
        else{
            if(str[s]<'a' || str[s]>'z'){
                s++;
            }
            else if (str[e]<'a' || str[e]>'z'){
                e--;
            }
        }
    }
    return 1;
}

void tolower(string &str){
    for(int i = 0; i<str.size() ; i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i] += 32;
        }
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    string s;
    cout << "Enter the string" << " ";
    // s = "5?36@6?35";
    getline(cin, s);
    tolower(s);
    if(checkpal(s)){
        cout << "Yes!!";
    }
    else{
        cout << "No:(";
    }
}