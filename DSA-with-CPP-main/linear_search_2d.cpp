#include<iostream>
using namespace std;

bool linearSearch(int arr[][4], int row, int col, int key)
{
    for(int i = 0; i < row; i++)
    {  
        for(int j = 0; j < col; j++)
        {
            if(arr[i][j] == key)
            {
                return true;
            }
        }
    }
    return false;
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
    
    int key ;
    cout << "Enter the key you want to search: ";
    cin >> key;
    
    bool result = linearSearch(arr, 3, 4, key);
    if(result)
        cout << "Element found!";
    else
        cout << "Element not found!";
    
    return 0 ;
}
