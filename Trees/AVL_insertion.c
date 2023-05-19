#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Defining the structure of the node datatype
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
}sn;

struct node* CreateNode(int data){
    struct node* n = (sn*)malloc(sizeof(sn));
    n->left=NULL;
    n->right=NULL;
    n->data=data;
    // Height of leaf node=0
    n->height=0;
}

int GetHeight(sn* p){
    if (p==NULL){
        return 0;
    }
    // This +1 was because of the dry run or experimental running
    return p->height+1;
}

int max(int a,int b){
    return a>b?a:b;
}

sn* LeftRotate(sn* x){
    sn* y=x->right;
    sn* T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=max(GetHeight(x->left),GetHeight(x->right));
    y->height=max(GetHeight(y->left),GetHeight(y->right));

    return y;
}

sn* RightRotate(sn* y){
    sn* x=y->left;
    sn* T2=x->right;

    x->right=y;
    y->left=T2;

    x->height=max(GetHeight(x->left),GetHeight(x->right));
    y->height=max(GetHeight(y->left),GetHeight(y->right));

    return x;
}

int GetBalanceFactor(sn* p){
    if (p==NULL){
        return 0;
    }
    return GetHeight(p->left)-GetHeight(p->right);
}

sn* insert(sn* r,int value){
    if(r==NULL)
        return(CreateNode(value));
    if (r->data<value){
        r->right=insert(r->right,value);
    }
    else if(r->data>value){
        r->left=insert(r->left,value);
    }

    r->height=1+max(GetHeight(r->left),GetHeight(r->right));


    int BF=GetBalanceFactor(r);

    // LL
    if (BF>1 && value<r->left->data){
        return RightRotate(r);
    }

    // RR
    if (BF<-1 && value>r->right->data){
        return LeftRotate(r);
    }

    // LR
    if (BF>1 && value<r->left->data){
        r->left=LeftRotate(r->left);
        return RightRotate(r);
    }

    // RL
    if (BF<-1 && value<r->right->data){
        r->right=RightRotate(r->right);
        return LeftRotate(r);
    }

    return r;
}

// Time Complexity: O(logn)
// Auxiliary space: O(1)

void preOrder(sn * m){
    if(m!=NULL){
		printf("%d",m->data);
		preOrder(m->left);
		preOrder(m->right);
    }
}

int main(){
    sn* root = NULL;

    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,6);
    root = insert(root,3);

    preOrder(root);
    return 0;
}