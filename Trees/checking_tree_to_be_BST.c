#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Checking a tree to be a Binary Search Tree
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node*n;
    n= (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int IsBST(struct node* root){
    // This means the value of this variable will be saved for the next call of this function
    static int prev = INT_MIN;
    if(root != NULL){
        if(!IsBST(root->left)){
            // This means the traversal elements are not sorted
            return 0;
        }

        // If we use prev as struct node* =NULL, then doing the below comparison for the first element will give error, that is why we say (prev!=NULL && root->data<=prev->data).
        // This is not needed here, because INT_MIN returns a number and the below comparison for the first element wont give an error.

        // prev is actually root->left (previous in ** inorder traversal **)
        if(root->data <= prev){
            return 0;
        }
        prev=root->data;
        if(!IsBST(root->right)){
            return 0;
        }
    }

    // For empty tree/sub-tree
    else{
        return 1;
    }
    return 1;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

void main(){
    // Creating the nodes
    struct node* p = createnode(5);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(7);
    struct node* p11 = createnode(2);
    struct node* p12 = createnode(4);

    // Linking the nodes
    p->left = p1;
    p->right = p2;

    p1->left = p11;
    p1->right = p12;

    if (IsBST(p)){
        printf("This is a Binary Search Tree");
    }
    else{
        printf("This is not a Binary Search Tree");
    }

    return;
}