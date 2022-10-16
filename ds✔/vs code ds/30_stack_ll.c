#include <stdio.h>
#include <stdlib.h>

//Creation
struct node
{
    int data;
    struct node *next;
};

//isEmpty & isFull    
int isEmpty(struct node *top){
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *top){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Insertion
struct node* push(struct node* top, int value){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    if(isFull(top))
    {
        printf("Stack Overflow! cannot push %d to stack\n",value);
    }
    else
    {
        n->data = value;
        n->next = top;
        top = n;
        return top;
    }
}

//Deletion
int pop(struct node** top){
    if(isEmpty(*top))
    {
        printf("Stack Underflow! cannot pop from stack\n");
    }
    else
    {
        struct node *n = *top;
        int value = n->data;
        *top = (*top)->next;
        free(n);
        return value;
    }
}

//Display
void linkedlistTraversal(struct node *top)
{
    while (top != NULL)
    {
        printf("Element= %d\n", top->data);
        top = top->next;
    }
    printf("\n");
}

//Peek (traverse with index)
int peek(struct node *top, int pos){ 
    if(isEmpty(top)) 
    {
        printf("Stack Empty!\n");
        return -1;
    }
    else if(pos<=0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        int i=0;
        while (i < pos-1 && top != NULL)
        {
            top = top->next;
            ++i;
        }

        if(top != NULL)
        {
            return top->data;
        }
        else
        {
            printf("Not a valid position for the stack\n");
            return -1;  
        }  
    }
}

int stackTop(struct node *top){
    return top->data;
}

int stackBottom(struct node *top){
    while (top->next != NULL)
    {
        top = top->next;
    }
    return top->data;
}

int main(){
    struct node* top = NULL;
    top = push(top,78);
    top = push(top,7);
    top = push(top,8);
    linkedlistTraversal(top);

     // used '&' for above-top's-reference to get change of address of updated top 
     //OR
     // make top a global variable
    int element = pop(&top);   
    printf("Popped element is %d\n", element);
    linkedlistTraversal(top);

    // Traversal
    // for (int j = 1; j <= sp->top + 1; j++)
    // {
        printf("The value at position %d is %d\n", 3, peek(top, 3));
    // }
    linkedlistTraversal(top);
    
    printf("The top most value of the stack is %d\n",stackTop(top));
    printf("The bottom most value of the stack is %d\n",stackBottom(top));

    return 0;
}