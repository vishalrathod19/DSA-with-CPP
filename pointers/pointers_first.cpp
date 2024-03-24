#include<iostream>
using namespace std;
int main() {
   int num = 5 ;
   int *ptr = &num ;
   cout<<"the ptr is "<<*ptr<<endl;
   num++;
   cout<<"the ptr is "<<*ptr <<endl;
    num++;
   cout<<"the ptr is "<<*ptr <<endl;
    num++;
   cout<<"the ptr is "<<*ptr <<endl;
    num++;
   cout<<"the ptr is "<<*ptr <<endl;
    return 0;
}