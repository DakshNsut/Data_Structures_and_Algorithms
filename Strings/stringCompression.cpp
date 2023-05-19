#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char> &chars){
    int i = 0;
    int al = 0; // ansLength
    while(i<chars.size()){
        int j = i+1;

        while(j<chars.size() && chars[i] == chars[j])
        {
            j++;
        }

        chars[al++] = chars[i];

        int count = j-i;
        if(count>1){
            string cnt = to_string(count);

            for(char ch : cnt){
                chars[al++] = ch;
            }
        }

        i=j;
    }

    return al;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    vector<char> v = {'a', 'a', 'b', 'c', 'a'};
    cout << "Length of compressed string is: " << compress(v) << endl;
    cout << "Compressed string is: ";
    for(char &ch : v) cout << ch << " ";
}