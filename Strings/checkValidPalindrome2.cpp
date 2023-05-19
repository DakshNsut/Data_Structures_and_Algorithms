#include<iostream>
using namespace std;

// given a string check if it is a palindrome, ignore characters other than alphabets and numbers
// also convert upper case letters to lower case ones and then check

bool checkpal(string str){
    int s = 0;
    int e = str.size()-1;

    while(s<e){
        if(str[s] != str[e]){
            return 0;
        }
        s++;
        e--;
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

bool valid(char ch){
    if( (ch>='a' && ch<='z') || (ch>='0' && ch<='9') ){
        return true;
    }
    return false;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    string s;
    cout<<"Enter the string"<<" ";
    // s = "5?36@6?35";
    // s = "A man, a plan, a canal: Panama";
    // s = "race a car";
    getline(cin, s);

    tolower(s);
    cout << s << endl;

    string temp = "";
    for(char i: s){
        if(valid(i)){
            temp.push_back(i);
        }
    }

    cout << temp << endl;

    if(checkpal(temp)){
        cout << "Yes!!";
    }
    else{
        cout << "No:(";
    }
}