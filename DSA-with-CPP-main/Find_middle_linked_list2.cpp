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

Node *findMiddle(Node *head)
{
      if (head == NULL||head->next==NULL)
      { 
        return NULL;
      }     
      if (head->next->next==NULL)
      {
        return head->next;
      }
      Node* slow = head ;
      Node* fast = head->next;
      while(fast!=NULL)
      {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
      }
    return slow;
} 

int main ()
{
    Node* node1= new Node(20);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtHead(head , 12);
    print (head);
     InsertAtHead(head , 13);
    print (head);
    InsertAtHead(head , 15);
    print (head);
     InsertAtHead(head , 18);
    print (head);
    InsertAtTail(tail,17);
    print (head);
    InsertAtTail(tail,15);
    print (head);
    InsertAtTail(tail,19);
    print (head);
    InsertAtTail(tail,25);
    print (head);
     InsertAtTail(tail,28);
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