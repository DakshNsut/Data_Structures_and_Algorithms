#include <iostream>
using namespace std;

// search in a row-wise and column-wise sorted matrix

int main(){
    int n1 = 4, n2 = 4;
    int m[n1][n2] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };

    int target = 37;

    // The rightmost - topmost element
    int r = 0;
    int c = n2-1;

    while (r <= n1 && c >= 0){
        if(m[r][c] == target){
            printf("Found");
            return 0;
        }

        else if(m[r][c] > target){
            c--;
        }

        else{
            r++;
        }
    }

    printf("Not Found");
    return 0;
}

// Time Complexity: O(n+m)
// Auxiliary space: O(1)