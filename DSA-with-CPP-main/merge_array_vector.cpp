#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>&arr1,vector<int>&arr2)
{   vector<int> arr3;
    int i = 0 ;
    int j = 0;
    while(i<arr1.size()&&j<arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            arr3.push_back(arr1[i++]);
        }
        else{
            arr3.push_back(arr2[j++]);
        }
    }
    while(i<arr1.size())
    {
        arr3.push_back(arr1[i++]);
    }
    while(j<arr2.size())
    {
        arr3.push_back(arr2[j++]);
    }
    return arr3;
}
void ans(const vector<int>&arr3)
{
   for(auto it : arr3)
   {
    cout<<it<<" ";
   }cout<<endl;
}

int main ()
{
    vector<int> arr1 ={2,4,6,8,10,12};
    vector<int> arr2={3,5,7,9};
    vector<int> answer = merge(arr1,arr2);
    ans(answer);
    return 0 ;
}