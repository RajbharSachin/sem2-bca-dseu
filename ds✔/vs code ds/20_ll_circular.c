#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

//Insertion
struct node* insertAtBegin(struct node *head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    struct node* p = head->next;
    while(p->next!=head)
    {
        p = p->next;
    }
    // At this point p points to last node of circular linked list
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

struct node* insertInBetween(struct node* head, int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    struct node* p=head;
    int i=0;
    while(i!=index-1 && p->next!=head)
    {
        p = p->next;
        i++;
    }
    // p points to exact node of Circular ll

    
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node* insertAtEnd(struct node* head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    struct node* p=head;
    while(p->next!=head)
    {
        p = p->next;
    }
    // p points to last node

    p->next=ptr;
    ptr->next=head;
    return head;
}

struct node* insertAfterNode(struct node* head, struct node* prevnode, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}

//Deletion
struct node* deleteFirstNode(struct node* head){
    struct node* ptr = head; // node to free
    struct node *p = head;
    while(p->next!=head)
    {
        p=p->next;
    }
    // p points to last node

    head = head -> next;
    p->next=head;
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
    while(q->next != head)
    {
        q = q -> next;
        p = p -> next;
    }
    
    p->next = head;
    free(q);
    return head;
}

struct node* deleteGivenValueNode(struct node* head, int value){
    struct node* p = head;
    struct node* q = head->next;
    while(q->data != value && p->data !=value && q->next != head)
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
        struct node* ptr = head; // node to free
        struct node *p = head;
        while(p->next!=head)
        {
            p=p->next;
        }
        // p points to last node

        head = q;
        p->next=head;
        free(ptr);
    }
    else
    {
        printf("Not found in given list\n");
    }
    return head;
}

//Traversal
void linkedlistTraversal(struct node *head){
    struct node* ptr = head;
    do
    {
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

int main(){
    struct node* head;
    struct node* second;

    //Allocating memory to node of linked list from heap
    head=(struct node*) malloc(sizeof(struct node));
    second=(struct node*) malloc(sizeof(struct node));

    //Link First to second node
    head->data=5;
    head->next=second;

    //terminate the list
    second->data=7;
    second->next=head; // forming circle

    printf("Circular Linked List before Insertion:\n");
    linkedlistTraversal(head);

    printf("Circular Linked List after Insertion:\n");
    head = insertAtBegin(head,6);
    linkedlistTraversal(head);

    // head = insertInBetween(head,3,1); // willn't work for begin i.e. 0 index
    // linkedlistTraversal(head);

    // head = insertAtEnd(head,11);
    // linkedlistTraversal(head);

    // head = insertAfterNode(head, second, 12);
    // linkedlistTraversal(head);

    printf("Circular Linked List after Deletion:\n");
    head = deleteFirstNode(head);
    linkedlistTraversal(head);

    // head = deleteNodeInBetween(head,1); // fail for 0th node
    // linkedlistTraversal(head);

    // head = deleteLastNode(head);
    // linkedlistTraversal(head);

    // head = deleteGivenValueNode(head,6);
    // linkedlistTraversal(head);

    return 0;
}