#include<iostream>
using namespace std ;
int get_sum(int*arr,int n)
{
    int sum= 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        sum+=arr[i];
    }
    return sum ;
}

int main ()
{
    int n ;
    cin>>n;

 int*arr =  new int[5];
 for(int i  =0 ; i<n ;i++)
 {
    cin>>arr[i];
 }
 int ans = get_sum(arr,n);
 cout<<"the result is :- "<<ans<<endl;
 return 0 ;
 while(true)
 {
  int *ptr = new int ;
 }
}
