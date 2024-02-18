#include<iostream>
using namespace std;

void sum(int arr[][4],int row, int col)
{
    int sum = 0 ;
    for( int i= 0 ; i < row; i++ ){
          for(int j = 0; j < col; j++)
        {
        sum+=arr[i][j];
    }cout<<"The "<<i<<" row th sum is :- "<<sum<<" "<<endl;
    }
    
}

int largestSum(int arr[][4],int row , int col)
{   int maxi = INT_MIN;
    int rowIndex = -1;
    for( int i= 0 ; i < row; i++ ){
        int sum = 0 ;
          for(int j = 0; j < col; j++)
        {
        sum+=arr[i][j];
    }
    if(sum>maxi)
    {
        maxi = sum;
        rowIndex = row;
    }
    }
  cout<<"The maximum sum is "<<maxi<<endl;
  return rowIndex;
}

int main ()
{
    int arr[3][4];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //sum(arr,3,4);
    int ans = largestSum(arr,3,4);
    cout<<"The row is at index "<<ans<<endl;
return 0;
}