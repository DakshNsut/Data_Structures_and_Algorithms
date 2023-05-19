#include <stdio.h>

int main()
{
    int num,OrgNum,count=0;
    printf("Enter the number you want to find its number of digits: ");
    scanf("%d",&num);
    OrgNum = num;

    while(num !=0)
    {
        num = num/10;
        count++;
    }
    printf("The number of digits in %d is %d.",OrgNum,count);
}

// Time Complexity: O(log10(n))
// Auxiliary space: O(1)