#include <iostream>
#include <vector>
using namespace std;

// to find kth permutation of string with sequence 1 to n.

void kthPermutation(int n, int k){
    k--;
    vector<int> numbers;
    int fact = 1; // This is where factorial of (n-1) will be calculated

    int i = 1;
    while(i < n){
        fact *= i;
        numbers.push_back(i);
        i++;
    }
    numbers.push_back(n);

    i = 0;
    string ans;
    while(1){
        int ind = k/fact;
        ans += to_string(numbers[ind]);
        numbers.erase(numbers.begin() + (ind));
        if(i == n-1) break;
        k = k % fact;
        fact = fact / (n-1-i);
        i++;
    }

    cout << ans << endl;
}

// Time Complexity : O(n^2) 
// Auxiliary Space : O(n) 

int main(){
    kthPermutation(3,4);
    return 0;
}