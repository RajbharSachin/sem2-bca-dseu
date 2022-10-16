#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
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

void push(struct stack *ptr, int value){
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

int pop(struct stack *ptr){
    if(isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }   
    else
    {
        int value = ptr->arr[ptr->top];
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

int main(){
    // struct stack s;
    // s.size = 6;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size*sizeof(int));
    struct stack* sp;    //For easy reference in functions
    sp->size = 6;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size*sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    // Pushing an element manually
    sp->arr[0] = 1;
    sp->top++;
    // Push Op
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);
        push(sp, 7);
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
  
    // Pop Op
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));    
    printf("Popped %d from the stack\n", pop(sp));
    
    // Traversal
    // for (int j = 1; j <= sp->top + 1; j++)
    // {
        printf("The value at position %d is %d\n", 1, peek(sp, 1));
    // }

    printf("The top most value of the stack is %d\n",stackTop(sp));
    printf("The bottom most value of the stack is %d\n",stackBottom(sp));

    // Check if stack is empty
    // if(isEmpty(sp))
    // {
    //     printf("The stack is empty");
    // }
    // else
    // {
    //     printf("The stack is not empty");
    // }
    return 0;
}