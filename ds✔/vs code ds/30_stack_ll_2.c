#include <stdio.h>
#include <stdlib.h>

//Creation
struct node
{
    int data;
    struct node *next;
};
//--------GLOBAL Top---------//
struct node* top = NULL;

//isEmpty & isFull    
int isEmpty(struct node *tp){
    if(tp == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *tp){
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

// stackTop & stackBottom
int stackTop(struct node *tp){
} 

int stackBottom(struct node *tp){
}

//Insertion
struct node* push(struct node* tp, int value){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    if(isFull(tp))
    {
        printf("Stack Overflow! cannot push %d to stack\n",value);
    }
    else
    {
        n->data = value;
        n->next = tp;
        tp = n;
        return tp;
    }
}

//Deletion
int pop(struct node* tp){
    if(isEmpty(tp))
    {
        printf("Stack Underflow! cannot pop from stack\n");
    }
    else
    {
        struct node *n = tp;
        int value = n->data;
        top = tp->next;
        free(n);
        return value;
    }
}

//Display
void linkedlistTraversal(struct node *tp)
{
    while (tp != NULL)
    {
        printf("Element= %d\n", tp->data);
        tp = tp->next;
    }
    printf("\n");
}



int main(){
    top = push(top,78);
    top = push(top,7);
    top = push(top,8);
    linkedlistTraversal(top);
    
     // used '&' for above-top's-reference to get change of address of updated top 
     //OR
     // make top a global variable
    int element = pop(top);   
    printf("Popped element is %d\n", element);
    linkedlistTraversal(top);
    return 0;
}