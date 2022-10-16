#include <stdio.h>

int linearSearch(int arr[], int size, int element){
    for(int i=0; i<size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
} 

//For Sorted Array
int binarySearch(int arr[], int size, int element){
    int low=0, mid, high = size-1;
    //Start searching
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    //Searching ends
    return -1;
}
int main(){
    //Unsorted array for linearSearch
    int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    int size = sizeof(arr)/sizeof(int);
    int element = 54;
    int searchIndex = linearSearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);

    //sorted array for binarySearch
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int size1 = sizeof(arr1)/sizeof(int);
    int element1 = 6;
    int searchIndex1 = binarySearch(arr1, size1, element1);
    printf("The element %d was found at index %d \n", element1, searchIndex1);

    return 0;
}