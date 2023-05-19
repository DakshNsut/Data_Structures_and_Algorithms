#include <iostream>
using namespace std;

int main(){
    int n1 = 3, n2 = 3, n3 = 3;

    int m1[n1][n2] = { {1, 1, 1},
                    {2, 2, 2},
                    {3, 3, 3} };

    int m2[n2][n3] = { {1, 1, 1},
                    {2, 2, 2},
                    {3, 3, 3} };
    
    int res[n1][n3];
    // Matrix Multiplication
    // the res matrix will be n1 X n3
    int r_e = n1-1;
    int c_e = n3-1;

    // The row of m1
    for (int i = 0; i <= r_e; i++){
        // The column of m2
        for(int j= 0; j<= c_e ; j++){
            int sop = 0;
            // The column of m1 and row of m2
            for (int k = 0; k < n2; k++){
                sop += m1[i][k] * m2[k][j];
            }
            res[i][j] = sop;
        }
    }

    cout << "The result is as follows:\n";
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n3; j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");        
    }

    return 0;
}

// Time Complexity: O(n^3)
// Auxiliary space: O(1)