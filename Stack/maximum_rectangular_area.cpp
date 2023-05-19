#include <iostream>
#include <stack>
#include <climits>
using namespace std;

// maximum rectangular area in a histogram

// -------------- Better Solution -----------------
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long int *ps = new long long int[n];
        ComputePS(arr, n, ps);
        long long int * ns = new long long int[n];
        ComputeNS(arr, n, ns);
        long long int res = INT_MIN;

        for(int i=0; i<n; i++){
            long long int curr = arr[i];
            curr += (i-ps[i]-1) * arr[i];
            curr += (ns[i]-i-1) * arr[i];
            res = max(res, curr);
        }
        return res;
    }
    
    void ComputePS(long long int arr[], int n, long long int ps[]){
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    
    void ComputeNS(long long int arr[], int n, long long int ns[]){
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
};

// Time Complexity: O(n) - needs two traversals
// Auxiliary space: O(n)

// ----------------- Best Solution ---------------
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
        long long int res = INT_MIN;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int tp = st.top();
                st.pop();
                // for tp -> NS is at i and PS is at current st.top()
                long long int currArea = arr[tp] * ((st.empty()) ? i : (i-st.top()-1));
                res = max(res, currArea);
            }
            st.push(i);
        }
        
        // For ones that don't have NS
        while(!st.empty()){
            int tp = st.top();
            st.pop();
            long long int currArea = arr[tp] * ((st.empty()) ? n : (n-1-st.top()));
            res = max(res, currArea);
        }

        return res;
    }
};

// Time Complexity: O(n) - needs one traversal
// Auxiliary space: O(n)


int main(){
    Solution obj;
    long long arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << obj.getMaxArea(arr, n);
    return 0;
}