#include <iostream>
#include <vector>
using namespace std;

// three - way partitioning about a range

void threeWayPartition(vector<int>& array,int a, int b)
{
    int n = array.size();
    int start = 0;
    int end = n-1;
    for(int i=0; i<=end;){
        if(array[i]<a){
            swap(array[start++],array[i++]);
        }
        else if(array[i]>b){
            swap(array[end--],array[i]);
			// don't move i becuase we aren't sure about the element's best position
        }
        else{
            i++;
        }
    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

void print(vector<int> &arr){
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> a = {-100, 1, 5, 3, 19, 18, 25};
    threeWayPartition(a, 1,5);
    print(a);
    return 0;
}