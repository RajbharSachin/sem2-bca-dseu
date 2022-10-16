#include <stdio.h>

void main(){
    int a[5]={2,5,3,1,7},ptr,temp;
    for(int i=1;i<5;++i)
    {
        temp=a[i];
        ptr=i-1;
        while(temp<a[ptr] && ptr!=-1)
        {
            a[ptr+1]=a[ptr];
            ptr=ptr-1;
        }
        a[ptr+1]=temp;
    }
    printf("Array after insertion sort: \n");
    for(int i=0;i<5;++i)
    {
        printf("%d\n",a[i]);
    }
}