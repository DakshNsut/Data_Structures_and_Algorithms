#include <iostream>
#include <climits>
using namespace std;

// --------------------- PRECISE RESULT USING AN ARRAY---------------------
#define MAX 500

int multiply(int x, int res[], int res_size){
    int carry = 0;
    int prod = -1;
    for (int i = 0; i < res_size; i++){
        prod = res[i] * x + carry;

        res[i] = prod % 10;
        carry = prod / 10;
    }
    
    while(carry){
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }

    return res_size;
}

int factorial(int n){
    int res[MAX];

    // Intialize result to be = 1
    res[0] = 1;
    int res_size = 1;

    // n! = 2.3.4.5.6.7 .... n
    for (int i = 2; i <= n; i++){
        // Its size has to be rechecked because carry value at the last digit will be carried to the next digit 
        // and that would increase the size of result
        res_size = multiply(i, res, res_size);
    }

    for (int i = res_size - 1; i >= 0; i--){
        cout << res[i] << "";
    }
    cout << endl;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// --------------------- RESULT USING MOD 1e9+7---------------------

#define ull unsigned long long
#define mod 1000000007

ull fact(int n){
    if(n==0 || n==1){
        return 1;
    }

    ull res = 1;
    for (int i = 2; i <= n; i++){
        if(n < INT_MAX){
            res = ( res * (i) % mod ) % mod;
        }
    }

    return res;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << fact(n);
    factorial(100);
}