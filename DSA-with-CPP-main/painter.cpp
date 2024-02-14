#include<iostream>
using namespace std;

bool isPossible(int arr[],int n ,int m,int mid)
{
    int paintercount = 1;
    int boardsum= 0;
    for (int i = 0; i < n ; i++)
    {
        if(boardsum+arr[i]<=mid)
        {
            boardsum+=arr[i];
        }
        else{
            paintercount++;
            if(paintercount>m||mid<arr[i])
            {
                return false;
            }
            boardsum=arr[i];
        }
        if(paintercount>m)
        {
            return false;
        }
    }
    return true;   
}

int PainterAllocation(int arr[],int n,int m)
{
    int start = 0 ;
    int sum = 0 ;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    int end = sum;
    int ans = -1;
    while (start<end)
    {
        /* code */
        int mid = start +(end-start)/2;
        if(isPossible(arr,n,m,mid))
        {
           ans = mid;
           end =mid-1;
        }
        else{
             start = mid+1 ;
        }
    }
 return ans ;
}

int main()
{
    int arr[5]={10,20,30,40,50};
    int m = 2;
    int result = PainterAllocation(arr,5,m);
    cout<<"the minimum number is :- "<<result<<endl;
    return 0 ;
}