#include <stdio.h>

void main(){
    int a[5]={5,2,1,3,4},loc,temp;
    for(int i=0;i<4;++i) 
    {
        loc=i;
        for(int j=i+1;j<5;++j)
        {
            if(a[loc]>a[j])
            {
                loc=j;
            }
        }
        temp=a[loc];
        a[loc]=a[i];
        a[i]=temp;
    }
    printf("Array after selection sort(asc. order): \n");
    for(int i=0;i<5;++i)
    {
        printf("%d\n",a[i]);
    }
}