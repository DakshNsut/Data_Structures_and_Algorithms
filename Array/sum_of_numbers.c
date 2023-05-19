#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    // Taking the last number of the natural number series as input
    int lastnum;
    printf("Enter the last number of the series of natural numbers you want sum of: ");
    scanf("%d",&lastnum);

    // Adding the numbers of the natural number series till the last number
    int sum = 0;
    for (int i = 0; i <= lastnum; i++)
    {
        sum +=i;
    }

    // Showing the calculated sum
    printf("The sum of all natural numbers till the number you entered is: %d",sum);
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)