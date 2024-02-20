#include <bits/stdc++.h> 
using namespace std;

void spiral_print(vector<vector<int>> &arr)
{
    int row = arr.size(); 
    int col = arr[0].size(); 
    int left = 0; 
    int right = col - 1; 
    int bottom = row - 1; 
    int top = 0; 

    // Traverse the array in a spiral pattern.
    while (top <= bottom && left <= right)
    {
        // Traverse from left to right in the top row.
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++; // Move to the next row.

        // Traverse from top to bottom in the rightmost column.
        for (int j = top; j <= bottom; j++)
        {
            cout << arr[j][right] << " ";
        }
        right--; // Move to the previous column.

        // Traverse from right to left in the bottom row.
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--; // Move to the previous row.
        }

        // Traverse from bottom to top in the leftmost column.
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++; // Move to the next column.
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
   
    for(int i = 0 ; i<arr.size();i++)
    {   
        for(int j = 0 ; j<arr[0].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // Call the function 
    spiral_print(arr);
    return 0;
}
