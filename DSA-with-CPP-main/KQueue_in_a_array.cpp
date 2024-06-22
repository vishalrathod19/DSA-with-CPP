#include<iostream>

using namespace std;

class KQueue{
    public:
    int n,k;
    int *front;
    int *rear;
    int *next;
    int *arr;
    int freeSpot;

    public:
     KQueue(int n , int k){
          this->n = n;
            this->k = k;
        front  = new int[k];
        rear = new int[k];
        for(int i = 0; i<k ; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i = 0; i<n ; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        freeSpot = 0;

     }

     void enqueue(int data , int qn){

        //overflow
        if(freeSpot == -1){
            cout<<"Queue is full"<<endl;
            return;
        }

        //find first free index ;
        int index = freeSpot;

        //update freeSpot
        freeSpot = next[index]; 

        //check whether first element 
        if(front[qn-1]==-1){
            front[qn-1] = index;
        }
        else{
            next[rear[qn-1]] = index;   
        }
        //update next
        next[index] = -1;

        //update rear
        rear[qn-1]=index;

        //push element
        arr[index] = data;
        
     }
      
    int dequeue(int qn){
        //underflow
        if(front[qn-1]==-1){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        int index = front[qn-1];
        front[qn-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

};

int main(){
    KQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(20,2);
    q.enqueue(30,3);
    q.enqueue(40,1);
    q.enqueue(50,2);
    q.enqueue(60,3);
    q.enqueue(70,1);
    q.enqueue(80,2);
    q.enqueue(90,3);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(3)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(3)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(3)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    
    return 0;
    
}