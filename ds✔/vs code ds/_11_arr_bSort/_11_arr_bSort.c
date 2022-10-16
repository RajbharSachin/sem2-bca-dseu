#include <stdio.h>

void main(){
    int a[5]={5,4,1,2,3},temp;
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4-i;++j)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Array after Bubble sort:\n");
    for(int i=0;i<5;++i)
    {
        printf("%d\n",a[i]);
    }
}