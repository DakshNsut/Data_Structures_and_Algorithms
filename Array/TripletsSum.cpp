#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// ------------ Two pointer approach -------------
void triplets_sum(vector<int> &v, int sum){
    for (int i =0; i<v.size() ;i++){
        int l = i+1;
        int r = v.size()-1;

        while(l<r){
            if(v[l] + v[r] + v[i] == sum)
            {
                cout<<v[i]<<" "<<v[l]<<" "<<v[r]<<endl;
                break;
            }

            else if(v[l] + v[r] + v[i] < sum)
            {
                l++;
            }

            else
            {
                r--;
            }
        }
    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

// ------------------- Hashing approach ---------------
bool triplets+sum(vector<int> A, int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
 
        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }
 
    // If we reach here, then no triplet was found
    return false;
}

int main(){
    vector<int> v = {2,2,4,2};
    triplets_sum(v, 8);
    return 0;
}