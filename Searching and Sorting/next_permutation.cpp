#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int> &num, int s, int e){
    while(s<e){
        swap(num[s],num[e]);
        s++; e--;
    }
}

void nextPermutation(vector<int>& num){
    int n = num.size();
    if(n == 0 || n == 1){
        return;
    }

    int i = n - 2;
    while(i>=0 && num[i]>=num[i+1]) i--;
    if(i>=0){
        int j = n-1;
        while(num[j]<=num[i]) j--;
        swap(num[i],num[j]);
    }
    reverse(num,i+1,n-1);
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)

void print(vector<int> &num){
    for(int i: num){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> num = {1, 2, 3, 6, 5, 4};
    nextPermutation(num);
    print(num);
}