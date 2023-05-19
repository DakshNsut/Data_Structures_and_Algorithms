#include <iostream>
#include <vector>
using namespace std;

// flatten a bst to linked list having elements in sorted form

struct interval{
    int low;
    int high;
};

struct Node{
    Node* left, *right;
    int data;
    Node(int a){
        data = a;
        left = right = NULL;
    }
};

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->left;
    }
    cout << endl;
}

void flatten(Node* root, Node* &head, Node* &tail){
    if(!root) return;
    flatten(root->left,head,tail);
    if(!head){
        head = root;
        tail = root;
    }
    else{
        tail->left = root;
        tail = root;
    }
    flatten(root->right,head,tail);
}

// Time Complexity: O(n)
// Auxiliary space: O(h)

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Node* head = NULL;
    Node* tail = NULL;
    flatten(root,head, tail);
    print(head);

    return 0;
}