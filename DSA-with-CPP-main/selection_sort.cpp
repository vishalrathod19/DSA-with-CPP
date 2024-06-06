#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n)
{
        int minindex = 0 ;
        for(int i = 0 ; i < n-1;i++)
        {
            minindex = i ;
            for (int j = i+1; j < n; j++)
            {
                /* code */
                if(arr[j]<arr[minindex])
                {
                    minindex = j;
                }
            }
          swap(arr[minindex],arr[i]);
        }
}
int main()
{
    int arr[5]={64,25,12,22,11};
    selectionSort(arr,5);
    for(int i = 0 ; i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}