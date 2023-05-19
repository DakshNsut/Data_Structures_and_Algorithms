#include <iostream>
using namespace std;

int main(){
    int n = 4, m = 4;
    int a[n][m] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };

    int r_s = 0;
    int r_e = n-1;

    int c_s = 0;
    int c_e = m-1;

    while (r_s <= r_e && c_s <= c_e){
        // for row start
        for(int i=c_s; i<=c_e; i++){
            printf("%d ", a[r_s][i]);
        }
        r_s++;

        // for column end
        for(int i=r_s; i<=r_e; i++){
            printf("%d ",a[i][c_e]);
        }
        c_e--;

        // for row end
        for (int i = c_e; i >=c_s; i--){
            printf("%d ",a[r_e][i]);
        }
        r_e--;

        // for column start
        for (int i = r_e; i >= r_s ; i--){
            printf("%d ",a[i][c_s]);
        }
        c_s++;
    }
}

// Time Complexity: O(n*m)
// Auxiliary space: O(1)