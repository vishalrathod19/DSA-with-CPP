#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;
    public:
    Queue(int s){
        size = 100001;
        arr = new int[s];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty(){
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int x){
        if(rear == size){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[rear] = x;
        rear++;
    }

    int dequeue(){
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front(){

        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};

int main(){
    Queue q(100);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(40);
    return 0;
}