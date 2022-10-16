#include <stdio.h>

int partition(int a[],int lb,int ub){
    int pivot= a[lb];
    int start= lb;
    int end= ub;
    while(start<end)
    {
        while(a[start]<=pivot)
        {
            ++start;
        }
        while(a[end]>pivot)
        {
            --end;
        }
        if(start<end)
        {
            a[start]=a[start]+a[end];
            a[end]=a[start]-a[end];
            a[start]=a[start]-a[end];
        }
    }

    a[lb]=a[lb]+a[end]; 
    a[end]=a[lb]-a[end]; 
    a[lb]=a[lb]-a[end]; 

    return end;
}

void quickSort(int a[],int lb,int ub){
    if(lb<ub)
    {
        int loc= partition(a,lb,ub);
        quickSort(a,lb,loc-1);  //Wc: O(n^2)  &&   Bc/Ac: O(nllogn) 
        quickSort(a,loc+1,ub);
    }
}

int main(){
    int a[]= {7,6,10,5,9,2,1,15,7};
    quickSort(a,0,8);
    for(int i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}