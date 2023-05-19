#include <iostream>
using namespace std;

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n = 4;
    int a[n][n] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(&a[i][j], &a[j][i]);
        }
    }

    printf("Transpose of the matrix is: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

// Time Complexity: O(n*m)
// Auxiliary space: O(1)