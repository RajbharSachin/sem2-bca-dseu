#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};

//Insertion
struct node* insertAtBegin(struct node *head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->prev=NULL;

    // link ptr & head
    ptr->next=head;
    head->prev=ptr;
    return ptr;

}

struct node* insertInBetween(struct node* head, int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    struct node* p=head;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    // p_prevnode points to index-1 node

    //link ptr in b/w p & p->next
    ptr->next=p->next;                      
    p->next=ptr;
    ptr->prev=p;
    /* set prev of ptr's next to ptr */
    if (ptr->next != NULL)
        ptr->next->prev = ptr;
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
    ptr->prev=p;
    return head;
}

struct node* insertAfterNode(struct node* head, struct node* prevnode, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    ptr->prev=prevnode;
    prevnode->next=ptr;
    /* set prev of ptr's next to ptr */
    if (ptr->next != NULL)
        ptr->next->prev = ptr;
    return head;
}

//Deletion
struct node* deleteFirstNode(struct node* head){
    struct node* ptr = head;
    head = head -> next;
    head->prev = NULL;
    free(ptr);
    return head;
}

struct node* deleteNodeInBetween(struct node* head, int index){
    struct node* p = head;
    struct node* q = head->next;
    int i=0;
    while(i!=index-1)
    {
        p = p -> next;
        q = q -> next;
        i++;
    }
    p->next = q->next;
    p->next->prev=p;
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
        if(q->next == NULL)
        {
            p->next = NULL;
        }
        else
        {
            p->next = q->next;
            p->next->prev=p;
        }
        free(q);
    }
    else if(p->data == value)
    {
        head = q;
        head->prev=NULL;
        free(p);
    }
    else
    {
        printf("Not found in given list\n");
    }
    return head;
}

//Traversal
void linkedlistTraversal(struct node *head){
    struct node *ptr = head;
    printf("Doubly Linked List in forward order:\n");
    while(ptr->next!=NULL)
    {
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("Element is %d\n",ptr->data);
    
    printf("Doubly Linked List in backward order:\n");
    do
    {
        printf("Element is %d\n",ptr->data);
        ptr = ptr->prev;
    }while(ptr!=NULL);

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
    head->prev=NULL;

    //terminate the list
    second->data=7;
    second->next=NULL;
    second->prev=head;

    printf("Linked List before Insertion:-\n");
    linkedlistTraversal(head);

    printf("\nLinked List after Insertion:-\n");
    head = insertAtBegin(head,6);
    linkedlistTraversal(head);

    // head = insertInBetween(head,3,1); // willn't work for begin i.e. 0 index
    // linkedlistTraversal(head);

    // head = insertAtEnd(head,11);
    // linkedlistTraversal(head);

    // head = insertAfterNode(head, head, 12);
    // linkedlistTraversal(head);

    printf("\nLinked List after Deletion:-\n");
    // head = deleteFirstNode(head);
    // linkedlistTraversal(head);

    // head = deleteNodeInBetween(head,1); // fail for 0th node
    // linkedlistTraversal(head);

    // head = deleteLastNode(head);
    // linkedlistTraversal(head);

    head = deleteGivenValueNode(head,5);
    linkedlistTraversal(head);


    return 0;
}