#include <iostream>
#include <climits>
#include <queue>
using namespace std;

// rearrange duplicate adjacent characters so that they are not adjacent

// ------------------- Method-1 --------------------
char findMaxOccuringChar(string &str, int count[]){
    char maxChar;
    int maxFreq = INT_MIN;
    for(int i=0; i<26; i++){
        if(count[i] > maxFreq){
            maxFreq = count[i];
            maxChar = i + 'a';
        }
    }
    return maxChar;
}

string rearrangeString(string str)
{
    int n = str.size();
    int count[26] = {0};
    string res(n,'a');
        
    // Count frequency of each character in the string
    for(int i=0; i<n; i++){
        count[str[i]-'a']++;
    }
        
    char ch = findMaxOccuringChar(str,count);
    int maxCount = count[ch-'a'];

    // if count of maxOccuringCharacter is more than the number of even positions
    if(maxCount > (n+1)/2){
        return "-1";
    }

    // Placing max frequency character at even indices
    int ind = 0;
    while(count[ch-'a']!=0){
        res[ind] = ch;
        count[ch-'a']--;
        ind+=2;
    }
        
    for(int i=0; i<26; i++){
        while(count[i]!=0){
            ind = (ind>=n) ? 1 : ind;
            res[ind] = i + 'a';
            ind += 2;
            count[i]--;
        }
    }
    return res;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

// -------------------- Method-2 ----------------------
struct Key{
    int freq;
    char ch;

    bool operator < (const Key&k) const{
        return freq<k.freq;
    }
};

string rearrangeString(string str){
    int n = str.size();
    int count[26] = {0};
    for(int i=0; i<n; i++){
        count[str[i]-'a']++;
    }
    
    // Adding all characters with frequency in pq
    priority_queue<Key> pq;
    for(char ch='a'; ch<='z'; ch++){
        if(count[ch-'a']!=0){
            pq.push(Key{count[ch-'a'],ch});
        }
    }

    string ans;
    Key prev{-1,'#'};
    while(!pq.empty()){
        Key k = pq.top();
        pq.pop();
        ans += (k.ch);
            
        if(prev.freq > 0){
            pq.push(prev);
        }
        (k.freq)--;
        prev = k;
    }

    if(ans.size() != n){
        return "-1";
    }
    return ans;
}

// Time Complexity: O(n*log(n))
// Auxiliary Space: O(n)

int main(){
    cout << rearrangeString("aabbdee");
    return 0;
}