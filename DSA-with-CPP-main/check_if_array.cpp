#include<iostream>
using namespace std;

bool check_array(int arr[],int n)
{
    int count = 0 ;
    for(int i = 1; i<n; i++)
    {
        if(arr[i-1]>arr[i])
        {
            count ++;
        }
    }
    if(arr[n-1]>arr[0])
    {
        count++;
    }
    return count==1;
}
int main (){
    int arr1[5]={3,5,7,1,2};
    int arr2[5]={1,2,3,5,7};
      if (check_array(arr1, 5)) {
        cout << "arr1 is sorted and rotated." << endl;
    } else {
        cout << "arr1 is not sorted and rotated." << endl;
    }

    if (check_array(arr2, 5)) {
        cout << "arr2 is sorted and rotated." << endl;
    } else {
        cout << "arr2 is not sorted and rotated." << endl;
    }
    return 0;
}