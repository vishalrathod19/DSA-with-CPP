#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}

    ~Node() {
        cout << "Memory freed for node with data " << this->data << endl;
    }
};

void InsertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    if (tail == nullptr) {
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertionAtPosition(Node* &head, int position, int d) {
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }
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
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head) {
    if (position <= 0 || head == nullptr) {
        cout << "Invalid position or empty list!" << endl;
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = nullptr;
        int cnt = 1;
        while (cnt < position && curr != nullptr) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
}

Node* sortList(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == 0)
            zeroCount++;
        else if (temp->data == 1)
            oneCount++;
        else if (temp->data == 2)
            twoCount++;
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr) {
        if (zeroCount != 0) {
            temp->data = 0;
            zeroCount--;
        } else if (oneCount != 0) {
            temp->data = 1;
            oneCount--;
        } else if (twoCount != 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;

    InsertAtTail(tail, 20);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 5);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 25);

    cout << "Original list: ";
    print(head);

    head = sortList(head);
    cout << "List after sorting: ";
    print(head);

    return 0;
}
