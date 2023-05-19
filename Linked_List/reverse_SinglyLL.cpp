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

    while(hptr != NULL){
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

// -------------- ITERATIVELY --------------
void Reverse1(Node* &hptr){
    Node* prev = NULL;
    Node* curr = hptr;
    Node* nextHead = NULL;

    while(curr != NULL){
        nextHead = curr -> next;
        curr -> next = prev;

        // maintain the sequence below
        prev = curr;
        curr = nextHead;
    }
    hptr = prev;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// -------------- RECURSIVELY --------------
void Reverse2(Node* &hptr, Node* curr, Node* prev = NULL){
    if(curr == NULL){
        hptr = prev;
        return;
    }

    Node* nextHead = curr -> next;
    curr -> next = prev;

    prev = curr;
    curr = nextHead;

    Reverse2(hptr, curr, prev);
}

// Time Complexity: O(n)
// Auxiliary space: O(n) - recursion call stack

void InsertAtTail(Node* &hptr, Node* &tptr, int item){
    Node* newNode = new Node(item);

    // Empty Linked List // Special Case
    if(hptr == NULL){
        hptr = newNode;
        tptr = newNode;
        return;
    }

    tptr -> next  = newNode;
    tptr = newNode;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtTail(head, tail, 55);
    InsertAtTail(head, tail, 11);
    InsertAtTail(head, tail, 22);
    InsertAtTail(head, tail, 33);
    printLL(head);

    Reverse1(head);
    printLL(head);
    Reverse2(head, head);
    printLL(head);
    return 0;
}