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
};
void InsertAtTail(Node* &tail,int d)
{
    //new node create;
    Node* temp = new Node(d);
    tail->next = temp ;
    tail = tail->next ;
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

void InsertionAtPosition(Node* &head,int postion , int d)
{
    Node*temp = head;
    int cnt = 1;
    while(cnt<postion-1 && temp!=nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }
    Node* nodeToinsert=new Node(d);
    nodeToinsert=temp->next;
    temp-> next = nodeToinsert;
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
    return 0 ; 
}