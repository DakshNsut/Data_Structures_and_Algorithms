#include <stdio.h>
#include <stdlib.h>

// to find union of two sorted arrays
// note: the union should not contain duplicates

int main(){
    int arr1[] = {2,3,4,6,9,11};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {1,2,3,4,5,6,7,8};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    int s[n1+n2+1];
    int k=0;

    int i=0,j=0;
    while (i<n1 && j<n2)
    {
        if(arr1[i] < arr2[j]){
            if(k>0 && s[k-1] != arr1[i]){
                s[k] = arr1[i];
                k++;
            }
            else if (k==0)
            {
                s[k] = arr1[i];
                k++;
            }
            i++;
        }
        else if(arr1[i]>arr2[j]){
            if(k>0 && s[k-1] != arr2[j]){
                s[k] = arr2[j];
                k++;
            }
            else if (k==0)
            {
                s[k] = arr2[j];
                k++;
            }
            j++;
        }
        else{
            if(k>0 && s[k-1] != arr1[i]){
                s[k] = arr1[i];
                k++;
            }
            else if (k==0)
            {
                s[k] = arr1[i];
                k++;
            }
            i++; j++;
        }
    }

    while(i<n1){
        if(k>0 && s[k-1] != arr1[i]){
            s[k] = arr1[i];
            k++;
        }
        else if (k==0)
        {
            s[k] = arr1[i];
            k++;
        }
        i++;
    }

    while(j<n2){
        if(k>0 && s[k-1] != arr2[j]){
            s[k] = arr2[j];
            k++;
        }
        else if (k==0)
        {
            s[k] = arr2[j];
            k++;
        }
        j++;
    }    

    for (int i=0;i<k;i++){
        printf("%d ",s[i]);
    }

    return 0;
}

// Time Complexity: O(n1+n2)
// Auxiliary space: O(n1+n2)