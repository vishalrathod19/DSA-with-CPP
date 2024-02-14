#include<iostream>
using namespace std ;
int maX(int num[], int n )
{
    int maxi = INT_MIN;
    for(int i = 0 ; i < n ; i++)
    {
        maxi = max(maxi,num[i]);
    }
    return maxi;
}
int miN(int num [], int n)
{
    int mini = INT_MAX;
    for(int i=0 ; i < n ; i++)
    {
       mini = min(mini,num[i]);
    }
    return mini ;
}
int main ()
{  int n ; 
cin>>n;
    int arr[10];
    
for(int i = 0 ; i< n ; i++)
{
    cin>>arr[i];
}
int result = maX(arr,n);
int result1 = miN(arr,n);
     cout<<result1<<endl;
     cout<<result<<endl;
return 0 ;
}