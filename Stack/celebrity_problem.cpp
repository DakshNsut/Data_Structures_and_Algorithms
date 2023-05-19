#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// find a stranger/celebrity
// adjacency list defines who knows whom
// celebrity is one who doesn't know anyone but everybody knows him

// -------------- Naive Approach ---------------
int celebrity(vector<vector<int> >& M, int n){
    for(int i=0; i<n; i++){
        bool flag = true;
        for(int j=0; j<n; j++){
            if(M[i][j] == 1){
                flag = false;
            }
        }

        if(!flag) continue;

        flag = true;
        for(int r=0; r<n; r++){
            if(i!=r && M[r][i] == 0){
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
    return -1;
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// ------------ Efficient Soln ---------------
// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int> st;
    for(int i=0; i<n; i++){
        st.push(i);
    }
        
    while(st.size() >= 2){
        int i = st.top(); st.pop();
        int j = st.top(); st.pop();
        if(M[i][j] == 0){
            // if i doesn't know j, then i can be possible celeb
            st.push(i);
        }
        else{
            // if i knows j, then j can be possible celeb
            st.push(j);
        }
    }

    int celeb = st.top(); st.pop();
    for(int i=0; i<n; i++){
        // if celeb knows somebody i or somebody i doesn't know celeb
        // Then celeb is not a celebrity
        if(i != celeb && (M[celeb][i] == 1 || M[i][celeb] == 0)){
            return -1;
        }
    }
    return celeb;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// --------------- Most Optimal ----------------
int celebrity(int M[N][N], int n){
	int i = 0, j = n - 1;
	while (i < j) {
		if (M[i][j] == 1) // j knows i
			i++;
		else // j doesnt know i so i cant be celebrity
			j--;
	}

	int candidate = i;

	// Now, all that is left is to check that whether
	// the candidate is actually a celebrity i.e: he is
	// known by everyone but he knows no one
	for (i = 0; i < n; i++) {
		if (i != candidate){
			if (M[i][candidate] == 0 || M[candidate][i] == 1)
				return -1;
		}
	}

	return candidate;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    // represents if one person knows other or not.
    vector<vector<int>>M{ {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} };
    int n = 4;
    cout << celebrity(M, n);
    return 0;
}