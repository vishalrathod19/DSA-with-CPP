#include<iostream>

using namespace std ;

class Node {
    public :
    int data ;
    Node* next ;
    Node(int data){
        this -> data = data ;
        this -> next = NULL;
    }
    ~Node(){
        int value = this -> data ;
        if(this-> next!=NULL)
        {
            delete next ; 
            this -> next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
void InsertAtTail(Node* &tail,int d)
{
    //new node create;
    Node* temp = new Node(d);
    tail->next = temp ;
    tail = temp ;
}
void InsertAtHead(Node* &head,int d) {
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}


void print(Node* &head)
{
    Node*temp = head ;
    while (temp !=NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl;
}

void InsertionAtPosition(Node* &head,int position , int d)
{    if (position == 1) {
        InsertAtHead(head, d);
        return;
    }
    Node*temp = head;
    int cnt = 1;
         
    while(cnt<position-1 && temp!=nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }
    Node* nodeToinsert=new Node(d);
    nodeToinsert->next = temp->next;
    temp-> next = nodeToinsert;
}
void deleteNode(int position , Node* &head)
{
     if (position == 1 )
     {  Node* temp = head ;
        head = head -> next ;
        //memory free start node 
        temp -> next = NULL;
        delete temp ;
     }
     else
     {
        //deleting node 
        Node* curr = head ;
        Node* prev = NULL;
        int cnt = 1 ;
        while (cnt < position ){
             prev = curr;
             curr = curr->next;
             cnt++;
        }
        prev -> next = curr-> next ;
        curr -> next = NULL;
        delete curr ;
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
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);

    std::cout << "Original list: ";
    print(head);

    // Sorting the list
    head = sortList(head);

    std::cout << "Sorted list: ";
    print(head);

    return 0;
}