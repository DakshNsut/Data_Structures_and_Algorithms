#include<iostream>
using namespace std;

// ----------------------- Method-1 ----------------------------------------
void swap(char &ch1 , char &ch2){
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

void reverse(string &str , unsigned int s, unsigned int e){
    int start = s;
    int end = e;

    while(start<end){
        swap(str[start],str[end]);
        start++;end--;
    }
}

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    cout<<str<<endl;

    // Reverse the whole string
    reverse(str,0,str.length()-1);
    cout<<str<<endl;

    // The start of the word
    unsigned int s = 0;
    unsigned int e = 0;

    while(s<str.size()){
        // Finding the end of word
        int i = s;
        while(str[i] != ' ' && i<str.size()){
            i++;
        }
        e = i-1;

        // Reversing the word
        reverse(str,s,e);

        s = e+2;
    }
    
    cout<<str;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// --------------------------- Method-2 --------------------------------------
#include<iostream>
#include<vector>
using namespace std;

void swap(string &str1 , string &str2){
    string temp = str1;
    str1 = str2;
    str2 = temp;
}

void reverse_vector(vector<string> &vecstr , unsigned int start, unsigned int end){

    while(start<end){
        swap(vecstr[start],vecstr[end]);
        start++;end--;
    }

}

void reverse_pos_word(string & str){

    // Creating vector of word in the string
    vector<string> vecstr;
    string temp;
    for (int i = 0; i < str.length(); i++){
        if(str[i]==' '){
            vecstr.push_back(temp);
            temp.clear();
        }
        else{
            temp+=str[i];
        }
    }

    if(temp !=""){
        vecstr.push_back(temp);
        temp.clear();
    }

    // Reverse the whole string
    reverse_vector(vecstr,0,vecstr.size()-1);
    
    str.clear();
    for(int i=0; i< vecstr.size(); i++){
        str+=vecstr[i];
        if(i!=vecstr.size()-1){
            str+=" ";
        }
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<str<<endl;
    reverse_pos_word(str);
    cout<<str;
}