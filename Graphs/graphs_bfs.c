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

int enqueue(struct queue* q,int element){
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
    struct queue* q;
    q->size = 100;
    q->back = -1;
    q->front = -1;
    q->arr = (int*)malloc(q->size*sizeof(int*));

    // Implementing BFS

    // Representation of the GRAPH
    int size = 7; // no. of elements in the graph
    // The elements in the graph will be equal to the indices
    // for two nodes to be connected, we write 1 & otherwise 0.
    int graph[7][7] = {
        {0,1,1,0,0,0,0}, // for element 0
        {1,0,1,0,0,0,0}, // for element 1
        {1,1,0,1,1,0,0}, // for element 2
        {1,0,1,0,1,0,0}, // for element 3
        {0,0,1,1,0,1,1}, // for element 4
        {0,0,0,0,1,0,0}, // for element 5
        {0,0,0,0,1,0,0}  // for element 6
    };

    // the source node
    int s = 1;
    // the visited value for all nodes will be stored in an array, 0 for not visited and 1 otherwise
    int visited[7] = {0,0,0,0,0,0,0};
    // the node where dequeued node will be stored
    int node;

    // visiting the source node
    printf("%d ",s);
    visited[s] = 1;
    // For exploration
    enqueue(q,s);

    while (!isEmpty(q))
    {
        node = dequeue(q);
        for(int j=0; j<7; j++){
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                // visiting j
                printf("%d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }

    return 0;
}

// Time Complexity: O(V+E)
// Auxiliary space: O(1)