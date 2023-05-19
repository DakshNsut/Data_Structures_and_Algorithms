#include<iostream>
#include<vector>
using namespace std;

// ---------------------- Method-1 -------------------
void sort_012(vector<int> &arr){
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;

    for(int i=0 ;i<arr.size() ;i++){

        if(arr[i] == 0)
        {
            count_0++;
        }
        else if(arr[i] == 1)
        {
            count_1++;
        }
        else if(arr[i] == 2)
        {
            count_2++;
        }

    }


    for(int i=0; i<count_0; i++){
        arr[i] = 0;
    }
    for(int i=count_0; i<count_0+count_1; i++){
        arr[i] = 1;
    }
    for(int i=count_0+ count_1; i<arr.size(); i++){
        arr[i] = 2;
    }

}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

// ---------------------- Method-2 -------------------
void sort_012(vector<int> &arr){

    int l = 0;
    int r = arr.size() -1;
    int k = 0;

    while(k<=r){

        if(arr[k] == 0){
            swap(arr[l],arr[k]);
            l++;
            k++;
        }

        else if(arr[k] == 2){
            swap(arr[r],arr[k]);
            r--;
        }

        else{
            k++;
        }
    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

int main(){
	vector<int> a = {0,2,0,1,2,1,2,0,1,2,0,1};
	sort_012(a);
	cout << "Sorted array is: ";
	for(int i: a) cout << i << " ";
	return 0;
}