#include<iostream>

using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Stack class to manage stack operations
class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation to add an element to the stack
    void push(int element) {
        Node* newNode = new Node(element);
        if (newNode==NULL) {
            cout << "Heap overflow" << endl;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    // Pop operation to remove the top element from the stack
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek operation to return the top element of the stack
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isempty() {
        return top == nullptr;
    }
};

int main() {
    Stack st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;
    
    if (st.isempty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    
    return 0;
}
