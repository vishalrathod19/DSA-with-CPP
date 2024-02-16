#include<bits/stdc++.h>
#include<string>
using namespace std;
bool check_reverse(char name[],int n)
{
    int s = 0 ;
    int e = n-1;
    while(s<e)
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
void reverse(char name[],int n)
{
    int s = 0;
    int e = n-1;
    while (s<e)
    {
        swap(name[s++],name[e--]);
    }
}
int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main()
{
    char name[20]= "mom";
    cout<<name<<endl;
    int leng = getLength(name);
    reverse(name,leng);
    cout<<name<<endl;
    cout<<"pallindrome or not "<<check_reverse(name,leng)<<endl;
    return 0;
}