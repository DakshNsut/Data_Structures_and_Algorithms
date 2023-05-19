#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void print(Node* hptr){
    while(hptr != NULL){
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

void InsertAtTail(Node* &hptr, Node* &tptr, int item){
    if(hptr == NULL){
        Node* newNode = new Node(item);
        hptr = newNode;
        tptr = newNode;
        return;
    }

    Node* newNode = new Node(item);
    tptr -> next = newNode;
    newNode -> prev = tptr;

    tptr = newNode;
}

void DeleteAtPos(Node* &hptr, Node* &tptr, int pos){

    // Start node to be deleted
    if(pos == 1){
        Node* nodeToBeDeleted = hptr;
        hptr = hptr -> next;
        hptr -> prev = NULL;
        delete nodeToBeDeleted;
        return;
    }

    Node* ptr = hptr; // previous node
    for(int i=0; ptr != NULL && i<pos-2; i++){
        ptr = ptr -> next;
    }

    if(ptr == NULL || ptr -> next == NULL){
        cout << "Unidentified position " << endl;
        return;
    }

    Node* nodeToBeDeleted = ptr -> next;

    // Tail node to be deleted
    if(nodeToBeDeleted -> next == NULL){
        tptr = tptr -> prev;
        tptr -> next = NULL;
        delete nodeToBeDeleted;
        return;
    }

    ptr -> next = nodeToBeDeleted -> next;
    nodeToBeDeleted -> next -> prev = ptr;

    delete nodeToBeDeleted;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtTail(head, tail, 6);
    InsertAtTail(head, tail, 7);
    InsertAtTail(head, tail, 16);
    print(head);

    DeleteAtPos(head, tail, 1);
    print(head);

    DeleteAtPos(head, tail, 3);
    print(head);

    DeleteAtPos(head, tail, 2);
    print(head);
}