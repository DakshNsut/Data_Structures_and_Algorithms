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

void printLL(Node* hptr){
    // This hptr is a local variable and any changes made to it won't reflect outside
    // Had this been that i would have passed the address, the situation would have been different
    while(hptr != NULL){
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

void DeleteAtPos(Node* &hptr, Node* &tptr, int pos){
    if(hptr == NULL){
        cout << "Empty List" << endl;
        return;
    }

    // Special Case, because first element has no previous
    if(pos == 1){
        Node* ptr = hptr;
        hptr = hptr -> next;
        delete ptr;
        return;
    }

    Node* prev = hptr;
    for (int i=0; prev -> next != NULL && i < pos-2; i++){
        prev = prev -> next;
    }

    if(prev -> next == NULL){
        cout << "Unidentified position " << endl;
        return;
    }

    // i == pos-2, prev == ll[pos-2];
    Node* ptr = prev -> next;
    if(prev -> next -> next == NULL) tptr = prev;
    prev -> next = prev -> next -> next;
    delete ptr;
}

void DeleteVal(Node* &hptr, Node* &tptr, int val){

    if(hptr == NULL){
        cout << "Empty List " << endl;
        return;
    }

    Node* prev = NULL;
    Node* ptr = hptr;

    while(ptr != NULL && ptr -> data != val){
        prev = ptr;
        ptr = ptr ->next;
    }

    if(ptr == NULL){
        cout << "Not Found " << endl;
        return;
    }

    // delete at head
    if(prev == NULL){
        hptr = hptr -> next;
        delete ptr;
        return;
    }

    if(ptr -> data == val) {
        // delete at end
        if(ptr -> next == NULL){
            tptr = prev;
        }
        prev -> next = prev -> next -> next;
        delete ptr;
    }

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    DeleteAtPos(head, tail, 1);
    printLL(head);

    InsertAtHead(head, tail, 11);
    InsertAtHead(head, tail, 22);
    InsertAtHead(head, tail, 33);
    InsertAtHead(head, tail, 44);
    printLL(head);

    DeleteAtPos(head, tail, 3);
    printLL(head);

    DeleteAtPos(head, tail, 1);
    printLL(head);

    DeleteVal(head, tail, 33);
    printLL(head);

    DeleteVal(head, tail, 11);
    printLL(head);

    DeleteVal(head, tail, 10);
    printLL(head);
    return 0;
}