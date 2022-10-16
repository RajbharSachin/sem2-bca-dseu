#include <stdio.h>
#include <stdlib.h>

struct DEqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

void enqueueF(struct DEqueue *q, int value){
    if(q->f == -1)
    {
        printf("Queue Overflow front\n");
    }
    else
    {
        q->f--;
        q->arr[q->f] = value;  
        printf("Enqueued Element from front %d\n",value);
    }
}

void enqueueR(struct DEqueue *q, int value){
    if(q->r == q->size-1)
    {
        printf("Queue Overflow rear\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
        printf("Enqueued Element from rear %d\n",value);
    }
}

int dequeueF(struct DEqueue *q){
    int value=-1;
    if(q->f == q->r) // isEmpty()
    {
        printf("Queue Underflow front\n");
    }
    else
    {
        q->f++;
        value = q->arr[q->f];       
    }
    return value;
}

int dequeueR(struct DEqueue *q){
    int value=-1;
    if(q->r == -1) // isEmpty()
    {
        printf("Queue Underflow rear\n");
    }
    else
    {
        
        value = q->arr[q->r];    
        q->r--;   
    }
    return value;
}

int main(){
    struct DEqueue q;
    q.size = 3;
    q.f = q.r = -1;
    q.arr = (int *) malloc(q.size*sizeof(int));

    // Enqueue few elements
    enqueueR(&q, 12);
    enqueueR(&q, 14);   
    enqueueR(&q, 1);
    printf("Dequeuing element at front %d\n", dequeueF(&q));
    enqueueF(&q, 3);
    printf("Dequeuing element at rear %d\n", dequeueR(&q));
    /*if once queue gets full : f=r at end & r=size-1 also
     then both empty full will be printed */
    // if(isEmpty(&q)){
    //     printf("Queue is empty\n");
    // }
    // if(isFull(&q)){
    //     printf("Queue is Full\n");
    // }
    return 0;
}