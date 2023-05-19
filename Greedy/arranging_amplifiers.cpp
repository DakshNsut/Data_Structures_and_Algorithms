#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findAmplPermut(int amp[], int n){
    // sort greedily
    sort(amp, amp+n, greater<int>());
    // count ones
    int ones = 0;
    for(int i=0; i<n; i++) if(amp[i] == 1) ones++;

    // handle special case
    for(int i=0; i<ones; i++) cout << "1 ";
    // handle special case
    if((n-ones) == 2 && amp[0]==3 && amp[1]==2) cout << "2 3 ";
    else for(int i=0; i<(n-ones); i++) cout << amp[i] << " "; // normal case
    cout << endl;
}

// Time Complexity: O(nlogn)
// Auxiliary space: O(1)

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        int *amp = new int[n];
        for(int i=0; i<n; i++) cin >> amp[i];
        t--;
        findAmplPermut(amp, n);
    }
    return 0;
}