#include <iostream>
using namespace std;

void sayDigits(int n, string arr[]){
    if(n==0){
        return;
    }

    int digit = n%10;
    n /= 10;
    sayDigits(n, arr);
    cout << arr[digit] << " ";
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayDigits(100, arr);
    return 0;
}