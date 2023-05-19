#include <iostream>
#include <climits>
using namespace std;

// find maximum among sum of all subtrees

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int a){
        this->data = a;
        left = right = NULL;
    }
};

int getSubtreeSum(Node* root, int &ans){
    if(!root) return 0;

    int sum = root->data;
    sum += getSubtreeSum(root->left, ans);
    sum += getSubtreeSum(root->right, ans);

    ans = max(ans, sum);
    return sum;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    int ans = INT_MIN;
    getSubtreeSum(root, ans);
    cout << ans;
    return 0;
}