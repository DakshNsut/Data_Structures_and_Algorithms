#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> &a){
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

vector<int> nbit_sum(vector<int>&a, vector<int>&b) {
    int carry = 0;
    int res;
    vector<int> sum;
    int e1 = a.size()-1;
    int e2 = b.size()-1;

    while(e1>=0 && e2>=0){
        res = a[e1] + b[e2] + carry;
        carry = 0;

        if(res>9){
            sum.push_back(res%10);
            carry = res/10;
        }
        else{
            sum.push_back(res);
        }
        e1--;
        e2--;
    }

    while(e1>=0){
        res = a[e1] + carry;
        carry = 0;

        if(res>9){
            sum.push_back(res%10);
            carry = res/10;
        }
        else{
            sum.push_back(res);
        }
        e1--;
    }

    while(e2>=0){
        res = b[e2] + carry;
        carry = 0;

        if(res>9){
            sum.push_back(res%10);
            carry = res/10;
        }
        else{
            sum.push_back(res);
        }
        e2--;
    }
    
    if(carry){
        sum.push_back(carry);
    }

    reverse(sum.begin(), sum.end());
    return sum;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    vector<int> a = {9, 9, 9};
    vector<int> b = {9, 9, 9};

    auto sum = nbit_sum(a, b);
    printVector(sum);
}