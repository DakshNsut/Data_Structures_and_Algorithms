#include <iostream>
using namespace std;

// ---------------- Recursively ----------------
string countAndSay(int n) {
    if(n==1)
        return "1";

    string prevSay = countAndSay(n-1);
    int size = prevSay.size();

    char currEle = prevSay[0]; // The current element whose frequency is being counted
    int currCount = 0; // Frequency count of current element
    string result;
    for(int i=0; i<size; i++){
        if(prevSay[i] == currEle)
            currCount++;
        else{
            result.append(to_string(currCount));
            result.push_back(currEle);
            currEle = prevSay[i];
            currCount = 1;
        }
    }
    result.append(to_string(currCount));
    result.push_back(currEle);
    return result;
}
// T(n) = O(n^2)
// S(n) = O(n)

// ------------------- Iteratively ----------------------
string countAndSay(int n){
    string ans = "1"; // This stores the count and say result of (n-1) the previous number

    for(int i=2; i<=n; i++){
        string result; // Result of count and say for this iteration
        char currEle = ans[0]; // The current element whose frequency is being counted
        int currCount = 0; // Frequency count of current element

        for(int j=0; j<ans.size(); j++){
            if(ans[j] == currEle)
                currCount++;
            if(ans[j] != currEle){
                result.append(to_string(currCount));
                result.push_back(currEle);
                currEle = ans[j];
                currCount = 1;
            }
        }
        result.append(to_string(currCount));
        result.push_back(currEle);

        ans=result;
        // If i go to next iteration this result would become result of previous number, hence it is stored in ans.
    }
    return ans;
}
// T(n) = O(n^2)
// S(n) = O(1)

int main(){
    cout << countAndSay(3) << endl;
    cout << countAndSay(5);
    return 0;
}