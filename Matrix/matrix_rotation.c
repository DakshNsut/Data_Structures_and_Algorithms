#include <stdio.h>
#include <stdlib.h>
#define n 4
#define m 4

int main(){
    int a[n][m] = { {1,2,7,10},{3,4,8,11},{5,6,9,12} };

    int stR = 0;
    int enR = n-1;
    int stC = 0;
    int enC = m-1;

    printf("Matrix before Rotation\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    while(stR<enR && stC<enC){
            int starting = a[stR][enC];  // backup of starting row last column element.
            
            // shift first row elements to the right
            for (int j = enC; j>=stC; j--){
                a[stR][j] = a[stR][j-1];
            }
            stR++;   // done with this first row.

            // shift first column elements to up
            for(int r=stR; r<=enR; r++) {
                a[r-1][stC]=a[r][stC];
            }
            stC++;  // done with this first column

            // shift last row elements to the left
            for(int c=stC; c<=enC; c++) {
                a[enR][c-1]=a[enR][c];
            }
            enR--;  // done with this last row

            // shift last column elements to up
            for(int r=enR; r>=stR; r--) {
                a[r+1][enC]=a[r][enC];
            }
            a[stR][enC]=starting;
            enC--;  // done with this last column
    }

    printf("Matrix after Rotation\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }    
    return 0;
}

// Time Complexity: O(n*m)
// Auxiliary space: O(1)