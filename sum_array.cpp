#include<iostream>
using namespace std;

void sum(int arr[],int n)
{
    int sum = 0 ;
    for( int i= 0 ; i < n ; i++ ){
        sum+=arr[i];
    }
    cout<<"The sum of array is :- "<<sum<<endl;
}

int main()
{
    int n ;
    int arr[n];
    cout<<"Enter the number of array "<<endl;
    cin>>n;
    
    for(int i = 0 ; i<n ;i++)
    {
        cin>>arr[i];
    }
    
    sum(arr,n);
    return 0 ;
}