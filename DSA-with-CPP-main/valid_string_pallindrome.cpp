#include<bits/stdc++.h>
#include<string>
using namespace std;

bool valid(char c)//faltu elements ko hatayega 
{
   if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
   {
    return 1;
   }
   return 0 ;
}
char toLowerCase(char ch)//lower case kerega isse 
{
    if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
    {
        return ch; 
    }
    else
    {  char temp = ch - 'A'+'a';
        return temp;
    }
}
bool check_reverse(string name)//check kerega 
{
    int s = 0 ;
    int e = name.length()-1;
    while(s<=e)
    {
        if(name[s]!=name[e])
        {
            return 0 ;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
bool is_palindrome(string s)
{
    string temp ="";
    //faltu ke character ko hatao 
    for(int j = 0 ;j<s.length();j++){
        if(valid(s[j]))
        {
            temp += s[j];
        }

    }
    //lower case me kero 
    for (int j = 0; j<temp.length(); j++)
    {
        temp[j]=toLowerCase(temp[j]);
    }
    //phir check kerdo 
    return check_reverse(temp);
}
int main ()
{
    string s ;
    cout<<"Enter the string "<<endl;
    cin>>s;
    bool result = is_palindrome(s);
    if (result)
    {
        cout << "Yes, it is a palindrome.\n";
    }
    else
    {
        cout << "No, it is not a palindrome.\n";
    }
    return 0 ;
}