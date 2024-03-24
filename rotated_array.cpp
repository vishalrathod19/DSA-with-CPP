#include<bits/stdc++.h>
using namespace std;
void rotated_array(int arr [],int n,int k){
     int temp[n];
     for(int i = 0 ; i< n;i++)
     {
        temp[(i+k)%n] = arr[i];

     }
     for(int i = 0 ; i<n;i++)
     {
        arr[i]=temp[i];
     } 
}
int main ()
{
    int arr[4]={3,99,-1,-100}; 
    int k = 2;
    rotated_array(arr,4,k);
    cout<<"the rotated array is :- "<<endl;
    for(int i = 0 ;i<4;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0 ;
}