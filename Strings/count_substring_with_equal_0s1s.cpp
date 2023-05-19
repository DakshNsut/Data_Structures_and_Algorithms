#include <iostream>
#include <stack>
using namespace std;

// return max count of substrings starting from 0th index with equal number of 0's and 1's

// --------------- Method - 1 ------------------
int countSubstrings(string str){
    int n = str.size();
    int ansCount = 0;
    char curr = str[0];
    int currCount = 0;

    for(int i=0; i<n; i++){
        if(str[i] == curr){
            currCount++;
        }
        else{
            currCount--;
            if(currCount == 0){
                ansCount++;
                curr = str[i+1];
                currCount = 0;
            }
        }
    }

    // This means i was expecting to get a subarray with equal 0's and 1's but couldn't.
    if(currCount != 0){
        return -1;
    }
    return ansCount;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// ----------------------- Method - 2 ----------------------
int countSubstrings(string str){
    int n=str.length();
    int count0=0;
    int count1=0;
    int cnt=0;
    
    stack<int> st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(str[i]);
            count1++;
        }
        else if(str[i]!=st.top()){
            st.pop();
            count0++;
        }
        else{
            st.push(str[i]);
            count1++;
        }
        if(count0==count1)
            cnt++;
    }

    if(count0!=count1)
        return -1;
    else return cnt;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    cout << countSubstrings("010011");
    return 0;
}