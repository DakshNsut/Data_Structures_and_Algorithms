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

int getLength(Node* hptr){
    int len = 0;
    while(hptr != NULL){
        len++;
        hptr = hptr -> next;
    }

    return len;
}

void print(Node* hptr){
    while(hptr != NULL){
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

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

void InsertAtPos (Node* &hptr, Node* &tptr, int item, int pos){
    Node* newNode = new Node(item);

    if(pos == 1){
        InsertAtHead(hptr, tptr, item);
        return;
    }

    Node* ptr = hptr;
    for (int i=0; ptr!= NULL && i<pos-2; i++){
        ptr = ptr -> next;
    }

    // ------ Special Case ----------
    if(ptr == NULL || ptr -> next == NULL){
        InsertAtTail(hptr, tptr, item);
        return;
    };

    Node* ptrNext = ptr -> next;

    ptr -> next = newNode;
    newNode -> prev = ptr;

    newNode -> next = ptrNext;
    ptrNext -> prev = newNode;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 5);
    InsertAtHead(head, tail, 4);
    print(head);

    InsertAtTail(head, tail, 6);
    print(head);

    InsertAtPos(head, tail, 7, 2);
    print(head);
}
