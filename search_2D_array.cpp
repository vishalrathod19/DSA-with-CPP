#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<vector<int>>&matrix,int row , int col ,int target)
{
    int start = 0 ;
    int end = ((row*col)-1);
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        int element = matrix[mid/col][mid%col];
        if(element ==target)
        {
            return 1 ;
        }
        else if (element<target)
        {
            start = mid+1;

        }
        else{
            end  = mid -1;
        }
    }
    return -1;
}
int main ()
{   int row = 3;  
    int col = 3;
    vector<vector<int>> matrix = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}}; 
  int target = 4 ;
  int result = binary_search(matrix,row,col,target);
   if(result!=-1)
    {
        cout<<"the element is found"<endl;
    }
    else {
        cout<<"The element is not found"<<endl;
    }
    return 0 ;

}