#include <iostream>
using namespace std;

// SET the UNSET BITS IN X WHICH ARE SET IN Y in range L to R

// ---------- Method 1 ------------
int setSetBit(int x, int y, int l, int r){
    int i = l;
    int a = x >> (l-1); // starting from Lth bit
    int b = y >> (l-1); // strating from Lth bit
    while(b){
        int bitx = a&1;
        int bity = b&1;
        if(bitx == 0 && bity == 1){
            x |= 1<<(i-1);
        }
        i++;
        if(i == r+1){
            break;
        }
        a >>= 1;
        b >>= 1;
    }
    return x;
}

// Time Complexity: O(log(y))
// Auxiliary space: O(1)

// --------------- Method 2 ---------------
int setSetBit(int x, int y, int l, int r){
    long long mask = ((1ll << (r-l+1)-1) << (l-1) ) & y;
    x |= mask;
    return x;
}

// Time Complexity: O(1)
// Auxiliary space: O(1)

int main(){
    // for method-1
    // rightmost bit is index = 1, the index increase right to left
    // l and r are index of the bits
    cout << setSetBit(8, 3, 1, 2);

    // for method-2
    // rightmost bit is index = 0, the index increase right to left
    // l and r are index of the bits
    cout << setSetBit(8, 3, 1, 2);
    return 0;
}