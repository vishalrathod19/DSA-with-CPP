/*what is reference variable ?
Reference variable is like ek pointer ka pointer jiska sirf ek address hota hai.
Jab aap ek variable ko dusre variable se reference karte ho, 
toh dono variables ka address same hota hai aur dono same memory space share karte hain. 
Iska matlab hai ki jab aap kisi ek variable mein changes karte ho, 
toh dusre variable mein bhi wahi changes reflect hote hain. 
Isse aapko duplicate data store karne ki zarurat nahi hoti, 
aur code bhi efficient hota hai. Reference variable ko define karne
ke liye '&' symbol ka use hota hai
*/

#include<iostream>
using namespace std;
/*void update(int & n)
{
    n++;
}*/
int getsum(int * arr,int n)
{
    int sum =0 ;
    for(int i =0 ; i<n ;i++)
    {
        sum+=arr[i];
    }
    return sum ;
    }
int main ()
{
   // int n = 6;
    //cout<<"Before n value "<<n<<endl;
    //update(n);
    //cout<<"after n value "<<n<<endl;
   /*char ch = 9 ;
    cout<<sizeof(ch)<<endl;
    char * cha = &ch;
    cout<<sizeof(cha);*/
    int n;
    cin>>n;
    int * arr = new int[n];
    for(int i = 0 ; i<n ; i++)
    {
        cin>>arr[i];

    }
    int getans = getsum(arr,n);
    cout<<getans<<endl;
}
