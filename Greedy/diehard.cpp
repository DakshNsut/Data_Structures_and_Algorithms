#include <iostream>
using namespace std;

// -------------- DIEHARD(SPOJ problem) ---------------------

void calculateTimeSurvived(int h, int a){
    int ans = 0;
    bool air = 0, water = 0, fire = 0;
    while(1){
        if(!air && h+3>0 && a+2>0){
            h += 3; a += 2;
            // re-initializing place
            air = 0, water = 0, fire = 0;
            air = 1;
            ans++; // increment time survived
        }
        else if(!water && h-5>0 && a-10>0){
            h -= 5; a -= 10;
            // re-initializing place
            air = 0, water = 0, fire = 0;
            water = 1;
            ans++; // increment time survived
        }
        else if(!fire && h-20>0 && a+5>0){
            h -= 20; a += 5;
            // re-initializing place
            air = 0, water = 0, fire = 0;
            fire = 1;
            ans++; // increment time survived
        }
        else break;
    }
    cout << ans  << endl;
}

int main(){
    int t;
    cin >> t;
    while(t){
        int H, A;
        cin >> H >> A;
        calculateTimeSurvived(H,A);
        t--;
    }
    return 0;
}