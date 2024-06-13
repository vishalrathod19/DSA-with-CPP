#include<iostream>
#include<stack>

using namespace std;

class Stack {
    //properties
    public:
    int *arr;
    int top;
    int size;
  
    //behaviour
    Stack(int size){
         this->size = size;
         arr = new int[size];
           top = -1;
    }  
    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack is full"<<endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if(top==-1)
        {
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    Stack st(5);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<st.peek()<<endl;

    st.pop();

    cout<<st.peek()<<endl;
    
    st.isempty();
    

    return 0;

}