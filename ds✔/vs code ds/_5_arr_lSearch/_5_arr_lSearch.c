#include <stdio.h>
void main(){
    int a[5]={1,18,5,8,2};
    int num;
    printf("Enter no. to be searched ");
    scanf("%d",&num);
    for(int i=0;i<5;++i)
    {
        if(num==a[i])
        {
            printf("Found at location %d",i+1);
            break;
        }
    }
}