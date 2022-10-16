#include <stdio.h>

void divide(int a[],int,int);
void merge(int a[],int,int,int);


void divide(int a[],int lb,int ub){
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        divide(a,lb,mid);
        divide(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

void merge(int a[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[100];
    while(i<=mid && j<=ub) //compare and copy non exhausted part
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)  // if i is exhausted j has extra elements copied
    {
        while(j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else // i has extra elements copied
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++) //replacing values from b arr to a arr
    {
        a[k]=b[k];
    }
}

int main(){
    int a[100],size,i;
    printf("Enter the size of array(b/w 0 to 100): ");
    scanf("%d",&size);
    printf("Enter the array elements: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    divide(a,0,size-1);
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}