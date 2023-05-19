#include <iostream>
using namespace std;

// count perfect squares less than n

// ----------------------------- Method-1 --------------------------
    int sqrt(int n){
        int l = 1, h = n/2, mid, ans = 0;
        while(l<=h){
            mid = (l+h)/2;
            unsigned long long int sqr = mid*mid; // EVEN IN unsigned long long it gives overflow result, -ve . Thus, use O(root(n)) solution
            if(sqr == n){
                return mid;
            }
            else if (sqr > n){
                h = mid-1;
            }
            else {
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }

int countSquares(int N) {
    return sqrt(N-1);
}

// Time Complexity: O(logn)
// Auxiliary space: O(1)

// ---------------------------- Method-2 -----------------------
int sqrt(int n){
    if(n==0 || n==1){
        return n;
    }

    int ans;
    for(int i=1; i*i<=n; i++){
        ans = i;
    }
    return ans;
}

int countSquares(int N) {
    return sqrt(N-1);
}

// Time Complexity: O(root(n))
// Auxiliary space: O(1)

int main(){
    cout << countSquares(9) << endl;
    cout << countSquares(19);
    return 0;
}