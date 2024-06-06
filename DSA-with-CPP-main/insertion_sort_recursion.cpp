#include<iostream>
using namespace std;

void insertion_sort(int *arr,int n)
{
    if(n==0||n==1)
    {
        return ;
    }
    insertion_sort(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while(j>=0&&arr[j]>last)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=last;
}
int main ()
{
    int arr[5]={6,7,2,4,0};
    insertion_sort(arr,5);
    for(int i =0 ; i<=5 ; i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0 ;
}