#include<iostream>
#include<queue>
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

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data <= root->data){
        root->left = insertIntoBST(root->left, data);
    }
    else{
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void levelordertraversal(Node* root){
    if(root == NULL) return; // Check for empty tree

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//postorder traversal LRN

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* takeInput(Node* root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

int main()
{
    Node* root = NULL;
    cout << "Enter the data to create a binary search tree: (end input with -1)" << endl;
    root = takeInput(root);
    cout << "Level order traversal of the binary search tree is: " << endl;
    levelordertraversal(root);
    cout << "Inorder traversal of the binary search tree is: " << endl;
    inorder(root);
    cout << endl<<"Preorder traversal of the binary search tree is: " << endl;
    preorder(root);
    cout << endl<<"Postorder traversal of the binary search tree is: " << endl;
    postorder(root);
    
    return 0;
}
