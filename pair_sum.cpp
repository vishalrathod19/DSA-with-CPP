#include<iostream>
using namespace std ;
void findPairSum(int arr [],int n ,int k)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1; j<n ; j++)
        {
            if(arr[i]+arr[j]==k)
            {
                cout<<"The target number is present :- "<<"( "<<arr[i]<<" "<<arr[j]<<" )"<<endl;
            }
        }
    }
}
int main ()
{
    int arr[7]={1,2,9,3,4,5,8};
    int target = 7;
    findPairSum(arr,7,target);
    return 0 ;
}