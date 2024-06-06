#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this -> data ;
        if(next!=NULL)
        {
            delete next ; 
            next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
// traversing a linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// gives length of linked list
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAttail(Node * &tail , int d)
{
    Node *temp = new Node(d);
    tail -> next = temp;
    temp->prev = tail;
    tail = temp ;
}

void InsertionAtPosition(Node * &tail, Node* &head,int position , int d){

    if (position == 1) {
        insertAtHead(head, d);
        return;
    }
    Node*temp = head;
    int cnt = 1;
         
    while(cnt<position-1 && temp!=NULL)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL) {
       insertAttail(tail,d);
        return;
    }
    Node* nodeToinsert=new Node(d);
    nodeToinsert->next = temp->next;
    temp-> next->prev = nodeToinsert;
    temp -> next = nodeToinsert;
    nodeToinsert->prev = temp ;

}

void deleteNode(int position , Node* &head)
{
     if (position == 1 )
     {  Node* temp = head ;
        temp ->next -> prev = NULL;
        head = head -> next ;
        //memory free start node 
        temp -> next = NULL;
        delete temp ;
     }
     else
     {
        //deleting any node middle node or last node 
        Node* curr = head ;
        Node* prev = NULL;
        int cnt = 1 ;
        while (cnt < position ){
             prev = curr;
             curr = curr->next;
             cnt++;
        }
       
        curr -> prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr ;
     }
}

Node* reverseDoublyLinkedlist(Node* head)
{
    if(head->next==NULL||head==NULL)
    {
        return head;
    }
    Node * newhead = reverseDoublyLinkedlist(head->next);
    head->next->prev = head->next->next;
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
    return newhead;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout << getLength(head) << endl;
    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 13);
    print(head);
    insertAtHead(head, 14);
    print(head);
    insertAttail(tail,15);
    print(head);
    InsertionAtPosition(tail,head,1, 43);
    print (head);
    deleteNode(4,head);
    print(head);
    head = reverseDoublyLinkedlist(head);
    cout << "Reversed Linked List: ";
    print(head);
    return 0;
}