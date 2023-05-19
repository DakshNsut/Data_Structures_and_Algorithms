#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int back;
    int front;
    int *arr;
};

int isFull(struct queue* q){
    if((q->back+1)%q->size==q->front){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue* q){
    if(q->front==q->back){
        return 1;
    }
    return 0;
}

int enqueue(struct queue* q,int element){
    if(isFull(q)){
        printf("Queue Overflow\n");
        return 0;
    }
    q->back=(q->back+1)%q->size;
    q->arr[q->back]=element;
    return 1;
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return 0;
    }
    q->front=(q->front+1)%q->size;
    int a = q->arr[q->front];
    return a;
}

void traversal(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow");
        return;
    }
    for (int i = q->front+1;i!=(q->back+1)%q->size;i = (i+1)%q->size)
    {
        printf("%d ",q->arr[i]);
    }
    return;
}

int main(){
    struct queue* q = (struct queue *) malloc(sizeof(struct queue));
    q->size = 10;
    q->front = 0;
    q->back = 0;
    q->arr = (int*)malloc(q->size*sizeof(int*));

    enqueue(q, 12); // Adding at index 1
    enqueue(q, 15);
    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    // printf("Dequeuing element %d\n", dequeue(q));
    enqueue(q, 45); // Adding at index 0
    enqueue(q, 45); // Adding at index 1
    // enqueue(q, 45); // Adding at index 2  b=1,f=2 FULL condition!!!
    printf("\nAll elements\n");
    traversal(q);

    return 0;
}