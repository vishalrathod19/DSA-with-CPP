#include <iostream>

// Definition for singly-linked list.
class node {
public:
    int data;
    node *next;
    
    // Constructor
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to find the middle of the linked list
node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
node* merge(node* left, node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    node* ans = new node(-1); // Temporary dummy node
    node* temp = ans;

    // Merging the two lists
    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    // Attach the remaining nodes
    while (left != NULL) {
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }
    while (right != NULL) {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }

    node* result = ans->next;
    delete ans; // Delete the temporary dummy node
    return result;
}

// Function to sort the linked list using merge sort
node* mergeSort(node *head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Find the middle of the linked list
    node* mid = findMid(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // Recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge both sorted halves
    node* result = merge(left, right);

    return result;
}

// Utility function to print the linked list
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Utility function to insert a new node at the end of the linked list
void insertAtEnd(node* &head, int data) {
    if (head == NULL) {
        head = new node(data);
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new node(data);
}

int main() {
    node* head = NULL;
    
    // Example: Insert nodes into the linked list
    insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);

    std::cout << "Original List: ";
    printList(head);

    // Apply merge sort
    head = mergeSort(head);

    std::cout << "Sorted List: ";
    printList(head);

    return 0;
}
