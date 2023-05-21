#include <iostream>
#include <unordered_map>
using namespace std;

// to find the minimum number of group flips required to convert a given binary array into an array that either contains all 1s or
// all 0s. A group flip is defined as flipping a continuous sequence of elements in the array.

void minimum_group_flips(string &arr){
    char prev; // to store the last character seen
    int res = 0; // to store the number of consecutive groups seen
    int n = arr.size();

    for(int i=0; i<n; i++){
        if(prev != arr[i]) res++;
        prev = arr[i];
    }

    cout << "Minimum number of group flips required is: " << res/2 << endl;
}

int main(){
    string arr = "110001";
    minimum_group_flips(arr);
}