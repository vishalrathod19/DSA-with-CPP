#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
vector<int> reverse(vector<int> & arr,int m)
{ 
  int s = m+1 ;
  int e = arr.size()-1;
  while(s<=e)
  {
    swap(arr[s],arr[e]);
    s++;
    e--;
  }
  return arr ;
}

int main (){
    vector<int> v ;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);
    cout<<"the array is : -"<<endl;
    for(auto it : v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
     int m ;
    cout<<"Enter the index where you want to reverse the array "<<endl;
    cin>>m;
  vector<int>ans= reverse(v,m);
    cout<<"after reversing the array "<<endl;
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    return 0 ;
}