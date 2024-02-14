#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int n , int m ,int mid)
{
    int cowPlaced = 1 ;
    int Prev = arr[0];
     for (int i = 1; i < n; i++) {
        if (arr[i] - Prev >= mid) {
            cowPlaced++;
            if(cowPlaced==m)
            {
                return true;
            }
            Prev = arr[i];
        }
    }
    return false;
}

int CowAggressive(int arr[],int n ,int m)
{
    int start = 0 ;
    int end = arr[n-1];
    int ans = -1;
    while(start<end)
    {
        int mid = start+(end - start)/2;
        if(isPossible)
        {
            ans = mid ;
            start = mid+1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans ;
}

int main ()
{
    int arr [5]={4,2,1,3,6};
    int k = 2 ;
    sort(arr,arr+5);
    int result = CowAggressive(arr,5,k);
    cout<<"The result is : "<<result<<endl;

}
