#include <stdio.h>

void main(){
    int a[7]={1,2,8,13,17,21,28};
    int s=0,e=6,mid=(s+e)/2,num;
    printf("Enter the no. to be searched for ");
    scanf("%d",&num);
    while (s<=e)
    {
        if(num==a[mid])
        {
            printf("Found at location %d",mid+1);
            break;
        }
        else if(a[mid]<num)
        {
            s=mid+1;
        }
        else 
        {
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    
}