#include <stdio.h>

void main(){
    int a[10]={2,8,15,4,1,3};
    int pos=3,num=100;
    pos=pos-1;
    for(int i=5;i>=pos;--i)
    {
        a[i+1]=a[i];
    }
    a[pos]=num;
    printf("Final array is ");
    for(int i=0;i<=6;++i)
    {
        printf("%d ",a[i]);
    }
}


