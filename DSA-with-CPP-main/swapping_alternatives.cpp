#include<bits/stdc++.h>
using namespace std;

void swaPping(int arr[],int n)
{
    for(int i = 0 ; i < n-1; i+=2)
    {
        swap(arr[i],arr[i+1]);
    }
}

int main ()
{
    int arr[6]={4,6,14,8,12,2};
    swaPping(arr,6);
    for(int i = 0 ; i<6 ; i++)
    {  
        cout<<arr[i]<<" ";
    }        
    return 0 ;
}

