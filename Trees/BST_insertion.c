#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
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

void Insertion(struct node *root, int val){
    struct node *prev = NULL;
    // Finding where it should be inserted
    while (root != NULL){
        prev = root;
        if (root->data == val){
            printf("Element can't be inserted, beacuse it was already present");
            return;
        }
        else if (val < root->data)
            root = root->left;

        else
            root = root->right;
    }

    // Creating the node
    struct node *ptr = CreateNode(val);

    // Linking/ Inserting the node
    if (prev->data > val)
        prev->left = ptr;
    else
        prev->right = ptr;
}

// Time Complexity: O(n) - worst case
// Auxiliary space: O(1)

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

    int value = 11;
    Insertion(p,value);
    printf("The element added was: %d",p->right->right->data);
    return 0;
}
