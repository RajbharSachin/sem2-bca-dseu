#include <stdio.h>
#include <stdlib.h>
#define null 0


//Structure is used to create the circular linked list
typedef struct CircularLinkedList
{
int data;
struct CircularLinkedList *next;
}node;


//Function to add the items to the linked list
node *getnode()
{
node *new;
int item;
printf("Enter the data ");
scanf("%d",&item);
new=(node*)malloc(sizeof(node));
new->data = item;
new->next = null;
return new;
}

//Method to traverse through a circular linked list
void *traverse(node*h)
{
    if(h==null)   //Checking if the linked list is empty
     {
          printf(“Empty Circular Linked List”);
     }
     else
     {
          node *q;
          q=h;
          while(q->next!=h)   //Traversing through the linked list
          { 
              q=q->next;
          }
    }
}

int main()
{
node *head, *q, *x;
int i,n,ch;
printf("Enter the number of nodes ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
        if(i==0)
        {
            head = getnode();
            head->next=head;
            q=head;
        }
        else
        {
            x=getnode();
            q->next=x;
            x->next=head; //Last element is linked to the first one
            q=x;
        }
}
traverse(head);
return 0;
}