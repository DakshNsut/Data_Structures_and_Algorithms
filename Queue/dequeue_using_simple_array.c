#include <stdio.h>
#include <stdlib.h>

// simple dequeue implementation

struct queue{
    int size;
    int *arr;
    int f;
    int r;
};

int isempty(struct queue *q){
    if (q->r == -1){
        return 1;
    }
    return 0;
}
int isFull(struct queue *q){
    if (q->r == q->size - 1){
        return 1;
    }
    return 0;
}
void displaylist(struct queue *ptr){
    if (isempty(ptr)){
        printf("Queue Underflow");
        return;
    }

    printf("Elements of queue are\n");
    int i = ptr->f;
    if (i==-1){
        i=0;
    }
    
    while (i <= ptr->r){
        printf("%d\n", ptr->arr[i]);
        i++;
    }
}

void enqueueR(struct queue *ptr, int value)
{
    if (isFull(ptr)){
        printf("Queue is full\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r] = value;
    }
}

void enqueuef(struct queue *ptr, int value)
{
    if (isFull(ptr)){
        printf("Queue is full\n");
    }
    else{
        ptr->f--;
        ptr->arr[ptr->f] = value;
    }
}
int dequeueR(struct queue *ptr)
{
    int x = -1;
    if (isempty(ptr)){
        printf("Queue is Empty\n");
    }
    else{

        x = ptr->arr[ptr->r];
        ptr->r--;
    }
    return x;
}
int dequeuef(struct queue *ptr) 
{
    int x = -1;
    if (isempty(ptr)){
        printf("Queue is Empty\n");
    }
    else{
        if (ptr->f == -1){
            ptr->f++;
        }
        x = ptr->arr[ptr->f];
        ptr->f++;
    }
    return x;
}

int main(){
    struct queue *de = (struct queue*) malloc(sizeof(struct queue));
    de->size = 7;
    de->arr = (int *)malloc(de->size * sizeof(int));
    de->f = -1;
    de->r = -1;
    enqueueR(de, 2);
    enqueueR(de, 4);
    enqueueR(de, 6);
    displaylist(de);
    printf("deleted %d\n", dequeueR(de));
    printf("deleted %d\n", dequeuef(de));
    enqueuef(de, 3);
    displaylist(de);
    return 0;
}