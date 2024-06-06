#include<iostream>
using namespace std ;
int maX(int num[], int n )
{
    int max = INT_MIN;
    for(int i = 0 ; i < n ; i++)
    {
        if(num[i]>max)
        {
            max= num[i];
        }
    }
    return max;
}
int miN(int num [], int n)
{
    int min = INT_MAX;
    for(int i=0 ; i < n ; i++)
    {
        if(num[i]<=min)
        {
            min = num[i];
        }
    }
    return min ;
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