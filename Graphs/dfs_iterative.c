#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    struct stack *s;
    s->size = 7;
    s->top = -1;
    s->arr = (int*) malloc(s->size * sizeof(int));

    int a[7][7]= {
        {0,1,1,0,0,0,0}, // for element 0
        {1,0,1,0,0,0,0}, // for element 1
        {1,1,0,1,1,0,0}, // for element 2
        {1,0,1,0,1,0,0}, // for element 3
        {0,0,1,1,0,1,1}, // for element 4
        {0,0,0,0,1,0,0}, // for element 5
        {0,0,0,0,1,0,0}  // for element 6
    };

    int visited[7] = {0,0,0,0,0,0,0};
    int i = 0;
    visited[i] = 1;
    push(s,i);
    while (!(isEmpty(s))){
        // we are taking that element which is at top, only one element or one direction, so we will printf only the topmost element
        // in bfs we used to visit all connected nodes, so we had to printf in loop for all connected nodes
        int node = pop(s);
        printf("%d ", node);
        for (int j = 0; j < 7; j++){
            if (a[node][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                push(s, j);
            }
        }
    }
    return 0;
}

// Time Complexity: O(V+E)
// Auxiliary space: O(1)