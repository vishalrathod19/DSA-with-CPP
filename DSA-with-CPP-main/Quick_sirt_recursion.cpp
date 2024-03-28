#include<iostream>
using namespace std;

int  partition(int arr[],int s, int e)
{
      int pivot = arr[s];

      int count = 0 ;
      for(int i = s+1; i<=e;i++)
      {
        if(arr[i]<=pivot)
        {
           count++;
        }
      }
      //place pivot at right place 
      int pivotIndex = s + count ;
      swap(arr[pivotIndex],arr[s]);
      //left and right wala part smbhal lete hai 
      int i = s , j =e;
      while(i<pivotIndex && j>pivotIndex)
      {
        while(arr[i]<pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<pivotIndex&& j>pivotIndex)
        {
           swap(arr[i++],arr[j--]);          
        }    
 }
 return pivotIndex;
}

void quick_sort(int arr[],int s, int e)
{
    if(s>=e)
    {
        return ;
    }
    int p = partition(arr,s,e);
    //left part sort kerdo 

    quick_sort(arr,s,p-1);

    //right part me sort kerdo 
    quick_sort(arr,p+1,e);
      
}
int main ()
{
   int arr[5] = {5, 2, 9, 3, 8};
    int n = 5;
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<arr[i] << " ";
    }
    cout << endl;

    return 0;
}