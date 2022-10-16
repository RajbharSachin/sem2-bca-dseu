#include <stdio.h>
#include <stdlib.h>

struct cqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct cqueue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct cqueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct cqueue *q, int value){
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enqued element: %d\n", value);
        q->r = (q->r+1)%q->size; //Circular increment
        q->arr[q->r] = value;
    }
}

int dequeue(struct cqueue *q){
    int val=-1;
    if(isEmpty(q)) 
    {
        printf("No element to dequeue\n");
    }
    else
    {
        q->f = (q->f+1)%q->size; //Circular increment
        val = q->arr[q->f];       
    }
    return val;
}
int main(){
    struct cqueue q;
    q.size = 4;  // size-1 elemnts in cqueue bcz of 0 reserved for is full condition
    q.f = q.r = 0;
    q.arr = (int *) malloc(q.size*sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 14);   
    enqueue(&q, 1);


    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    enqueue(&q, 12);
    enqueue(&q, 14);   
    enqueue(&q, 1);
    
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }
    return 0;
}