#include <stdio.h>

int main(){
    int a[2][3][2] = { {  {0,1},{2,3},{4,5}  } , {{6,7},{8,9},{10,11} } };
    printf("%d",a[0][2][1]);
    printf(" %d",a[1][2][0]);
    printf(" %d",a[0][2][0]);
    return 0;
}