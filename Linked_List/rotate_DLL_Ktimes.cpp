#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;

    Node(int a){
        data = a;
        next = prev = NULL;
    }
};

void InsertAtHead(Node* &hptr, Node* &tptr, int item){
    if(hptr == NULL){
        Node* newNode = new Node(item);
        hptr = newNode;
        tptr = newNode;
        return;
    }

    Node* newNode = new Node(item);
    newNode -> next = hptr;
    hptr -> prev = newNode;

    hptr = newNode;
}

void print(Node* hptr){
    if(hptr == NULL){
        cout << "Empty List" << endl;
        return;
    }

    while(hptr){
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

// ---------------- Method 1 ---------------
void Rotate_k (Node* &hptr, int k){
    if(k==0 || hptr==NULL){
        return;
    }

    Node* curr = hptr;

    while(curr!=NULL && k!=0){
        curr = curr -> next;
        k--;
    }

    if(curr == NULL){
        return;
    }

    // getTail
    Node* tail = hptr;
    while(tail -> next != NULL){
        tail = tail -> next;
    }

    // Changing Links
    tail -> next = hptr;
    hptr -> prev = tail;

    curr -> prev -> next = NULL;
    curr -> prev = NULL;

    hptr = curr;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// ------------ Method 2 -------------
void Rotate_k (Node* &hptr, int k){
    if(k==0 || hptr==NULL){
        return;
    }

    // getTail
    Node* tail = hptr;
    while(tail -> next != NULL){
        tail = tail -> next;
    }

    // Converting DLL -> CLL
    hptr -> prev = tail;
    tail -> next = hptr;

    // Changing the head pointer
    while(k){
        hptr = hptr -> next;
        k--;
    }

    // Converting CLL -> DLL
    hptr -> prev -> next = NULL;
    hptr -> prev = NULL;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    Node* head = NULL, *tail = NULL;
    InsertAtHead(head, tail, 8);
    InsertAtHead(head, tail, 56);
    InsertAtHead(head, tail, 12);
    InsertAtHead(head, tail, 6);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 3);
    print(head);

    Rotate_k(head, 2);
    print(head);

    return 0;
}