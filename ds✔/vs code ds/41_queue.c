#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int value){
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)) // isEmpty()
    {
        printf("No element to dequeue\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];       
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 3;
    q.f = q.r = -1;
    q.arr = (int *) malloc(q.size*sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 14);   
    enqueue(&q, 1);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    /*if once queue gets full : f=r at end & r=size-1 also
     then both empty full will be printed */
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }
    return 0;
}