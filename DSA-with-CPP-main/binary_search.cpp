#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int target )
{
    int start = 0 ;
    int end = n-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid]==target)
        {
            return mid ;
        }
        else if (arr[mid]<target)
        {
            start = mid+1;

        }
        else{
            end  = mid -1;
        }
    }
    return -1;
}
int main ()
{
    int arr[10]={2,3,4,5,6,7,8,9,10,11};
    int target = 10;
    int result = binarySearch(arr,10,target);
    if(result!=-1)
    {
        cout<<"the element found at index :- "<<result<<endl;
    }
    else {
        cout<<"The element is not found"<<endl;
    }
    return 0 ;

}