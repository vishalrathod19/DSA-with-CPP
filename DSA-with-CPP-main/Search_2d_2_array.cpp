#include<bits/stdc++.h>
using namespace std;

bool binary_search(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int row_index = 0;
    int col_index = col-1;
    while (row_index<row && col_index>=0)
    {
        if(matrix[row_index][col_index]==target)
        {
            return 1;
        }
        else if (matrix[row_index][col_index]<target)
        {
            row_index++;
        }
        else{
            col_index--;
        }
    }
    return 0 ;
}
int main ()
{
    vector<vector<int>> matrix ={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 9;
    int result = binary_search(matrix,target);
    if(result!=0)
    {
        cout<<"the target element is present "<<endl;
    }
    else{
        cout<<"not found!!!"<<endl;
    }
   return 0;
}