#include <iostream>
#include <climits>
#include <queue>
using namespace std;

// to find k elements closes to x

// --------------------------------- METHOD -1 ------------------------------
void findKClosest(int arr[], int n, int x, int k){
    bool visited[n] = {false};

    for(int i=0; i<k; i++){
        int min_diff = INT_MAX;
        int min_diff_index;
        for(int j=0; j<n; j++){
            int diff = abs(arr[j] - x);
            if(!visited[j] && diff < min_diff){
                min_diff = diff;
                min_diff_index = j;
            }
        }
        cout << arr[min_diff_index] << " ";
        visited[min_diff_index] = 1;
    }
}

// Time Complexity: O(n*k)
// Auxiliary space: O(n)

// --------------------------------- METHOD -2 ---------------------------
void findKClosest(int arr[], int n, int x, int k){
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<k; i++){
        pq.push(make_pair(abs(arr[i]-x),i));
    }

    for(int i=k; i<n; i++){
        int diff = abs(arr[i]-x);
        if(pq.top().first > diff){
            pq.pop();
            pq.push(make_pair(diff,i));
        }
    }

    while(!pq.empty()){
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}

// Time Complexity: O(n*logk)
// Auxiliary space: O(k)

// --------------------------------- METHOD -3 (if array is sorted) ---------------------------
int findCrossOver(int arr[], int l, int r, int x){
    int mid = l+((r-l)>>1);
    while(l <= r){
        if(arr[l] > x) return l;
        if(arr[r] <= x) return r;

        mid = l+((r-l)>>1);
        if(arr[mid] <= x && arr[mid+1] > x) return mid;

        if(arr[mid] < x) l = mid+1;
        else r = mid-1;
    }
}

void findKClosest(int arr[], int n, int x, int k){
    int l = findCrossOver(arr,0,n-1,x);
    int r = l+1;
    int cnt = 0;

    while(cnt < k && l>=0 && r<n){
        if(abs(arr[l]-x) < abs(arr[r]-x)) cout << arr[l--] << " ";
        else cout << arr[r++] << " ";
        cnt++;
    }
    while(cnt < k && l >=0) {cout << arr[l--] << " "; cnt++;}
    while(cnt < k && r < n) {cout << arr[r++] << " "; cnt++;}
}

// Time Complexity: O(Logn + k)
// Auxiliary space: O(1)

int main(){
    int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4, x = 35;
    findKClosest(arr,n,x,k);
}