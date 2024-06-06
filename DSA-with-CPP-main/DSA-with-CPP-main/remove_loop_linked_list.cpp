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
Node* detectLoop(Node* head){
    if(head == NULL)
    {
        return NULL;
    }
    Node* slowPointer = head;
        Node* fastPointer = head;

        while (slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer){
                return slowPointer;
        }
        }
        return NULL;
}

Node * getStartingNode(Node * head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node * intersection = detectLoop(head);
    Node * slow = head ;
    while( slow != intersection)
    {
          slow = slow->next ;
          intersection = intersection -> next ;
    }
    return slow;
}

void removeLoop(Node* head)
{
    if(head == NULL)
    {
        return ;
    }

    Node * start = getStartingNode(head);
    Node * temp = start ;
    while(temp->next != start)
    {
         temp = temp->next ;
    }
    temp ->next = NULL;
}
int main ()
{
    Node* node1= new Node(10);
   // cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
   /* InsertAtHead(head , 12);
    print (head);
    InsertAtHead(head , 15);
    print (head);*/
    InsertAtTail(tail,12);
    print (head);
    InsertAtTail(tail,15);
    print (head);
    InsertionAtPosition(head,3,22);
    print (head);
    tail->next = head->next;
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    if(detectLoop(head)){
        cout << "Loop exists in the"
             << " Linked List" << endl;
     }
    else
        cout << "Loop does not exists "
             << "in the Linked List" << endl;
    
    Node * loop = getStartingNode(head);
    cout<<"Loop starts at "<<loop->data <<endl;
    removeLoop(head);
    print(head);
    return 0; 
}
