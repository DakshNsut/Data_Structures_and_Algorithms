#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ----------- Naive approach -----------
bool find_sum0_subarray(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i<n; i++){
        int sum = arr[i];
        for(int j = i+1; j<n; j++){
            sum += (arr[j]);
        }
        if(sum == 0){
            return true;
        }
    }
    return false;
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// ------------- Optimal approach -------------
bool find_sum0_subarray(vector<int> &arr){
    int n = arr.size();
    unordered_map<int,bool> m;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum==0 || m[sum] == true){
            return true;
        }
        m[sum] = true;
    }
    return false;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

void print(vector<int> &num){
    for(int i: num){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> num = {1, 2, 3, 6, -5, -4};
    cout << find_sum0_subarray(num); // subarray: {3,6,-5,-4} with sum zero exists
    return 0;
}