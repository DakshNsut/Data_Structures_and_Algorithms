#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int data){
    struct node *n;
    // We dynamically allocate memory when we dont want to calculate how much memory this user defined data type takes.
    n = (struct node *)malloc(sizeof(struct node *));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct node* InOrderPre(struct node* root){
    // InOrderPre = max element of left subtree
    root=root->left;
    // till right is empty, means we will find the rightmost element at end of this loop
    while (root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct node* Delete(struct node* root,int value){
    // Base condition - if root is empty
    if (root==NULL){
        return NULL;
    }

    // For a leaf node
    if (root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }

    // Searching the node and making space for its deletion
    if (value<root->data){
        root->left=Delete(root->left,value);
    }

    else if (value>root->data){
        root->right=Delete(root->right,value);
    }

    // We got the element to be deleted, now we will delete it/replace it with its InorderPredecessor,
    // but by checking if it is a leaf node, if node we will do the above process again (means will will call the function again)
    else{
        struct node* Ipre;
        Ipre=InOrderPre(root);
        root->data=Ipre->data;
        // root->left because Ipre will be found at left subtree of root at the rightmost node(RULE!!!)
        root->left=Delete(root->left,Ipre->data);
    }
    return root;
}

// Time Complexity: O(n) - worst case
// Auxiliary space: O(1)

void Inorder(struct node* root){
    if (root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

int main(){
    // It should be a binary search tree
    // Constructing the nodes
    struct node *p = CreateNode(5);
    struct node *p1 = CreateNode(3);
    struct node *p2 = CreateNode(6);
    struct node *p11 = CreateNode(1);
    struct node *p12 = CreateNode(4);

    // Linking created nodes
    p->left = p1;
    p->right = p2;
    p1->left = p11;
    p1->right = p12;

    int value = 4;
    Inorder(p);
    Delete(p,value);
    printf("\n");
    Inorder(p);
    return 0;
}