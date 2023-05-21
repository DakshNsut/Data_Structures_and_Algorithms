#include <iostream>
#include <unordered_map>
using namespace std;

// Majority Element in an array
// A majority element in an array is an element that appears more than n/2 times

void majority_element(int arr[], int n){
    // Hashing frequency of each element in map
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
        m[arr[i]]++;

    // Checking each element for frequency > n/2
    for(auto e : m){
        if(e.second > n/2){
            cout << "Majority element is: " << e.first << endl;
            return;
        }
    }

    // if the program reached this line means no majority element was found
    cout << "No Majority element" << endl;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// --------------- Moore Voting Algorithm -------------------
int majority_element(int arr[], int n){
    int ans = 0;
    int count = 1;

    // Finding a possible majority element
    for(int i=1; i<n; i++){
        if(arr[i] == arr[ans]) count++;
        else{
            // Since other element came its vote decreased
            count --;
            if(count == 0){
                ans = i;
                count = 1;
            }
        }
    }

    // Final check on the final candidate for majority element
    count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == arr[ans]) count++;
    }

    if(count > n/2) return arr[ans];
    else return -1;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    majority_element(arr, n);
}