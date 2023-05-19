#include <iostream>
#include <vector>
using namespace std;

// find element having duplicate in the array
// the array must have aal values less than size, and not equal to 0

int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow!=fast);

    slow = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
        
    return slow;
}

void print(vector<int> &arr){
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    vector<int> arr = {1,3,4,3};
    cout << findDuplicate(arr);
    return 0;
}