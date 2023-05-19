#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// to find the longest subsequence of consecutive elements
// consecutive means 1,2,3,4 or 5,6,7,8,9

int find_subsequence(vector<int> &arr){
    int N = arr.size();

    // Storing values in a map
    unordered_map<int,bool> m;
    for(int i=0; i<N; i++){
        m[arr[i]] = true;
    }

    int maxlen = 1; // why 1? because single element is consecutive
    for(int i=0; i<N; i++){
        // If it is not the starting point of the consecutive subsequence
        if(!m[arr[i]-1]){
            int j = arr[i];
            // Finding the extent of consecutive subsequence
            while(m[j]){
                j++;
            }
            // Finding length of current consecutive subsequence and storing the maximum of them
            maxlen = max(maxlen,j-arr[i]);
        }
    }
    return maxlen;
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
    vector<int> arr = {1, 2, 3, 6, -5, -4};
    cout << find_subsequence(arr); // the required subsequence is "1 2 3", len = 3.
    return 0;
}