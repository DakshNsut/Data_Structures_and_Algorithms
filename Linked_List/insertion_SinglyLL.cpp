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

void InsertAtPos(Node* &hptr, Node* &tptr, int pos, int item){
    Node* prev = hptr;

    // Special Case
    if(pos == 1){
        InsertAtHead(hptr, tptr, item);
        return ;
    }

    for(int i = 0; prev -> next != NULL && i < pos-2; i++) {
        prev = prev -> next;
    }

    Node* newNode = new Node(item);
    newNode->next = prev->next;
    prev->next = newNode;

    // Special Case
    if(newNode -> next == NULL){
        tptr = newNode;
    }
}

// Can't remove it because this is also implemented in InsertAtPos
// Special Need is because we don't have to traverse to the end.
void InsertAtTail(Node* &hptr, Node* &tptr, int item){
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

    tptr -> next  = newNode;
    tptr = newNode;

    // return hptr; // No need because we took reference of head
    // This is better because making a temp copy will take 8bytes space (pointer size = 8, fixed)
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 33);
    printLL(head);

    InsertAtHead(head, tail, 22);
    printLL(head);

    InsertAtPos(head, tail, 1, 11);
    printLL(head);

    InsertAtPos(head, tail, 4, 44);
    printLL(head);

    InsertAtTail(head, tail, 55);
    printLL(head);

    return 0;
}