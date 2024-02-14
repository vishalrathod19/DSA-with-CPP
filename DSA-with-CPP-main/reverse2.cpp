// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void reverse(int arr[],int n)
{
    int start = 0 ;
    int end = n-1;
    //while loop for reverse the array
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    //print the reverse array 
    for(int i = 0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[5]={1,2,3,4,5};
    int brr[5]={2,0,1,5,6};
    reverse(arr,5);
    reverse(brr,5);
    return 0;
}