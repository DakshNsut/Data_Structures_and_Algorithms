#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}N;

int isEmpty(N* f){
    if (f==NULL)
    {
        printf("Queue Empty");
        return 1;
    }
    return 0;
}

int isFull(){
    N*n;
    if (n==NULL)
    {
        printf("Queue Full");
        return 1;
    }
    return 0;
}

N* enqueue(N* f,N* r,int val){
    if (isFull())
    {
        return NULL;
    }
    N*ptr=(N*)malloc(sizeof(N*));
    ptr->data=val;
    ptr->next=NULL;

    if (isEmpty(f))
    {
        f=ptr;
        r=ptr;
        return NULL;
    }

    r->next=ptr; // else case
    r=ptr;
    return r;
}

N* dequeue(N*f){
    if(isEmpty(f)){
        return NULL;
    }

    N*ptr;
    ptr = f;
    f=f->next;
    free(ptr);
    return f;
}

void Traversal(N *f)
{
    N*ptr = f;
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    N* first = (N*)malloc(sizeof(N*));
    N* second = (N*)malloc(sizeof(N*));
    N* third = (N*)malloc(sizeof(N*));
    N* fourth = (N*)malloc(sizeof(N*));

    N*f=first;
    N*r=fourth;

    first->data=3;
    first->next=second;

    second->data=12;
    second->next=third;

    third->data=13;
    third->next=fourth;

    fourth->data=31;
    fourth->next=NULL;

    r = enqueue(f,r,11);
    Traversal(f);
    f = dequeue(f);
    Traversal(f);
}