#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element= %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct node* head;
    struct node* second;

    //Allocating memory to node of linked list from heap
    head=(struct node*) malloc(sizeof(struct node));
    second=(struct node*) malloc(sizeof(struct node));

    //First to second node
    head->data=5;
    head->next=second;

    //terminate the list
    second->data=7;
    second->next=NULL;

    linkedlistTraversal(head);

    return 0;
}