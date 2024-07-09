#include<bits/stdc++.h>
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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void fillPreOrder(Node* root, vector<int> arr,int* i ){
    if(root == NULL){
        return ;
    }
    root->data = arr[++*i];
    fillPreOrder(root->left,arr,i);
    fillPreOrder(root->right,arr,i);

}

void converttoMinHeap(Node* root){
    if(root == NULL){
        return ;
    }
    vector<int> arr;
    int i  = -1;
    inorder(root);
    
    fillPreOrder(root,arr,&i);
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    converttoMinHeap(root);
    preOrder(root);
    return 0;
}
