#include<stdio.h>
#include<stdlib.h>
#define n 10
int queue[n];
int front=-1;
int rear=-1;

void enqueue(int x){
if(rear==n-1){
printf("overflow");
}
else if(front==-1&&rear==-1){
front=rear=0;
queue[rear]=x;
}
else{
rear++;
queue[rear]=x;
}
}

int dequeue(){
if(front==-1&&rear==-1){
printf("underflow");
}
else if (front==rear)
{
front=rear=-1;
}
else{
int val = queue[front];     
front++;
return val;
}
}

void display(){
if(front==-1&&rear==-1)
printf("queue is empty");
else
for(int i=front;i<=rear;i++){
printf("%d ",queue[i]);
}
}

int main(){
int choice, value;
printf("\nImplementation of Queue using array\n");
while (choice != 4) {
printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
printf("\nEnter your choice : ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("\nEnter the value to insert: ");
scanf("%d", &value);
enqueue(value);
break;
case 2:
printf("Popped element is :%d\n", dequeue());
break;
case 3:
display();
break;
case 4:
exit(0);
break;
default:
printf("\nWrong Choice\n");
}
}
return 0;
}