#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top = -1;
int size = 10;
char postfix[] = "215-+";

void push(char item){
    if (top == size - 1){
        printf("Satck Overflow");
        return;
    }
    stack[++top] = item;
}

int pop(){
    if (top == -1){
        printf("Stack Underflow");
    }
    else{
        top--;
        return stack[top+1];
    }
}

void stack_traversal(){
    for(int i=0;i<=top;i++){
        printf("%d",stack[i]);
    }
    printf("\n");
}

int postfix_evaluate(){
    for (int i = 0; postfix[i]!='\0'; i++){
        if (postfix[i] == '+'){
            int a = pop();
            int b = pop();
            char item=b+a;
            push(item);
        }

        else if (postfix[i] == '-'){
            int a = pop();
            int b = pop();
            int item= b-a;
            push(item);
        }

        else if (stack[i] == '*'){
            int a = pop() - '0';
            int b = pop() - '0';
            char item=(b*a);
            push(item);
        }

        else if (postfix[i] == '/'){
            int a = pop() - '0';
            int b = pop() - '0';
            char item=(b/a);
            push(item);
        }

        else{
            push((int)postfix[i]-48);
        }
    }
    return pop();
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    printf("The evaluation of the postfix expression results in: %d",postfix_evaluate(postfix));
}