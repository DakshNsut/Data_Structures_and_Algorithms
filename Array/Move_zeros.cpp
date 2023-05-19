#include <iostream>
#include <vector>
using namespace std;

// move all zeroes to the end

void printVector(vector<int> a){
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void move_zeros(vector<int> &a){
    int i = 0;
    int j = 0;
    int n = a.size();

    while(i < n){
        while(a[i] == 0 && i<n){
            i++;
        }
        if(i < n){
            swap(a[j], a[i]);
            j++;
            i++;
        }
    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

int main(){
    vector<int> a = {0,1,0,2,12,3};

    move_zeros(a);
    printVector(a);
}