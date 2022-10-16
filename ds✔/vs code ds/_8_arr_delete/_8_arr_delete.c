#include <stdio.h>

void main(){
    int a[10]={6,5,2,1,3,4};
    int pos=2;
    for(int i=pos-1;i<5;++i)
    {
        a[i]=a[i+1];
    }
    printf("New Array ");
    for(int i=0;i<5;++i)
    {
        printf("%d ",a[i]);
    }
}









