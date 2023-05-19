#include <iostream>
#include <climits>
using namespace std;

int pow(int a, int b)
{
    int res = 1;
    while(b>0){
        // This will be true at last, b == 1
        // Thus, product of all the 'a' calculated will be multiplied to res
        if(b&1){
            res = res*a;
        }
        a = (a*a);
        b = b >> 1;
    }
    return res;

    // In case of b = odd, res = res*a will happen, then b/2 = even thus normal would follow
}

// Time Complexity: O(log(b))
// Auxiliary space: O(1)

// --------------------------- RECURSIVELY ---------------------------

// 1.
int pow(int a, int b, int res=1){
    if(b==0){
        return res;
    }

    if(b&1){
        res = res * a;
    }
    return pow(a*a, b>>1, res);
}

// 2.
int pow(int a, int b){
    if(b==0){
        return 1;
    }

    int ans = pow(a, b / 2);

    if(b&1){
        return a * ans * ans;
    }
    else{
        return ans * ans;
    }
}

// Time Complexity: O(log(b))
// Auxiliary space: O(log(b))

// Modular exponentiation
int modPow(int x, int n, int m) {
    int ans = 1;
    
    while(n){
        if(n&1){
            ans = (1LL * ans*(x%m))%m;
        }

        x = (1LL * (x%m)*(x%m))%m;
        n >>= 1;
    }
    return ans;
}

// Time Complexity: O(log(n))
// Auxiliary space: O(1)

int main(){
    cout << pow(9, 12);
    cout << modPow(773,39, INT_MAX);
}