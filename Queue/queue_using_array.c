#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int back;
    int front;
    int* arr;
};

int isFull(struct queue* q){
    if(q->back == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue* q){
    if(q->front == q->back){
        return 1;
    }
    return 0;
}

int enqueue(struct queue* q, int element){
    printf("%d\n",q->back);
    if(isFull(q)){
        printf("Queue Overflow");
        return 0;
    }
    q->back++;
    q->arr[q->back] = element;
    return 1;
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow");
        return 0;
    }
    q->front++;
    int a = q->arr[q->front];
    return a;
}

int traversal(struct queue* q){
    for (int i = q->front+1; i <= q->back; i++)
    {
        printf("%d\n",q->arr[i]);
    }
    return 0;
}

int main(){
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->size = 5;
    q->back = -1;
    q->front = -1;
    q->arr = (int*) malloc (q->size * sizeof(int*));

    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);
    traversal(q);

    return 0;
}