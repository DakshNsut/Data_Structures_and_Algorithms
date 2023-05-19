#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// minimum characters to be added at front to make string a palindrome

// ---------------- Naive method --------------
bool checkPali(string &s,int l, int h){
    while(l<h){
        if(s[l]!=s[h]){
            return false;
        }
        l++; h--;
    }
    return true;
}

int minChar(string str){
    int n = str.size();
    for(int i=n-1;i>=0;i--){
        if(checkPali(str,0,i)){
            return n-i-1;
        }
    }
        
    return n-1;
}

// Time Complexity : O(n^2)
// Auxiliary Space : O(1)

// ---------------- Better Solution ------------------
void computeLPS(string &concat, int* lps){
    lps[0] = 0;
    int m = concat.size();
    int i=0, j=1;
    while(j<m){
        if(concat[i]==concat[j]){
            lps[j] = i+1;
            i++; j++;
        }
        else{
            if(i!=0){
                i = lps[i-1];
            }
            else{
                lps[j] = 0;
                j++;
            }
        }
    }
}

string reverse(string& str){
    int n = str.size();
    string temp;
    int i = n-1;
    while(i>=0){
        temp.push_back(str[i]);
        i--;
    }
    return temp;
}

int minChar(string str){
    int n = str.size();
    string reversed = reverse(str);
    string concat = str + "$" + reversed;
    
    int *lps = new int[2*n+1];
    computeLPS(concat,lps);
    
    int lastValue = lps[2*n];
    delete[] lps;
    return n - lastValue;
}

// Time Complexity : O(n)
// Auxiliary Space : O(n)

// ---------------------- Optimal Method ----------------
int minChar(string str){
	int i=0;
	int j = str.size()-1;
	while(i<j){
		if(str[i] == str[j]){
			i++; j--;
		}
		else{
			res++; i=0;
			j= n-res-1;
		}
	}
	return res;
}

// Time Complexity : O(n)
// Auxiliary Space : O(1)

int main(){
    cout << minChar("aacecaaa") << endl;
    cout << minChar("abc");
    return 0;
}