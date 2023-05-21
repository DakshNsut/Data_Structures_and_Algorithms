#include <iostream>
using namespace std;

// Count set bits in an integer

int countSetBits(unsigned int n){
	int count = 0;
	while (n){
		count += n & 1;
		n >>= 1;
	}
	return count;
}

int main(){
	int i = 9;
	cout << countSetBits(i);
	return 0;
}