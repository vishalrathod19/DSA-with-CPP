#include<iostream>
using namespace std;

void print( int arr[],int n , int size = 0 )
{
    for(int i = 0 ; i<n ; i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main ()
{
    int arr[5]={2 ,4,5,6,7};
    int n = 5;
    print(arr,n);
    cout<<endl<<endl;
    print(arr,n,2);
    return 0 ;
}