#include<iostream>
#include<vector>
using namespace std;

// find all duplicates in an array

vector<int> all_duplicates (vector<int> & arr){
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i])-1;
        if(arr[index] < 0){
            ans.push_back(abs(arr[i]));
        }
        arr[index]*=-1;
    }

    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    vector<int> v;
    v = {4,3,2,7,8,2,3,1};

    for(int i: all_duplicates(v)){
        cout << i << " ";
    }

}