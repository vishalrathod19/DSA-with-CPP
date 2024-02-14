#include<iostream>
using namespace std;

void Insertion_Sort(int arr[],int n)
{
    int temp = 0 ;
    for(int i = 0 ; i < n;i++)
    {
        temp = arr[i];
        int j = i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}

int main()
{
    int arr[7]={10,1,7,4,8,2,11};
    Insertion_Sort(arr,7);
    for(int i = 0 ; i<7 ;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0 ;
}