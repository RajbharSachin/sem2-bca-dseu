#include <stdio.h>
#include <conio.h>

struct node
{
    int data;
    node *next;
};

class list
{
    node *head,*tail;
    public:
    list()
    {
        head=NULL;
        tail=NULL:
    }
    void insert(int);
    void display();
}

void insert(int item)
{
    node *temp=new node;
    temp->data=item;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void display()
{
    node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d ->",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    list obj;
    obj.display();
    obj.insert(2);
    obj.insert(5);
    obj.insert(10);
    obj.display();
    return 0;
}