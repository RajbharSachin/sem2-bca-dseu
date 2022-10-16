#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;  //reserved memory
    int used_size;   //used memory
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *) malloc(tSize*sizeof(int));   
                        //star or arrow operator
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *) malloc(tSize*sizeof(int));
}

void setVal(struct myArray *a){
    int n;
    for(int i=0; i<a->used_size; ++i)
    {
        printf("Enter element %d: ", i);
        scanf("%d",&( (a->ptr)[i] ));
    }
}

void show(struct myArray *a){
    for(int i=0; i<a->used_size; ++i)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}

void eleInsert(struct myArray *a, int ele, int pos){
    for(int i=a->used_size; i>=pos-1; --i){
        (a->ptr)[i+1] = (a->ptr)[i];
    }
    (a->ptr)[pos-1] = ele;
    (a->used_size)+=1;
}

void eleDelete(struct myArray *a, int pos){
    for(int i=pos; i<a->used_size; ++i){
        (a->ptr)[i-1] = (a->ptr)[i];
    }
    (a->used_size)-=1;
}
int main(){
    struct myArray marks;
    createArray(&marks,10,2);

    printf("\nSetting values\n");
    setVal(&marks);
    show(&marks);

    printf("\nInsertion running\n");
    eleInsert(&marks, 10, 1);
    show(&marks);

    printf("\nDeletion running\n");
    eleDelete(&marks, 1);
    show(&marks);

    return 0;
}