#include<unordered_map>
#include<vector>
using namespace std;

// to check if no duplicate elements are present in array

int main(){
    int arr[] = {-1,-1,2,3,3,3};

    unordered_map<int,int> m;
    for(auto it: arr)
        m[it]++;
    
    for (auto it: m)
    {
        int sec = it.second;
        for(auto i:m){
            if(i.second == sec && i!=it){
                cout << "false";
                break;
            }
        }
        cout << "true";
        break;
    }
}

// Time complexity: O(n) 
// Auxiliary Space: O(n)