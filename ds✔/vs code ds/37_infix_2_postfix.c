#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char value){
    if(isFull(ptr))
    {
        printf("Stack Overflow! cannot push %d to stack\n",value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }   
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *ptr, int pos){
    // To move to positions down the top, we minus position from top i.e. end and add 1 to it
    int arrayInd = ptr->top -pos + 1; 

    if(arrayInd < 0) 
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}

//Parenthesis Match (Return 1 means true balanced)
int parenthesisMatch(char *exp){
    //Create and initialize the stack
    struct stack *sp;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size*sizeof(char));

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='('){
            push(sp,exp[i]);
        }    
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0; //Unbalanced
            }
            pop(sp);
        }
    }    

    //Check at End Of Char Arr Expression
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;        //Unbalanced
    }
}

int precedence(char ch){
    if(ch=='*' || ch=='/')
        return 3;
    else if(ch=='+' || ch=='-')
        return 2;
    else 
        return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch =='-' || ch=='*' || ch=='/')
        return 1;
    else
        return 0;
} 

char *infixToPostfix(char *infix){
    struct stack *sp = (struct stack*) malloc(sizeof(struct stack)); // Stack pointer to temporary store operators
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char *postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j=0; // Track postfix addition
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char *infix = "x-y/z-k*d";
    printf("Postfix is %s", infixToPostfix(infix));
    return 0;
}  