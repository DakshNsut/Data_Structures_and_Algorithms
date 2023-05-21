#include <iostream>
using namespace std;

// Check if x is a power of a

bool checkPower(int x, int a){
    if(x == 0 && a != 0) return 0;
    if(x != 0 && a == 0) return 0;
    if(x == 0 && a == 0) return 1;

    while(x != 1){
        if(x % a != 0) return 0;
        x /= a;
    }
    return 1;
}

int main(){
    cout << (checkPower(8, 2) ? "Yes" : "No") << endl;
    cout << (checkPower(0, 0) ? "Yes" : "No") << endl;
    cout << (checkPower(8, 0) ? "Yes" : "No");
    return 0;
}