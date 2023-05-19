#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// to arrange the array such that it has alternate positive and negative elements

// rotates array between a and b
void rotate(vector<int> &arr,int a, int b){
    int temp = arr[b];
    for(int i = b; i>a; i--){
        arr[i] = arr[i-1];
    }
    arr[a] = temp;
}

// prints the array
void print(vector<int> &num){
    for(int i: num){
        cout << i << " ";
    }
    cout << endl;
}

// arranges the array
void alternate(vector<int> & v){
    int i = 0;
    int n = v.size();

    while(1){
        // Finding the out_of_place element
        while(i<n){
            if(v[i]<0 && (i&1) == 1){
                break;
            }
            else if(v[i]>=0 && (i&1) == 0){
                break;
            }
            i++;
        }

        // out_of_place element not found
        if(i == n){
            return;
        }

        // Finding the opposite sign element
        int j = i+1;
        int sign = (v[i]<0) ? -1:1;
        if(sign == -1){
            while(j<n){
                if(v[j] > 0){
                    break;
                }
                j++;
            }
        }
        else{
            while(j<n){
                if(v[j] < 0){
                    break;
                }
                j++;
            }
        }

        // no other out-of-place element found, the array is arranged
        if(j == n){
            return;
        }

        rotate(v,i,j);
    }
}

int main(){
    vector<int> num = {1, 2, 3, 6, -5, -4};
    alternate(num);
    print(num);
}

// Time Complexity: O(n)
// Auxiliary Space taken: O(1)