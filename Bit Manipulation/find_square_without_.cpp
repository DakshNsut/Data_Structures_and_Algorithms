#include <iostream>
using namespace std;

// Finding square of a number without *,/,%

// ----------- Method 1 --------------
int square (int n){
    int ans = 0;
    for(int i =1; i<=n; i++){
        ans += n;
    }
    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// --------------- Method 2 -------------
int square(int n){
    // Base Case
    if(n == 0) return 0;
    // Handling negative input
    n = n < 0 ? -n : n;
    int x = n >> 1;
    if(n&1){
        // 4 * square(n/2) + 4 * (n/2) + 1
        return (square(x) << 2) + (x << 2) + 1;
    }
    else{
        // 4 * square(n/2)
        return square(x) << 2;
    }
}

// Time Complexity: O(logn)
// Auxiliary space: O(logn)

// -------------- Method 3 ---------------
int square(int n){
    // for handling negative input
    n = n < 0 ? -n : n;
    int temp = n;
    int ans = 0;
    int power = 0;
    while(temp){
        if(temp & 1){
            // ans += (n * 2^power);
            ans = ans + (n << power);
        }
        power ++;
        temp >>= 1;
    }
    return ans;
}

// Time Complexity: O(logn)
// Auxiliary space: O(1)

int main(){
    cout << square(9);
    return 0;
}