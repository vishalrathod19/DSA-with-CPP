#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n)
{
    for(int i = 0 ; i<n;i++)
    {    bool swapped = false;
        for(int j =0; j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped =true;
            }
        }
        if(swapped==false)
        {
            break;
        }
    }
}
int main ()
{
    int arr[6]={19,2,1,0,16,11};
    bubble_sort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0 ;
}