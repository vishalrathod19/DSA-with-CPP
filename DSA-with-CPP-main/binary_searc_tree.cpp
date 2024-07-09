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

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data <= root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) return; // Check for empty tree

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
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

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal LRN
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* takeInput(Node* root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

Node* minVal(Node* root) {
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* pred = NULL;
    while (root != NULL) {
        if (key <= root->data) {
            root = root->left;
        } else {
            pred = root;
            root = root->right;
        }
    }
    return pred;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* succ = NULL;
    while (root != NULL) {
        if (key >= root->data) {
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root==NULL){
        return NULL;
    }

    if(root->data == val){
        //0 child
        if(root->left ==  NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(left != NULL&& right == NULL){
            Node* temp = root->left;
            delete root;
        }
        else if(right != NULL&& left == NULL){
            Node* temp = root->right;
            delete root;
        }
        //2 child
       if(root -> left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
       }

    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
    }
    else{
        root->right = deleteFromBST(root->right, val);
    }
}

int main() {
    Node* root = NULL;
    //50 20 70 10 30 90 110 -1
    cout << "Enter the data to create a binary search tree: (end input with -1)" << endl;
    root = takeInput(root);

    cout << "Level order traversal of the binary search tree is: " << endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal of the binary search tree is: " << endl;
    inorder(root);
    cout << endl << "Preorder traversal of the binary search tree is: " << endl;
    preorder(root);
    cout << endl << "Postorder traversal of the binary search tree is: " << endl;
    postorder(root);
    cout << endl;

    cout << "Minimum value in the binary search tree is: " << minVal(root)->data << endl;
    cout << "Maximum value in the binary search tree is: " << maxVal(root)->data << endl;

    int key = 30; // Example key
    Node* pred = inorderPredecessor(root, key);
    Node* succ = inorderSuccessor(root, key);
 
    cout << "Inorder Predecessor of " << key << " is: " << pred->data << endl;
  
    cout << "Inorder Successor of " << key << " is: " << succ->data << endl;
    root = deleteFromBST(root, 50);


    cout << "Level order traversal of the binary search tree is: " << endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal of the binary search tree is: " << endl;
    inorder(root);
    cout << endl << "Preorder traversal of the binary search tree is: " << endl;
    preorder(root);
    cout << endl << "Postorder traversal of the binary search tree is: " << endl;
    postorder(root);
    cout << endl;

    cout << "Minimum value in the binary search tree is: " << minVal(root)->data << endl;
    cout << "Maximum value in the binary search tree is: " << maxVal(root)->data << endl;

    return 0;
}
