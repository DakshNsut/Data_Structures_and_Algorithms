#include <iostream>
using namespace std;

// Function to return sum of count of set bits in the integers from 1 to n.

int countSetBits(int n)
{
    n++;
    int powerOfTwo = 2;
    int count = n/2;

    while(powerOfTwo <= n){
        int totalPairs = n/powerOfTwo;
        count += (totalPairs)/2 * powerOfTwo;
        count += (totalPairs & 1) ? (n%powerOfTwo) : 0;
        powerOfTwo <<= 1;
    }
    return count;
}

int main(){
    cout << countSetBits(5);
    return 0;
}