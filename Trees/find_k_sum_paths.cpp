#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// find all paths in a binary tree that sums to K

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int a){
        this->data = a;
        left = right = NULL;
    }
};

void print(vector<int> &v){
    for(int i : v) cout << i << " ";
    cout << endl;
}

void move(Node* root, int &k, vector<int> &path, int pathSum){
    if(!root) return;
    path.push_back(root->data);
    pathSum += root->data;

    if(pathSum == k) print(path);

    move(root->left, k, path, pathSum);
    move(root->right, k, path, pathSum);
    path.pop_back();
}

void printPathsKSum(Node* root, int &k){
    if(!root) return;
    vector<int> path;
    move(root, k, path, 0);
    printPathsKSum(root->left, k);
    printPathsKSum(root->right, k);
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printPathsKSum(root, k);
    return 0;
}