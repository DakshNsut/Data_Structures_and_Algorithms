#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* CreateNode(int data){
    struct node* n;
    // We dynamically allocate memory when we dont want to calculate how much memory this user defined data type takes.
    n = (struct node*) malloc(sizeof(struct node*));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int main(){
    //Constructing root node - Using user defined function
    struct node* p = CreateNode(2);

    //Constructing second node - Using user defined function
    struct node* p1 = CreateNode(4);

    //Constructing third node - Using user defined function
    struct node* p2 = CreateNode(1);

    // Linking created nodes
    p->left = p1;
    p->right = p2;

    // Printing data for each node in Tree format
    printf("\t%d\n\n%d\t\t%d",p->data,p1->data,p2->data);

    return 0;
}