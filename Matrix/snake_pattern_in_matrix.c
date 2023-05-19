#include <stdio.h>
#include <stdlib.h>
#define n 3
#define m 2

int main(){
    int a[n][m] = { {1,2},{3,4},{5,6} };

    for (int r = 0; r < n; r++){
        if(r%2 != 0){
            for (int c = 0; c < m; c++){
                printf("%d ",a[r][c]);
            }
        }
        else{
            for(int c = m-1; c>=0; c--){
                printf("%d ",a[r][c]);
            }
        }
    }    
    return 0;
}

// Time Complexity: O(n*m)
// Auxiliary space: O(1)