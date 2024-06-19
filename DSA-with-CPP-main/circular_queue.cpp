#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value) {
        // Check if the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            return false;
        } else if (front == -1) { // Insert the first element
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) { // Wrap around to the beginning of the array
            rear = 0;
        } else { // Normal case
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue() {
        // Check if the queue is empty
        if (front == -1) {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) { // Queue has become empty
            front = rear = -1;
        } else if (front == size - 1) { // Wrap around to the beginning of the array
            front = 0;
        } else { // Normal case
            front++;
        }
        return ans;
    }

    // To get the front element of the queue
    int getFront() {
        if (front == -1) {
            return -1;
        }
        return arr[front];
    }

    // To get the rear element of the queue
    int getRear() {
        if (rear == -1) {
            return -1;
        }
        return arr[rear];
    }

    // To check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // To check if the queue is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)));
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5); // Initialize the queue with size 5

    // Perform some operations
    cout << "Enqueue 10: " << (q.enqueue(10) ? "Success" : "Failure") << endl;
    cout << "Enqueue 20: " << (q.enqueue(20) ? "Success" : "Failure") << endl;
    cout << "Enqueue 30: " << (q.enqueue(30) ? "Success" : "Failure") << endl;
    cout << "Enqueue 40: " << (q.enqueue(40) ? "Success" : "Failure") << endl;
    cout << "Enqueue 50: " << (q.enqueue(50) ? "Success" : "Failure") << endl;
    cout << "Enqueue 60: " << (q.enqueue(60) ? "Success" : "Failure") << endl; // Should fail

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Enqueue 60: " << (q.enqueue(60) ? "Success" : "Failure") << endl; // Should succeed now

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Is queue empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full: " << (q.isFull() ? "Yes" : "No") << endl;

    return 0;
}
