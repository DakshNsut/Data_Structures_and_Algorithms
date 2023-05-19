#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// to find max profit when buying and selling stocks with atmost 2 transactions allowed

// -------------------------- Recursion + DP --------------------------
vector<vector<vector<int>>> mem;
int Calculateprofit(vector<int> prices, int pos, int t, bool bought){
    // The three states are:
    // bought or not: bool brought
    // transactions left: t
    // stock_day: pos

    // Base Case -(prices array got finished or no. of transactions that can be done = 0)
    if(pos>=prices.size() || t==0){
        return 0;
    }
    // If the result was already calculated use the stored result
    if(mem[bought][t][pos] != -1){
        return mem[bought][t][pos];
    }

    // 3 choices that can be done for this stock day
    int result = Calculateprofit(prices,pos+1,t,bought); // SKIP
    if(bought){
        result = max(result,Calculateprofit(prices,pos+1,t-1,false)+prices[pos]); // SELL
    }
    else{
        result = max(result,Calculateprofit(prices,pos+1,t,true)-prices[pos]); // BUY
    }

    // Store the max value
    mem[bought][t][pos] = result;
    return result;
}

int maxProfit(vector<int> &prices){
    mem.resize(2,vector<vector<int>>(3,vector<int>(prices.size(),-1)));
    int result = Calculateprofit(prices,0,2,false);
    return result;
}

// Time complexity: O(2^n) 
// Auxiliary Space: O(n)

// ------------------------------------ DIVIDE N CONQUER ------------------------------------
int maxProfit(vector<int> &prices){
    int n = prices.size();
    if(n == 0){
        return 0;
    }

    vector<int> left(n),right(n);

    // Building left array
    left[0] = 0;
    int min_so_far = prices[0];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1],prices[i] - min_so_far);
        min_so_far = min(min_so_far,prices[i]);
    }

    // Building right array
    right[n-1] = 0;
    int max_so_far = prices[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = max(right[i+1],max_so_far - prices[i]);
        max_so_far = max(max_so_far,prices[i]);
    }

    // Finding max of maxProfit at each point of division in the array
    int maxProfit = right[0];
    for(int i=1; i<n; i++){
        int profit = left[i-1] + right[i];
        maxProfit = max(maxProfit,profit);
    }

    return maxProfit;
}
// Time complexity: O(n^2)
// Auxiliary Space: O(1)

// --------------------------- Best Solution ---------------------------
int maxProfit(vector<int> &prices){
    int n = prices.size();
    int first_buy = INT_MIN;
    int first_sell = 0;
    int second_buy = INT_MIN;
    int second_sell = 0;
    for(int i=0; i<n; i++){
        first_buy = max(first_buy,-prices[i]);
        first_sell = max(first_sell,first_buy+prices[i]);
        second_buy = max(second_buy,first_sell-prices[i]);
        second_sell = max(second_sell,second_buy+prices[i]);
    }
    return second_sell;
}

// Time complexity: O(n)
// Auxiliary Space: O(1)

int main(){
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(prices);
    return 0;
}