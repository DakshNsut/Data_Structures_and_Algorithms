#include<malloc.h>

typedef struct stack{
    int top;
    int size;
    char* arr;
}st;

int push(st*sp,int element){
    if(sp->top==sp->size-1){
        printf("Stack Overflow");
        return 0;
    }
    sp->arr[++sp->top]=element;
    return 1;
}

char pop(st*sp){
    if(sp->top==-1){
        printf("Stack Underflow");
        return 0;
    }
    char element=sp->arr[sp->top];
    sp->top--;
    return element;
}

int checking_precedence(st*sp){
    int prec2;
    int element=sp->arr[sp->top];
    if (element=='-'||element=='+')
    {
        prec2=1;
    }
    else if(element=='*'||element=='/'){
        prec2=2;
    }
    return prec2;
}

char* infix_to_postfix(char *exp,st *sp,char*postfix_exp){
    int j=0;
    printf("REACHED2");
    for (int i=0; exp[i]!='\0' ;){
        printf("\nREACHED3-- %c",exp[i]);
        if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'){
            int prec1;
            if (exp[i]=='-'||exp[i]=='+'){
                prec1=1;
            }
            else if(exp[i]=='*'||exp[i]=='/'){
                prec1=2;
            }

            int prec2 = checking_precedence(sp);

            if(prec1 > prec2){
                push(sp,exp[i]);
                i++; //Going to next element only if push happens
            }
            else{
                printf("\n%c %c",sp->arr[0],sp->arr[1]);
                postfix_exp[j]=pop(sp);
                printf("\npopped %c",postfix_exp[j]);
                j++;
                // didnt do i++ because we dont want to go to next element, because this element is not at any place
            }
        }
        else{
            postfix_exp[j]=exp[i];
            j++;
            i++; //Going to next element only if push happens
        }
        printf("\nREACHED4-- %c",exp[i]);
    }

    while (sp->top != -1){
        postfix_exp[j]=pop(sp);
        j++;
    }

	return postfix_exp;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

char* traversal(char* postfix_exp){
    for (int j = 0; postfix_exp[j]!='\0'; j++){
        printf("%c",postfix_exp[j]);
    }
}

int main(){
    st* sp;
    sp->top=-1;
    sp->size=10;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char *exp="x-y/z-k*d";
    char *postfix_exp=(char*)malloc(sp->size*sizeof(char));
    printf("REACHED1");
    char *postfix_exp2=infix_to_postfix(exp,sp,postfix_exp);
    printf("\nREACHED5\nPostfix expression is:\n");
    traversal(postfix_exp2);
    return 0;
}