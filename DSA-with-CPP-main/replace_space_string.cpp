#include<bits/stdc++.h>
using namespace std;

/*string replace_string(string &s)
{
    string temp = " ";
    for(int i =0 ; i<s.length(); i++)
    {
        if(s[i]==' ')
        {
           temp.push_back('@');
           temp.push_back('4');
           temp.push_back('0');
        }
        else{
            temp.push_back(s[i]);
        }
    }
    return temp ;
}*/
string replace_string(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            s[i] = '@';
            s.insert(i + 1, "40");
            i += 2; // Increment i to skip over the inserted "40"
        }
    }
    return s;
}
int main ()
{
    string s = "hii vishal rathod ";
    cout<<replace_string(s);
    
    return 0 ;
}