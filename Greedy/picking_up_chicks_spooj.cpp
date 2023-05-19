#include <iostream>
#include <vector>
using namespace std;

// ------------ Picking up chicks (SPOJ) ----------------

void findSwaps(vector<long long int> &x, vector<long long int> &v, long long int &n, long long int &k, long long int &b, long long int &t){
    int slow_chicks =0, ans =0; // slow chicks which are ahead are counted

    long long int count = 0;
    for(int i=n-1; i>=0; i--){
        int dist1 = b-x[i]; // distance between barn and chick/ distance which has to be travelled
        int dist2 = t*v[i]; // distance which can be travelled in time 'T'
        if(dist2 >= dist1){ ans += slow_chicks; count++;}
        else slow_chicks++;

        if(count >= k) break;
    }

    if(count >= k) cout << ans << endl; // because question said atleast 'k'
    else cout << "IMPOSSIBLE";
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    long long int t;
    cin >> t;

    long long int j=1;
    while(t){
        long long int n, k, b, T;
        cin >> n >> k >> b >> T;
        vector<long long int> x, v; // x-> positions of respective chicks, v-> velocity of repsective chicks
        for(int i=0; i<n; i++){
            long long int a;
            cin >> a;
            x.push_back(a);
        }
        for(int i=0; i<n; i++){
            long long int a;
            cin >> a;
            v.push_back(a);
        }

        cout << "Case #" << j << ": ";
        findSwaps(x, v, n, k, b, T);
        j++;
        t--;
    }
    return 0;
}