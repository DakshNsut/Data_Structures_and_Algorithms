#include <bits/stdc++.h>
using namespace std;

#define N 4 // Rows
#define M 4 // Columns

// Function to find pair with maximum
// difference in a matrix
int maxDifferencePair(int mat[N][M]){
	int maxElement = INT_MIN; // max
	int minElement = INT_MAX; // min

	// Traverse the matrix
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			// Find max element
			if (mat[i][j] > maxElement){
				maxElement = mat[i][j];
			}

			// Find min element
			if (mat[i][j] < minElement){
				minElement = mat[i][j];
			}
		}
	}

	return abs(maxElement - minElement);
}

// Time Complexity: O(R*C)
// Auxiliary space: O(1)

// Driver Code
int main()
{
	int mat[N][M] = { { 1, 2, 3, 4 },
					{ 25, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };
	cout << maxDifferencePair(mat) << endl;

	return 0;
}
