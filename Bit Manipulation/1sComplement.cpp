#include<iostream>
using namespace std;

// to find 1's complement of a number

int main(){
    int n;
    cin >> n;

    int m = n;
    int mask = 0;

    if(n == 0){
        cout << 1;
    }

    while(m){
        mask = (mask << 1) | 1;
        m = m >> 1;
    }

    int ans = (~n) & mask;
    cout << ans;
}