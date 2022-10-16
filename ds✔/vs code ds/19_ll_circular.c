#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void lltraversal(struct node *ptr){
    struct node* p = ptr;
    while(p->next != ptr)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("%d ",p->data);
}

int main(){
    struct node* head,* second,* third;
    head->data = 1;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 1;
    third->next = head;

    lltraversal(head);
    return 0;
}