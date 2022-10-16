#include <stdio.h>
#include <stdlib.h>

//Creation
struct node
{
    int data;
    struct node *next;
};

struct node* f=NULL;
struct node* r=NULL;

//Insertion
void insertAtEnd(int value){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    if(ptr == NULL)
    { 
        printf("Queue Full");
    }
    else
    {
        ptr->data = value;
        ptr->next=NULL;
        if(f==NULL)   //if queue empty
        {
            f=r=ptr;  
        }
        else
        {
            r->next = ptr;
            r=ptr;
        }
    }
}

//Deletion
int deleteFirstNode(){
    int value=-1;
    struct node* ptr = f;
    
    // check for queue empty
    if(f==NULL)
    {
        printf("Queue Empty\n");
    }
    else
    {
        value = ptr->data;
        f = f -> next;
        free(ptr);
    }
    return value;
}

//Display
void linkedlistTraversal(struct node *ptr)
{
    printf("\nPrinting the elements of the linked list\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    linkedlistTraversal(f);
    printf("Dequeued element: %d\n",deleteFirstNode());
    insertAtEnd(4);
    linkedlistTraversal(f);
    return 0;
}
