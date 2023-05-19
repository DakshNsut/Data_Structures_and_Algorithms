#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// to find kth ancestor of X

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int a){
        this->data = a;
        left = right = NULL;
    }
};

// -------------------- Naive ------------------

bool storePath(Node* root, int &x, vector<int> &path){
    if(!root) return 0;
    if(root->data == x) return 1;
    path.push_back(root->data);

    if(storePath(root->left, x, path) || storePath(root->right, x, path)) return 1;
    else path.pop_back();
}

int findKthAncestor(Node* root, int &x, int &k){
    vector<int> path;
    storePath(root, x, path); // stores path from root to node with value 'x'

    int n = path.size();
    if(n-k < 0) return -1;
    return path[n-k];
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// --------------- Space Optimised ---------------
bool findKthAncestor(Node* root, int &x, int &k, int &ans){
    if(!root) return 0;
    if(root->data == x) return 1;

    if(findKthAncestor(root->left, x, k, ans) || findKthAncestor(root->right, x, k, ans)){
        k--;
        if(k == 0) ans = root->data;
        return 1;
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(h)

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int x = 5;
    cout << findKthAncestor(root, x, k) << endl;
    return 0;
}