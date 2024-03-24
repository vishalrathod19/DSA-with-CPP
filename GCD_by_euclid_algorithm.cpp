#include<bits/stdc++.h>
using namespace std;

// function create 

int GCD(int a,int b)
{
    if(a==0){
    return a;}
    if(b == 0 )
    {
        return b ;
    }
    while(a!=b)
    {
        if(a>b)
        {
            a = a-b;
        }
        else{
            b= b-a;
        }
    }
    return a;
}
int main ()
{
    int a = 15,b = 10;
    cout<<GCD(a,b);
    return 0;
}