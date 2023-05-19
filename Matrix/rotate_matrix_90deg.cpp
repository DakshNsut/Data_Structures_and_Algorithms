#include <iostream>
using namespace std;

void displayMatrix(unsigned int * p, unsigned int n, unsigned int m){
    for(int i = 0; i<n; i++){
        for(int j = 0;j<m;j++){
            cout << *(p+i*n+j) << " ";
        }
        cout << "\n";
    }
}

// ------------------- Method - 1 --------------------
void Rotate_90(unsigned int * pS, unsigned int * pD, unsigned int row, unsigned int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            *(pD + j*col + (row-1-i)) = *(pS + i*row + j);
        }
    }
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// ------------------- Method - 2 --------------------
void Rotate_90(unsigned int * pS, unsigned int n){
    for(int i = 0; i<n/2; i++){
        for(int j = i; j<n - 1 - i; j++){
            int temp = *(pS + i*n + j);
            *(pS + i*n + j) = *(pS + (n-1-j)*n + i);
            *(pS + (n-1-j)*n + i) = *(pS + (n-1-i)*n + (n-1-j));
            *(pS + (n-1-i)*n + (n-1-j)) = *(pS + j*n + (n-1-i));
            *(pS + j*n + (n-1-i)) = temp;
        }
    }
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

int main(){
    unsigned int a[][4] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    int n = 4;
    int m = 4;
    unsigned int * pS = (unsigned int *) a;
    displayMatrix(pS,n,m);
    
    unsigned int * pD = (unsigned int *) malloc(sizeof(int) * m * n);
    Rotate_90(pS,pD,n,m);
    
    displayMatrix(pD, m, n);
    return 0;
}