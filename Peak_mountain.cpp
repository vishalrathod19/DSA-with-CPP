#include<iostream>
using namespace std;
int Peak(int arr[],int n)
{
    int s = 0 ; 
    int e = n - 1 ;
    while ( s < e)
    { int m = (e+s)/2;
        if(arr[m]<arr[m+1])
        {
            s = m+1;
        }
        else {
            e = m;
        }
    }
    return s ;
}
int peakIndexInMountainArray(int arr[], int size) {
    return Peak(arr, size);
}
int main ()
{
  int arr[5]={2,3,4,5,1};
  int result = peakIndexInMountainArray(arr,5);
cout<<"The peak element is : "<<result<<endl;
  return 0 ;
}