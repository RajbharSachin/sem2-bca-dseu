#include <iostream>
using namespace std;
int main() {
    int a[5];
    cout<<"Enter the 5 elements of array ";
    //read array at compile time by loops
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    //printing array elements
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<"\n";
    }
    return 0;
}