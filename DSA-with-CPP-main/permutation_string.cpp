#include<bits/stdc++.h>
using namespace std ;

bool check_equal(int a[26],int b[26])
{
    for(int i = 0 ; i<26; i++)
    {
        if(a[i]!=b[i])
        {
            return false ;
        }

    }
    return true;
}

string permutation(string& s1 ,string& s2)
{
    int count1[26]={0};
    for(int i = 0 ; i<s1.length(); i++)
    {
        int index = s1[i]-'a';
        count1[index]++;
    }
    int count2[26]={0};
    int window = s1.length();
    for (int i = 0; i < window && i< s2.length(); i++)
    {
        int index1 = s2[i]-'a';
        count2[index1]++;
    }
    
    if(check_equal(count1,count2))
    {
        return "true";
    }
    int i = window ;
    while(i<s2.length())
    {
        char newChar = s2[i];
        int index2 = newChar -'a';
        count2[index2]++;
        char oldchar = s2[i-window];
        int index3 = oldchar -'a';
        count2[index3]--;
         if(check_equal(count1,count2))
    {
        return "true";
    }
    i++;
    }
  return "false";
}

int main ()
{
    string s2 = "eidbaooo";
    string s1="ab";
    string result = permutation(s1,s2);
    cout<<"the result is :- "<<result<<endl;

}