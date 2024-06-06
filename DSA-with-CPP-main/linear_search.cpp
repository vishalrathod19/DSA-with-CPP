#include<iostream>
using namespace std;

bool linearSearch(int arr[],int size,int key)
{
    for(int i = 0 ; i <size ; i++ )
    {
        if(arr[i]==key)
        {
            return 1;
        }
    }
    return 0;
}

int main ()
{
    int arr[5]={1,3,1,-2,5};
    
    int key ;
    cout<<"Enter the element which you find the entire list."<<endl;
    cin>>key;
    bool found = linearSearch(arr,5,key);
    if(found)
    {
        cout<<"key is present in list";

    }
    else 
       cout<<"key is not present in list ";
return 0 ;
}