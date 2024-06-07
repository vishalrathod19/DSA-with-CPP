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

Node* getMid(Node* head)//this func find the middle of ll 
   {
       Node* slow = head ;
       Node* fast = head-> next;
       
       while(fast!=NULL&& fast->next!=NULL){
           fast = fast->next->next;
           slow = slow -> next ;
       }
       return slow ;
   }
   
Node* reverse(Node* head)//this func find the reverse of LL middle 
   {
       Node* curr = head;
       Node* prev = NULL;
       Node* next = NULL;
       
       while(curr!= NULL)
       {
           next = curr->next;
           curr -> next = prev;
           prev = curr;
           curr = next;
       }
       return prev;
   }
bool isPalindrome(Node *head)
    {
        if(head->next == NULL)
        {
            return true;
        }
        //step 1 -> find middle
        Node* middle = getMid(head);
        //step 2 -> reverse list after middle 
        Node* temp = middle -> next ;
        middle ->next = reverse(temp);
        //step 3 -> compare both halves 
        Node*head1 = head;
        Node*head2 = middle->next;
        while(head2!=NULL)
        {
            if(head1->data!=head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        //step 4 ->repeat second steps again

        temp = middle -> next ;
        middle ->next = reverse(temp);
        return true;
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
    InsertAtHead(head , 12);
    print (head);
    InsertAtHead(head , 15);
    print (head);
    InsertAtTail(tail,12);
    print (head);
    InsertAtTail(tail,15);
    print (head);
    InsertionAtPosition(head,3,10);
    print (head);
    if(isPalindrome(head)){
        cout<<"it is pallindrome";
    }
    else{
        cout<<"it is not pallindrome";
    }
    return 0 ; 
}