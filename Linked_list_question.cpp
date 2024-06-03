#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};
void InsertAtTail(Node *&tail, int d)
{
    // new node create;
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertionAtPosition(Node *&head, int position, int d)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

Node *KReverse(Node *head, int k)
{
    // base call
    if (head == NULL)
    {
        return NULL;
    }
    // step 1 : reverse first k node
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;

    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 : recursion dekhlega aage ka
    if (next != NULL)
    {
        head->next = KReverse(next, k);
    }

    // step 3 : return head of reversal list
    return prev;
}
int main()
{
    Node *node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 12);
    print(head);
    InsertAtHead(head, 15);
    print(head);
    InsertAtTail(tail, 12);
    print(head);
    InsertAtTail(tail, 15);
    print(head);
    InsertionAtPosition(head, 3, 22);
    print(head);
    // deleteNode(3,head);
    // print (head);
    head = KReverse(head, 2);
    cout << "Reversed Linked List: ";
    print(head);
    return 0;
}
