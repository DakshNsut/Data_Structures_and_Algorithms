#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void preorder(struct node* root){
    if (root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void Inorder(struct node* root){
    if (root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

struct node* createnode(int data){
    struct node* n;
    n= (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main(){
    struct node* p = createnode(4);
    struct node* p1 = createnode(1);
    struct node* p2 = createnode(6);
    struct node* p11 = createnode(5);
    struct node* p12 = createnode(2);

    // Linking the nodes
    p->left=p1;
    p->right=p2;

    p1->left=p11;
    p1->right=p12;

    // Only needed to pass root node as an argument
    printf("Preorder Traversal\n");
    preorder(p);
    printf("\nPostorder Traversal\n");
    postorder(p);
    printf("\nInorder Traversal\n");
    Inorder(p);
    return 0;
}