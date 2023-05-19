#include <iostream>
#include <vector>
using namespace std;

// to check if s2 is a rotation of s1

// ---------------- Method - 1 -------------
bool isRotationUtil(string &s1, string &s2, int idx){
    int n = s1.size();
    int i = idx; // to find the first occurence of s2[0] in s1 // T(n) = O(n)
    int j = 0;

    // traversing s2 to find 'p'
    while(j<n){ // T(n) = O(n)
        if(s2[j] != s1[(i)%n])
        return 0;
        i++; j++;
    }

    return 1;
}

string isRotation(string &s1, string &s2){
    int k = s2[0];
    vector<int> indexes;
    int n = s1.size();
    for(int i=0; i<n; i++){
        if(s1[i] == k){
			indexes.push_back(i);
        }
    }

    for(int index: indexes){
		bool result = isRotationUtil(s1,s2,index);
		if(result){
			return "Yes";
		}
    }
    return "No";
}

// Time Complexity: O(n*n)
// Auxiliary space: O(n)

int main(){
    string s1 = "ADAC";
    string s2 = "ACAD";
    cout << isRotation(s1,s2);
}

// ----------- Method - 2 -------------
string isRotation(string &s1, string &s2){
    s1.append(s1);
    return (s1.find(s2) == string::npos) ? "No" : "Yes";
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    string s1 = "ADAC";
    string s2 = "ACAD";
    cout << isRotation(s1,s2);
}