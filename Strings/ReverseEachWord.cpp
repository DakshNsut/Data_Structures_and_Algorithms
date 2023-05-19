#include<iostream>
using namespace std;

void swap(char &ch1 , char &ch2){
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

void reverse_word(string &str , unsigned int s, unsigned int e){
    int start = s;
    int end = e;

    while(start<end){
        swap(str[start],str[end]);
        start++;end--;
    }
}

int main(){
    string str;
    cout << "Enter the string: ";
    getline(cin,str);
    cout << str << endl;

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
        reverse_word(str,s,e);

        s = e+2;
    }
    
    cout << str;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)