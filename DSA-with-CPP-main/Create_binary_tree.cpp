#include <iostream>
#include <queue>

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

Node* buildTree(Node* root) {
    cout << "Enter the data: "<<endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << ": "<<endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << ": "<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {//purana level complete ho gaya hai
            cout << endl;
            if (!q.empty()) {//queue still has some child nodes0258
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

//inorder traversal LNR

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//preorder traversal NLR

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

void BuildFromLevelorder(Node* &root){
    queue<Node*> q;
    q.push(root);
    cout<<"Enter the data for root"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter the data for left child of "<<temp->data<<endl;
        cin>>data;
        if(data!=-1){
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout<<"Enter the data for right child of "<<temp->data<<endl;
        cin>>data;
        if(data!=-1){
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}
int main() {
    Node* root = NULL;
    root = buildTree(root);
    // Sample input:1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Printing the level order traversal output: " << endl;
    levelOrderTraversal(root);
    cout << "Printing the inorder traversal output: " << endl;
    inorder(root);
    cout <<endl<<"Printing the preorder traversal output: " << endl;
    preorder(root);
    cout <<endl<<"Printing the postorder traversal output: " << endl;
    postorder(root);
    cout<<endl;
    BuildFromLevelorder(root);
    return 0;
}
