#include<iostream>
using namespace std;
int binarySearchFirst(int arr[],int n , int target)
{
  int start = 0 ;
  int end = n-1;
  int firstP = -1;
  while(start<=end)
  {
    int mid = start+(end-start)/2;
    if(arr[mid]==target)
    {
        firstP = mid ;
        end = mid - 1;
    }
    else if(arr[mid]<target)
    {
        start = mid+1;
    }
    else{
        end = mid -1 ;
    }
  }
  return firstP;
}
int binarySearchLast(int arr[],int n , int target)
{
  int start = 0 ;
  int end = n-1;
  int lastP = -1;
  while(start<=end)
  {
    int mid = start+(end-start)/2;
    if(arr[mid]==target)
    {
        lastP = mid;
        start = mid + 1;
    }
    else if(arr[mid]<target)
    {
        start = mid+1;
    }
    else{
        end = mid -1 ;
    }
  }
  return lastP;
}
int main ()
{
    int arr[10]={1, 2, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;
    int firstP= binarySearchFirst(arr,10,target);
    int lastP= binarySearchLast(arr,10,target);
    if(firstP!=-1 && lastP!= -1)
    {
        cout<<"the element found at index : "<<firstP<<" "<<lastP<<endl;
    }
    else{
        cout<<"The element not found "<<endl;
    }
    int total = (lastP - firstP)+1;
    cout<<"The total ocurance in the index :- "<<total;
    return 0 ;
}