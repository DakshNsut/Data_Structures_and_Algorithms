#include <iostream>
using namespace std;
#define N 3

// minimize the number of cash flow operations

int maxAmt(int arr[]){
    int maxInd = 0;
    for(int i=0; i<N; i++){
        if(arr[i] > arr[maxInd]) maxInd = i;
    }
    return maxInd;
}

int minAmt(int arr[]){
    int minInd = 0;
    for(int i=0; i<N; i++){
        if(arr[i] < arr[minInd]) minInd = i;
    }
    return minInd;
}

int getMin(int a, int b){
    return (a<b) ? a : b;
}

void minCashFlowRecur(int amount[]){
    int maxCredit = maxAmt(amount); // person who gets the max amount of money
    int maxDebit = minAmt(amount); // person who gives the max amount of money

    if(amount[maxCredit] == 0 && amount[maxDebit] == 0) return;
    int min = getMin(-amount[maxDebit], amount[maxCredit]);

    amount[maxCredit] -= min;
    amount[maxDebit] += min;

    cout << maxDebit << " pays " << min << " to " << maxCredit << endl;
    minCashFlowRecur(amount);
}

void minCashFlow(int cashFlow[][N]){
    int amount[N] = {0};

    for(int p=0; p<N; p++)
        for(int i=0; i<N; i++)
            amount[p] += (cashFlow[i][p] - cashFlow[p][i]);

    minCashFlowRecur(amount);
}

// Time Complexity: O(N^2)
// Space Complexity: O(N)

int main(){
    int cashFlow[N][N] = { {0, 1000, 2000}, {0, 0, 5000}, {0, 0, 0}};
    minCashFlow(cashFlow);

    return 0;
}