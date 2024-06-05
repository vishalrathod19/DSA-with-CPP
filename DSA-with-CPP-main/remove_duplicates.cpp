#include <iostream>

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

void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertionAtPosition(Node* &head, int position, int d) {
    if (position == 1) {
        InsertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }
    Node* nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

void deleteNode(int position, Node* &head) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

Node* uniqueSortedList(Node* head) {
    if (head == NULL)
        return NULL;

    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            nodeToDelete->next = NULL; // Ensure no recursive delete
            delete nodeToDelete;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;

    InsertAtTail(tail, 20);
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 50);

    cout << "Original list: ";
    print(head);

    head = uniqueSortedList(head);

    cout << "List after removing duplicates: ";
    print(head);

   

    return 0;
}
