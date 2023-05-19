#include<iostream>
#include<vector>
using namespace std;

// Given a number of pages in N different books and M students.
// The task is to assign books in such a way that the maximum
// number of pages assigned to a student is minimum.

bool isPossible(vector<int> &arr, int &n, int &m, int &mid){
    int studentCount = 1; // Staring for 1st student
    int pagesSum = 0; // pages sum count

    for(int i = 0; i < n ;i++){
        if(pagesSum + arr[i] <= mid){
            pagesSum += arr[i];
        }
        else{
            studentCount++;
            // Starting a new group
            pagesSum = arr[i];

            // arr[i]> mid means not even one element can be allocated to any student
            // e.g -> mid= 50 but, arr[i] = 70, 70 can't be their in any group

            if(studentCount > m || arr[i] > mid){
                return false;
            }
        }
    }
    return true;
}

int allocate_books(vector<int> &arr, int &n , int &m){
    int sum = 0;
    for(int i: arr){
        sum+=i;
    }

    int s = 0;
    int e = sum;

    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        if(isPossible(arr, n, m, mid )){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }

    return ans;
}

// Time Complexity: O(n*log(n)), n is the total number of pages
// Auxiliary space: O(1)

int main(){
    vector<int> v = {10,20,30,40};
    int n = v.size();
    int m = 2;

    cout << allocate_books(v,n,m);
}

// -------------------------- RECURSIVELY --------------------------

#include <iostream>
#define ELE 10, \
20, \
30, \
40
using namespace std;

int Sum(int arr[], int n){
    if(n == -1){
        return 0;
    }

    return arr[n] + Sum(arr, n-1);
}

bool isPossible(int arr[], int mid, int n, int m, int i = 0, int studentCount = 1, int pagesSum = 0){


    if(i == n){
        return true;
    }

    if(pagesSum + arr[i] <= mid){
        return isPossible(arr, mid, n, m, i+1, studentCount, pagesSum + arr[i]);
    }
    else{
        if(studentCount+1 > m || arr[i]>mid){
            return false;
        }
        return isPossible(arr, mid, n, m, i+1, studentCount+1, arr[i]);

    }
}

int book_allocate(int arr[], int s, int e, int n, int m, int ans = -1){
    int mid = s+(e-s)/2;

    if(s>e){
        return ans;
    }

    if(isPossible(arr, mid, n, m)){
        book_allocate(arr, s, mid-1, n, m, mid);
    }
    else{
        book_allocate(arr, mid+1, e, n, m, ans);
    }
}

// Time Complexity: O(n*log(n)), n is the total number of pages

int main()
{
    int arr[] = { ELE };
    int n = sizeof(arr)/sizeof(arr[0]); // number of books
    int m = 2; // number of students

    int sum = Sum(arr, n-1);
    cout<<endl<<"ans= "<<book_allocate(arr, 0, sum, n, m);
    
    return 0;
}