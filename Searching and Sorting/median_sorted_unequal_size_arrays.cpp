#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// median of sorted arrays of unequal size

double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{
    int n1 = array1.size();
    int n2 = array2.size();
    if(n1<n2){
        return MedianOfArrays(array2,array1);
    }
        
    int l = 0;
    int h = n1;
        
    while(l<=h){
        int cut1 = (l+h)>>1;
        int cut2 = ((n1+n2+1)>>1) - cut1;
        int l1 = (cut1==0) ? INT_MIN:array1[cut1-1];
        int l2 = (cut2==0) ? INT_MIN:array2[cut2-1];
        int r1 = (cut1==n1) ? INT_MAX:array1[cut1];
        int r2 = (cut2==n2) ? INT_MAX:array2[cut2];
            
        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==0)
                return (max(l1,l2) + min(r1,r2))/2.0;
            return (max(l1,l2));
        }
        else if(l1>r2){
            h = cut1-1;
        }
        else{ // when l2>r1
            l = cut1+1;
        }
    }
    return 0.0;
}

int main(){
    vector<int> a = {1,4,7,10,12}, b = {2,3,6,15};
    cout << MedianOfArrays(a,b);
    return 0;
}

// Time Complexity: O(min(log M, log N))
// Auxiliary space: O(1)