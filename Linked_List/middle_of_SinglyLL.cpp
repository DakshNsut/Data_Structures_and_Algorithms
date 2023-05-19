#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void printLL(Node* hptr){
    if(hptr == NULL){
        return;
    }

    // This hptr is a local variable and any changes made to it won't reflect outside
    // Had this been that i would have passed the address, the situation would have been different
    while(hptr != NULL){
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

// ----------------- Naive Method -----------------
int getLength (Node* hptr){
    int len = 0;
    while(hptr != NULL){
        hptr = hptr -> next;
        len++;
    }

    return len;
}

Node* getMiddle1(Node* hptr){
    int index = getLength(hptr)/2;
    Node* temp = hptr;

    while(index--){
        temp = temp -> next;
    }

    return temp;
}

// Time Complexity: O(n) - two traversals
// Auxiliary space: O(1)

// ----------- Optimised Method -------------
Node* getMiddle2(Node* hptr){
    Node* slow = hptr;
    Node* fast = hptr;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

// Time Complexity: O(n) - one traversal
// Auxiliary space: O(1)

void InsertAtHead(Node* &hptr, Node* &tptr, int item){
    Node* newNode = new Node(item);

    // Empty Linked List // Special Case
    if(hptr == NULL){
        hptr = newNode;
        tptr = newNode;
        return;
    }

    // We allocate memory dynamically because we don't want
    // this new memory allocated to be erased when it goes out of scope
    // ALso, we don't know how much memory will be allocated, so take from heap

    newNode -> next  = hptr;
    hptr = newNode;

    // return hptr; // No need because we took reference of head
    // This is better because making a temp copy will take 8bytes space (pointer size = 8, fixed)
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 7);
    InsertAtHead(head, tail, 5);
    InsertAtHead(head, tail, 3);
    InsertAtHead(head, tail, 9);
    InsertAtHead(head, tail, 11);
    printLL(head);

    Node* mid = getMiddle1(head);
    if(mid == NULL){
        cout << "NULL" << endl;
        return 0;
    }
    cout << mid->data << endl;

    mid = getMiddle2(head);
    if(mid == NULL){
        cout << "NULL" << endl;
        return 0;
    }
    cout << mid->data << endl;
}