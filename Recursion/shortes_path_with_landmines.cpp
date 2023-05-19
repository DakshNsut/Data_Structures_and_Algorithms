#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;
#define R 12
#define C 10

// to find length of shortest path with landmines in the field

bool isSafe(int path[][C], int i, int j, int visited[][C]){
	if(visited[i][j]) return false;
	if(i<0 || i>=R || j<0 || j>=C) return false;

	int x = i;
	int y = j-1;
	if(path[x][y] == 0) return false;

	x = i;
	y = j+1;
	if(path[x][y] == 0) return false;

	x = i+1;
	y = j;
	if(path[x][y] == 0) return false;

	x = i-1;
	y = j;
	if(path[x][y] == 0) return false;

	return true;
}

void move(int path[][C], int currLen, int i, int j, int &ans, int visited[][C]){
	if(j == C-1){
		currLen++;
		if(currLen < ans) ans = currLen;
		return;
	}

	visited[i][j] = 1;

	int x = i;
	int y = j-1;
	if(isSafe(path, x, y, visited)) move(path, currLen+1, x, y, ans, visited);

	x = i;
	y = j+1;
	if(isSafe(path, x, y, visited)) move(path, currLen+1, x, y, ans, visited);

	x = i+1;
	y = j;
	if(isSafe(path, x, y, visited)) move(path, currLen+1, x, y, ans, visited);

	x = i-1;
	y = j;
	if(isSafe(path, x, y, visited)) move(path, currLen+1, x, y, ans, visited);

	visited[i][j] = 0;
}

// Time Complexity: O(4^(n^2))
// Auxiliary space: O(n^2)

int main(){
	int path[R][C] = {{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
                      { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }};

	int ans = INT_MAX;
	int visited[R][C] = {0};
	for(int i=0; i<R; i++){
		move(path, 0, i, 0, ans, visited);
	}
	cout << ans;

	return 0;
}