#include<iostream>
#include<queue>
using namespace std;

int main(){
    //creating a queue
    queue<int> q;

    q.push(11);
    q.push(22);
    q.push(33);
    cout<<"front of q is : "<<q.front()<<endl;
    cout<<"Size of queue: "<<q.size()<<endl;
    cout<<"back of q is : "<<q.back()<<endl;
    q.pop();

    cout<<"Size of queue: "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }   

}