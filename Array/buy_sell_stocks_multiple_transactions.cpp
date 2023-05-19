#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// to find maximum profit that can be earned when buying and selling a stock with multiple transactions allowed

// -------------------------- Recursion + DP --------------------------
vector<vector<int>> mem;
int Calculateprofit(vector<int> prices, int pos, bool bought){
    // The three states are:
    // bought or not: bool brought
    // stock_day: pos

    // Base Case ->(prices array got finished or no. of transactions that can be done = 0)
    if(pos>=prices.size()){
        return 0;
    }
    // If the result was already calculated use the stored result
    if(mem[bought][pos] != -1){
        return mem[bought][pos];
    }

    // 3 choices that can be done for this stock day
    int result = Calculateprofit(prices,pos+1,bought); // SKIP
    if(bought){
        result = max(result,Calculateprofit(prices,pos+1,false)+prices[pos]); // SELL
    }
    else{
        result = max(result,Calculateprofit(prices,pos+1,true)-prices[pos]); // BUY
    }

    // Store the max value
    mem[bought][pos] = result;
    return result;
}

int maxProfit(vector<int> &prices){
    mem.resize(2,vector<int>(prices.size(),-1));
    int result = Calculateprofit(prices,0,false);
    return result;
}

// Time complexity: O(n) 
// Auxiliary Space: O(n)

// --------------------------- STATE MACHINE TRANSITION APPROACH ---------------------------
int maxProfit(vector<int> &prices){
    int n = prices.size();
    if(n==0 || n==1){
        return 0;
    }

    vector<int> noStock(n),Bought(n),Sold(n);
    noStock[0] = 0;
    Bought[0] = -prices[0];
    Sold[0] = 0;
    for(int i=1; i<n; i++){
        noStock[i] = max(noStock[i-1],Sold[i-1]);
        Bought[i] = max(Bought[i-1],noStock[i-1]-prices[i]);
        Sold[i] = max(Sold[i-1],Bought[i-1]+prices[i]);
    }

    return max(noStock[n-1],Sold[n-1]);
}

// Time complexity: O(n) 
// Auxiliary Space: O(n)

// -------------------- Optmisation for above approach --------------------
int maxProfit(vector<int> &prices){
    int n = prices.size();
    if(n==0 || n==1){
        return 0;
    }

    int noStockPrev = 0;
    int BoughtPrev = -prices[0];
    int SoldPrev = 0;
    for(int i=1; i<n; i++){
        int noStockPrevTemp = noStockPrev;
        int BoughtPrevTemp = BoughtPrev;
        int SoldPrevTemp = SoldPrev;

        noStockPrev = max(noStockPrevTemp,SoldPrev);
        BoughtPrev = max(BoughtPrevTemp,noStockPrevTemp-prices[i]);
        SoldPrev = max(SoldPrevTemp,BoughtPrevTemp+prices[i]);
    }

    return max(noStockPrev,SoldPrev); // prev at last will be for i = n-1
}

// Time complexity: O(n) 
// Auxiliary Space: O(1)

int main(){
    vector<int> prices = {11, 6, 7, 19, 4, 1, 6, 18, 4};
    cout << maxProfit(prices);
    return 0;
}