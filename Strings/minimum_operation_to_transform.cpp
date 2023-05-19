#include <iostream>
using namespace std;

// find minimum operations to transform one string to other
// operation is to pick a character and put it at front

int transform (string A, string B){
    int n = A.size();
    if(n != B.size()) return -1;
    
    int i =n-1, j=n-1, countSteps=0;
    int CharsAtBack[256] = {0}; // List of characters in A string not matching and thus have to be pushed at back
    while(i>=0 && j>=0){
        if(A[i] == B[j]){
            i--; j--;
        }
        else{
            countSteps++;
            CharsAtBack[A[i--]]++;
        }
    }

    // This is done to check all characters B[j] which are left to be checked if they are present at back of string A
    if(i==-1 && j!=-1){
        while(j>=0){
            // Just check if it is present, if yes then we can do any arrangement to match it with the required arrangement
            if(CharsAtBack[B[j]]){
                CharsAtBack[B[j--]]--;
            }
            else{
                return -1;
            }
        }
    }

    return countSteps;
}

// Time Complexity : O(n)
// Auxiliary Space : O(1)

int main(){
    cout << transform("EACBD", "EABCD");
    return 0;
}