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

void Reverse(Node* &hptr){
    Node* curr = hptr;
    Node* previous = NULL;
    Node* nextHead;

    while(curr != NULL){
        nextHead = curr -> next;
        curr -> next = previous;
        curr -> prev = nextHead;

        previous = curr;
        curr = nextHead;
    }

    hptr = previous;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 5);
    InsertAtHead(head, tail, 4);
    InsertAtHead(head, tail, 6);
    InsertAtHead(head, tail, 8);
    print(head);

    Reverse(head);
    print(head);
    
}