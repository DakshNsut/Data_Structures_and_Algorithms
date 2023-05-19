#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// to find kth smallest element in a matrix

// --------------------- Method - 1 ----------------
#define MAX 10000
// function to generate pivot in quick sort
int partition(int mat[][MAX],int s, int e, int n){
    int pi = s;
    while(s<e){
        while(mat[s/n][s%n] <= mat[pi/n][pi%n]){
            s++;
        }
        while(mat[e/n][e%n] > mat[pi/n][pi%n]){
            e--;
        }
        if(s<e){
            swap(mat[s/n][s%n],mat[e/n][e%n]);
        }
    }
    swap(mat[e/n][e%n], mat[pi/n][pi%n]);
    return e;
}

// function to implement quick sort
void quickSort(int mat[][MAX], int k,int s, int e, int n){
    if(s<=e){
        int pivot = partition(mat,s,e,n);
        if((k-1)<(pivot-s))
            quickSort(mat,k,s,pivot-1,n);
        else if((k-1)>(pivot-s))
            quickSort(mat,k-pivot-1+s,pivot+1,e,n);
    }
}

// main function
int kthSmallest(int mat[][MAX], int n, int k)
{
    quickSort(mat,k,0,n*n-1,n);
    int ans = mat[(k-1)/n][(k-1)%n];
    return ans;
}

// Driver program to implement the above functions
int main() {
	int mat[][MAX] =  {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }};
    int n = 4;
    int k = 3;
    cout << kthSmallest(mat,n,k) << endl;
	return 0;
}

// Average Time Complexity = O(n)
// Worst Case Time Complexity = O(n^2)
// Space Complexity = O(log(n))

// --------------------- Method - 2 -------------
int kthSmallest(vector<vector<int>> &input, int n, int m, int k) {
    // Inbuilt max priority queue
    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            pq.push(input[i][j]);
        }
    }

    // Removing all the greater elements from Kth smallest element in priority queue
    for(int i=0; i<n*m-k; i++){
        pq.pop();
    }

    // Now the element at the top is Kth smallest element in a row-wise and column-wise sorted 2D array
    return pq.top();
}

// Time Complexity: O(n*m*log(m*n))
// Auxiliary space: O(1)

// Driver program to implement the above functions
int main(){
    // n is number of rows & m is number of columns in array
    int n = 4,m = 4;   
    vector<vector<int>> matrix = {{16, 28, 60, 64}, {22, 41, 63, 91}, {27, 50, 87, 93}, {36, 78, 87, 94 }};;
    int k = 3;

    cout << kthSmallest(matrix, n, m, k);
    return 0;
}