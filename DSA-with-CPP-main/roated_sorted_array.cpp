#include<iostream>
using namespace std;
int Pivot(int arr[],int n)
{
    int s = 0 ;
    int e = n - 1;
    while(s<e)
    {
        int m = (e+s)/2;
        if(arr[m]>= arr[0])
        {
            s = m+ 1;
        }
        else {
             e = m;
        }
    }
 return s ;
}

int binarySearch(int arr[],int s ,int e ,int n,int k)
{
    int start = s ;
    int end = e;
    while(start<end)
    {
        int m = start+(end-start)/2;
        if(arr[m]==k)
        {
            return m;
        }
        else if(arr[m]<k)
        {
            start= m+1;
        }
        else{
            end = m-1;
        }
    }
    return -1;
}

int getPostion(int arr[],int n,int k)
{
   int getpivot= Pivot(arr,n);
   if(arr[getpivot]<=k&&k<=arr[n-1])
   {
       return binarySearch(arr,getpivot,n-1,n,k);
   }
   else {
         return binarySearch(arr,0,getpivot-1,n,k);
   }
}
int main ()
{
    int arr[5]={12,15,18,2,4};
    int k = 2;
    int index = getPostion(arr,5,k);
    if(index != -1)
    {
        cout<<"the key = "<<k<<" is present at index :- "<<index<<endl;
    }
    else{
        cout<<"the key not present"<<endl;
    }
    return 0;
}