#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
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

void insertNode(Node *&tail, int element, int d)
{
    // assuming that the element is present in the last
    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        // assuming that the element is present in the list

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "list is empty , please check again" << endl;
        return;
    }
    else
    {
        // non empty
        // assuming that value is  present in the list
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        //1 node linked list 
        if(curr == prev){
           tail = NULL;
           return ;
        }   
        //>=2 node linked list 
       else if(tail==curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&tail)
{    Node *temp = tail;
    if(tail == NULL)
    {
        cout<<"the list is empty "<<endl;
        return ;
    }
       
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
int main()
{

    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 3, 10);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    return 0;
}