#include<iostream>
using namespace std;

char get_maximum(string& s)
{
    int arr[26]={0};
    for (int i = 0; i < s.length(); i++)
    {
        /* code */
        char ch = s[i];
        
        arr[ch - 'a']++;
    }
    int max = -1 ;
    int ans = 0;
    for(int i = 0 ; i<26; i++)
    {
        if(max<arr[i])
        {  
            ans = i ;
            max = arr[i];
        }
    }
    return 'a'+ans;
}

int main ()
{
    string s ;
    cout<<"Enter the string "<<endl;
    cin>> s;
    cout<<"The maximum element in string :- "<<get_maximum(s)<<endl;
    return 0 ; 
}