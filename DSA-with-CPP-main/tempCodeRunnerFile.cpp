#include <iostream>
#include <map>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Memory is free for node with data " << this->data << endl;
    }
};

void InsertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void removeDuplicates(Node* &head){
    map<Node*, bool> visited;
    Node* curr = head;
    Node* prev = NULL;
    
    while(curr != NULL) {
        if(visited[curr]) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            visited[curr] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;

    InsertAtTail(tail, 12);
    InsertAtTail(tail, 11);
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 11);
    InsertAtTail(tail, 12);

    cout << "Original list: ";
    print(head);
    removeDuplicates(head);
    cout << "List after removing duplicates: ";
    print(head);
    return 0;
}
