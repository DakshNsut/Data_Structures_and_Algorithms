#include<iostream>
#include<vector>
using namespace std;

// to search in a sorted and rotated array

int main(){
    vector<int> arr = {5,6,1,2,3,4};
    int key = 4;

    int s = 0;
    int e = arr.size()-1;
    bool flag = 0;

    while(s<=e){
        int mid = s + (e-s)/2;

        if (arr[mid] == key) {
            cout << "Found at " << mid;
            flag = 1;
            break;
        }

        else if(arr[s]<arr[mid]){
            if(key>=arr[s] && key<=arr[mid-1]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        // when arr[s] == arr[mid] --> s==mid thus, element can be found at right side because mid is already checked.
        else{
            if(key>=arr[mid+1] && key<=arr[e]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    }

    if(!flag) cout << -1;
}

// Time Complexity: O(logn)
// Auxiliary Space: O(1)