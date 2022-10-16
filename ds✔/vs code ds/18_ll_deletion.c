#include <stdio.h>
#include <stdlib.h>

//Creation
struct node
{
    int data;
    struct node *next;
};

//Insertion
struct node* insertAtBegin(struct node *head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    ptr->next=head;
    return ptr;

}

struct node* insertInBetween(struct node* head, int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node* insertAtEnd(struct node* head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    struct node* p=head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* insertAfterNode(struct node* head, struct node* prevnode, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}

//Display
void linkedlistTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element= %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//Deletion
struct node* deleteFirstNode(struct node* head){
    struct node* ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct node* deleteNodeInBetween(struct node* head, int index){
    struct node* p = head;
    struct node* q = head->next;
    int i=0;
    while(i<index-1)
    {
        p = p -> next;
        q = q -> next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node* deleteLastNode(struct node* head){
    struct node* p = head;
    struct node* q = head->next;
    while(q->next != NULL)
    {
        q = q -> next;
        p = p -> next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

struct node* deleteGivenValueNode(struct node* head, int value){
    struct node* p = head;
    struct node* q = head->next;
    while(q->data != value && p->data !=value && q->next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else if(p->data == value)
    {
        head = q;
        free(p);
    }
    else
    {
        printf("Not found in given list\n");
    }
    return head;
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

    printf("Linked List before Insertion:\n");
    linkedlistTraversal(head);

    printf("Linked List after Insertion:\n");
    head = insertAtBegin(head,4);
    linkedlistTraversal(head);

    // head = insertInBetween(head,3,1); // willn't work for begin i.e. 0 index
    // linkedlistTraversal(head);

    // head = insertAtEnd(head,11);
    // linkedlistTraversal(head);

    // head = insertAfterNode(head, second, 12);
    // linkedlistTraversal(head);

    // printf("Linked List after Deletion:\n");
    // head = deleteFirstNode(head);
    // linkedlistTraversal(head);

    // head = deleteNodeInBetween(head,2); // fail for 0th node
    // linkedlistTraversal(head);

    // head = deleteLastNode(head);
    // linkedlistTraversal(head);

    // head = deleteGivenValueNode(head,4);
    // linkedlistTraversal(head);

    return 0;
}