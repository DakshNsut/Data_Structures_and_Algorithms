#include <iostream>
#include <vector>
using namespace std;
#define N 8

// the knight must visit every square exactly once
// print the sequence in which the square will be visited by knight

void printChessBoard(vector<vector<int>> &chess){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << chess[i][j] << " ";
		}
		cout << endl;
	}
}

bool isSafe(vector<vector<int>> &chess, int i, int j){
	if(i>=0 && i<N && j>=0 && j<N && chess[i][j] == -1) return true;
	return false;
}

bool checkAns(vector<vector<int>> &chess){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(chess[i][j] == -1) return false;
		}
	}
	return true;
}

void KnightTour(vector<vector<int>> &chess, int i, int j, int order, bool &foundAns, int *xDir, int *yDir){
	if(foundAns == true) return;
	if(order == N*N){
		if(checkAns(chess)) foundAns = true;
		return;
	}

	bool flag = false;
	for(int d=0; d<N; d++){
		int x = i + xDir[d];
		int y = j + yDir[d];

		if(isSafe(chess, x, y)){
			chess[x][y] = order;
			KnightTour(chess, x, y, order+1, foundAns, xDir, yDir);
			if(foundAns == true) return;
			chess[x][y] = -1;
		}
	}
}

// Time Complexity: O(8^(N^2))
// Auxiliary Space: O(N^2)

int main(){
	vector<vector<int>> chess(N, vector<int>(N,-1));
	chess[0][0] = 0;
	bool foundAns = false;

	// This order really matters to get the answer is less than 2 seconds
	int xDir[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yDir[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	KnightTour(chess, 0, 0, 1, foundAns, xDir, yDir);
	printChessBoard(chess);
	return 0;
}