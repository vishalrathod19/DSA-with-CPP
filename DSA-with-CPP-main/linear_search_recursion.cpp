#include<iostream>
using namespace std;

int linearSearch(int arr[],int key,int size,int index=0)
{
    if(index>=size)
    {
        return -1;
    }
    if(arr[index]==key)
    {
        return index;
    }

    return linearSearch(arr,key,size,index+1);
}

int main ()
{
    int arr[5]={2,3,4,5,6};
    int n = 5;
    int k = 5;
    int ans = linearSearch(arr,n,k);
    if(ans!=-1)
    {
        cout<<"the element is present ";
    }
    else{
        cout<<"the element is not present";
    
    }
    return 0 ;
 }