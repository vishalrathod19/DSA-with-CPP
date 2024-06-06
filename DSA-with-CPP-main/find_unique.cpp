#include<iostream>
using namespace std;

void UniqueF(int arr [],int n)
{
    int ans = 0 ;
    for (int i = 0; i < n ; i++)
    {
        /* code */
        ans = ans^arr[i]; 
    }
    cout<<ans;
}

int main ()
{
    int arr[5]={2,1,5,0,3};
    UniqueF(arr,5);
return 0;
}