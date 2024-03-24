#include<iostream>
using namespace std;

bool binary_search(int *arr,int k, int s , int e, int n){   
   if(s>e)
   {
    return false;
   }
   int mid = s+(e-s)/2;
    //element found
    if(arr[mid] == k){
        return true;
    }
    if(arr[mid] < k) {
        return binary_search(arr,k, mid+1,e,n);
    }
    else{
        return binary_search(arr,k, s, mid-1,n);
    }
}

int main ()
{
   int arr[5]={3,4,5,7,8};
   int n =5;
   int k = 7;
   if (binary_search(arr, k, 0, n - 1, n)) {
        cout << "Element found\n";
    } else {
        cout << "Element not found\n";
    }
    return 0;

}
