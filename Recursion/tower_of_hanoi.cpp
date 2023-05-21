#include <iostream>
#include <climits>
using namespace std;

// Tower of Hanoi
// Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks.
// The objective of the puzzle is to move the entire stack to another rod

// ------------ Using Recursion ------------
void TOH(int n, char from_rod, char to_rod, char aux_rod){
    if(n == 0) return;

    // Placing n-1 rods from from_rod to aux_rod
    TOH(n-1, from_rod, aux_rod, to_rod);
    // Placing 1 rod left from from_rod to to_rod
    cout << "Moved disk " << n << " from rod " << from_rod << " to " << to_rod << endl;
    // Placing n-1 rods from aux_rod to to_rod
    TOH(n-1, aux_rod, to_rod, from_rod);
}

// Time complexity: O(2^n)
// Auxiliary Space: O(n)

int main(){
    TOH(3, 'A', 'C', 'B');
    return 0;
}