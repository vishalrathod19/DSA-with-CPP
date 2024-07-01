#include<iostream>
using namespace std;

class Node {    
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void flatten(Node* root){
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left)
        {
            Node* pred = curr->left;
            while(pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}


void printInorder(Node* root){
    if(root==NULL)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(4);
    root->right->left = new Node(2);;
    root->right->left->right = new Node(5);
    flatten(root);
    printInorder(root);
    return 0;
}