#include<iostream>
using namespace std;

int PowerMod(int x , int n,int m)
{
    if(n==0)
    {
        return 1%m;
    }
    long long result = 1;
    long long base = x%m;
    while(n>0)
    {  //if n is odd , multiply result with base and take modules
        if(n%2==1){
        result = (result*base)%m;
        //reduce N by half
        n/=2;
        base = (base*base)%m;
        }
    }
    return result;
}
int main(){
    int x,n,m;
    cin>>x>>n>>m;
    int ans = PowerMod(x,n,m);
    cout<<ans<<endl;
    return 0 ;
}