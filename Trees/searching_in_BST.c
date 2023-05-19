#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* CreateNode(int data){
    struct node* n;
    // We dynamically allocate memory when we dont want to calculate how much memory this user defined data type takes.
    n=(struct node*)malloc(sizeof(struct node*));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
}

struct node* RecurSearch(struct node* p , int val){
    // For end of tree
    if(p==NULL)
        return NULL;

    if (p->data==val)
        return p;

    else if(val < p->data)
        return RecurSearch(p->left,val);

    else
        return RecurSearch(p->right,val);
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(n)

struct node* IterSearch(struct node* p , int val){
    while(p != NULL){
        if (p->data == val)
            return p;

        else if(val < p->data)
            p = p->left;

        else
            p = p->right;
    }
    // For end of tree
    return NULL;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(1)

int main(){
    // It should be a binary search tree
    // Constructing root node
    struct node* p = CreateNode(2);
    struct node* p1 = CreateNode(0);
    struct node* p2 = CreateNode(6);

    // Linking created nodes
    p->left = p1;
    p->right = p2;

    int data = 4 ;
    struct node* ptr1 = IterSearch(p,data);
    if (ptr1 != NULL){
        printf("%d found\n", ptr1->data);
    }
    else{
        printf("%d not found\n", data);
    }

    struct node* ptr2 = RecurSearch(p,data);
    if (ptr2 != NULL){
        printf("%d found\n", ptr2->data);
    }
    else{
        printf("%d not found\n", data);
    }
    return 0;
}