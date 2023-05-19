#include <iostream>
#include <vector>
using namespace std;

// to convert BST to min heap

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void print(Node* root){
    if(!root) return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void storeInorder(Node* root, vector<int> &res){
    if(!root) return;
    storeInorder(root->left, res);
    res.push_back(root->data);
    storeInorder(root->right, res);
}

void buildMinHeap(Node* root, int &i, vector<int> &in){
    if(!root) return;
    root->data = in[i++];
    buildMinHeap(root->left, i, in);
    buildMinHeap(root->right, i, in);
}

void BSTtoMinHeap(Node* root){
    vector<int> inorder;
    storeInorder(root, inorder);

    int i = 0;
    buildMinHeap(root, i, inorder);
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    BSTtoMinHeap(root);
    print(root);
    return 0;
}