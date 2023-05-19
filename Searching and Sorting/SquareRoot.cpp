#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number ";
    cin >> n;

    int s = 0;
    int e = n/2;

    long long int mid = s+(e-s)/2;
    long long int ans = -1;
    while(s <= e){
        long long int sqr = mid*mid;
        if(sqr == n){
            ans = mid;
            break;
        }
        else if(sqr<n){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }

    int prec;
    cout << "Enter precision till what decimal places ";
    cin >> prec;

    double final_ans = ans;
    double factor = 1;
    for (int i = 0; i<prec ;i++){
        factor /= 10;
        for(double j = ans; j*j<n ; j += factor){
            final_ans = j;
        }
    }

    cout << final_ans;
}

// Time Complexity: O(log(n) + precision)
// Auxiliary Space: O(1)

// --------------------------------- RECURSIVE ---------------------------------
    int sqrt(int n, int s, int e, int ans=-1){

    if (s > e){
        return ans;
    }

    int mid = s + (e - s) / 2;
    int sqr = mid * mid;
    if(sqr == n){
        return mid;
    }
    if(sqr < n){
        return sqrt(n, mid + 1, e, mid);
    }
    else{
        return sqrt(n, s, mid - 1, ans);
    }

}

double precise(double n, double j, double final_ans,int prec, int ans, int i=1, double factor=0.1){
    if(i > prec){
        return final_ans;
    }

    // if this prec unit completed
    if(j*j >= n){
        return precise(n, ans, final_ans, prec, ans, i + 1, factor/10);
    }
    else{
        return precise(n, j + factor, j, prec, ans, i, factor);
    }
}

// Time Complexity: O(log(n) + precision)
// Auxiliary Space: O(log(n) + precision)

int main(){
    int n = 2;
    int ans = sqrt(n, 0, n/2);
    cout << precise(n, ans, ans, 3, ans);

    return 0;
}
