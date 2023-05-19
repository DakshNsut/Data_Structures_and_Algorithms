#include <stdio.h>
#include <stdlib.h>
 
struct stack{
    int top;
    int size;
    char* arr;
};

int isEmpty(struct stack *sp){
    if (sp->top==-1){
        return 1;
    }
    return 0;

}

int isFull(struct stack *sp){
    if (sp->top==sp->size-1){
        return 1;
    }
    return 0;

}

char pop(struct stack *sp){
    if (isEmpty(sp)==1){
        return 0;
    }

    char element = sp->arr[sp->top];
    sp->top--;
    return element;
}

int push(struct stack *sp,int element){
    if(isFull(sp) == 1){
        return 0;
    }

    sp->arr[++sp->top] = element;
    return 1;
}

int multiple_parantheses_matching(char* exp){
    struct stack* sp;
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    for(int i=0; exp[i] != '\0'; i++){
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(sp,exp[i]);
        }

        else if (exp[i] == ')'||exp[i] == ']'||exp[i] == '}'){
            char element = pop(sp);
            if(exp[i] == ')'){
                if (element != '('){
                    return 0;
                }
            }
            else if(exp[i] == ']'){
                if (element != '['){
                    return 0;
                }

            }
            else if(exp[i] == '}'){
                if (element != '{'){
                    return 0;
                }
            }
        }
    }

    if (sp->top == -1){
        return 1;
    }
    return 0;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)


int main(){
    char exp[] ="(7-11+{23-8*2}-[33+1])";
    printf("parantheses matcher running.....\n");
    if(multiple_parantheses_matching(exp)){
        printf("Parantheses matched");
        return 0;
    }
    printf("Parantheses not matched");
    return 0;
}