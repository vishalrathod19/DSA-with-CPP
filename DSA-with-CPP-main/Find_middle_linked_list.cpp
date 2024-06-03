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

int getLength(Node* head)
{
    int len = 0 ;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *findMiddle(Node *head)
{
    int len = getLength(head);
    int ans = (len/2);
    
    Node * temp = head ;
    int cnt = 0 ;
    while(cnt<ans)
    {
        temp = temp->next ;
        cnt++;
    }
    return temp ;
} 

int main ()
{
    Node* node1= new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtHead(head , 12);
    print (head);
    InsertAtHead(head , 15);
    print (head);
     InsertAtHead(head , 18);
    print (head);
    InsertAtTail(tail,12);
    print (head);
    InsertAtTail(tail,15);
    print (head);
    //InsertionAtPosition(head,3,22);
    //print (head);
    cout<<endl;
    //deleteNode(3,head);
    //print (head);
    Node* middle = findMiddle(head);
    cout << "Middle element: " << middle->data << endl;
    return 0 ; 
}