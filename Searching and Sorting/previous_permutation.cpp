#include <iostream>
#include <algorithm>
using namespace std;

// --------------------- Method-1 -------------------
void prevPermutation(string &s){
    int n = s.size();
    int x = -1;
    for(int j=n-2; j>=0; j--){
        if(s[j] > s[j+1]){
            x = j;
            break;
        }
    }

    if(x == -1){
        return;
    }

    int y  = -1;
    for(int i=n-1; i>x; i--){
        if(s[i] < s[x]){
            y = i;
            break;
        }
    }

    swap(s[x], s[y]);
    reverse(s.begin()+x+1, s.begin()+y+1);
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

// ------------- Better using binary search --------------
void Swap(const auto &it1, const auto &it2){
    *it1 = *it1 ^ *it2;
    *it2 = *it1 ^ *it2;
    *it1 = *it1 ^ *it2;
}

void prevPermutation(string &s){
    int n = s.size();
    int x = -1;
    for(int j=n-2; j>=0; j--){
        if(s[j] > s[j+1]){
            x = j;
            break;
        }
    }

    if(x == -1){
        return;
    }

    auto y  = lower_bound(s.begin()+x+1, s.end(), s[x]); // Position of element greatest of smaller than s[x]

    Swap(s.begin()+x, y-1);
    reverse(s.begin()+x+1, y);
}

// Time Complexity: O(log n)
// Auxiliary Space: O(1)

int main(){
    string s = "4321";
    prevPermutation(s);
    cout << s;
    return 0;
}