#include<bits/stdc++.h>
using namespace std ;

string remove_ocurance(string & s,string & part)
{
    while(s.length()!=0&&s.find(part)<s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s ;
}
int main()
{
    string s = "daabcbaabcbc";
    string p = "abc";
    string result = remove_ocurance(s,p);
    cout<<result<<endl;
    return 0 ;
}