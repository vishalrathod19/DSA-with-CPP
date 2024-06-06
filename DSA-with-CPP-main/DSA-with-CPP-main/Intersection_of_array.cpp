#include<iostream>
#include<vector>
using namespace std;

vector<int> findArrayIntersection(vector<int>&arr1,int n , vector<int>&arr2 , int m)
{
   vector<int> ans;
   for(int i = 0 , j = 0;i<n&&j<m;)
   {
     if(arr1[i]==arr2[j])
     {
        ans.push_back(arr1[i]);
        i++;
        j++;
     }
     else if (arr1[i]<arr2[j])
     {
        /* code */
        i++;
     }
     else{
        j++;
     }
   }
   return ans;
}
int main ()
{
    vector<int> arr1={1,3,4,5,7};
    vector<int> arr2={3,4,6,8};
    vector<int> intersection = findArrayIntersection(arr1,arr1.size(),arr2,arr2.size());
    for (int i = 0; i < intersection.size(); i++)
    {
        /* code */
        cout<<intersection[i]<<" ";
    }
    cout<<endl;
    return 0 ;
    
}