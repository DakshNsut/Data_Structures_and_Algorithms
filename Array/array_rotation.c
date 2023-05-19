#include <stdio.h>

// to left rotate an array

// -------------------- Method - 1 -----------------------
void rotate(int* a,int n,int d){
    int temp[d];
    if(d >= n){
        return;
    }
    for(int i=0; i<d; i++){
        temp[i]=a[i];
    }
    for(int j=0; j<d; j++){
        for(int i=0; i<n; i++){
            a[i]=a[i+1];
        }
    }
    for(int i=n-d,j=0; j<d; i++,j++){
        a[i]=temp[j];
    }
}

// Time complexity: O(n)
// Auxiliary Space taken: O(n)

// --------------------- Method - 2 --------------------
// Juggling algorithm

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void rotate(int* a,int n,int d){
    int j,k,temp;
    
    // to handle if d>=n
    d = d%n;
    for(int i=0; i<gcd(n,d); i++){
        j=i;
        temp=a[i];
        while(1){
            k = (j+d)%n;
            if(k == i){
                break;
            }
            a[j] = a[k];
            j = k;
        }
        a[j]=temp;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n=7;
    rotate(arr,n,3);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}

// Time complexity: O(n) 
// Auxiliary Space: O(1)