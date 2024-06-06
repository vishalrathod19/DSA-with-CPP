#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>>& arr, int nRows,int mCols)
{
    vector<int> ans;
    for(int i = 0 ; i<mCols ; i++)
    {
        if(mCols&1)//if column index is odd 
        {
            for(int j = nRows-1; j>=0 ;j--)//we apply bottom to top approach 
            {   
                ans.push_back(arr[i][j]);
            }
        }
        else{//if column index is even 
            for(int j = 0 ; j<=nRows ;j++)//we apply top to bottom approach
            {
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans ;
}

int main() {
    // Example usage
    int nRows = 3; // Number of rows
    int mCols = 3; // Number of columns
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Sample 3x3 array

    vector<int> result = wavePrint(arr, nRows, mCols);

    // Print the result
    cout << "Wave print result: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}