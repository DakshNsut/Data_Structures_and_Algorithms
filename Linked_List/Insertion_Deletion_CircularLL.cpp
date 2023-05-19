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

void print(Node* tptr){

    if(tptr == NULL){
        cout << "Empty" << endl;
        return;
    }

    Node* ptr = tptr;
    do{
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    } while(ptr != tptr);
    cout << endl;
}

void InsertAfterVal(Node* &tptr, int val, int item){

    if(tptr == NULL){
        Node* newNode = new Node(item);
        newNode -> next = newNode;
        tptr = newNode;
        return;
    }

    Node* ptr = tptr;

    while (ptr -> data != val){
        ptr = ptr -> next;
        if(ptr == tptr){
            cout << val << " not found " << endl;
            return;
        }
    }

    Node* newNode = new Node(item);
    newNode -> next = ptr -> next;
    ptr -> next = newNode;

    if(ptr == tptr){
        tptr = newNode;
    }
    
}

void DeleteVal (Node* &tptr, int val){

    if (tptr == NULL){
        cout << "Empty List"<< endl;
        return;
    }

    Node* prev = tptr;
    Node* ptr = tptr -> next;
    while(ptr -> data != val){
        prev = ptr;
        ptr = ptr -> next;

        if( ptr == tptr -> next ){
            cout << val << " not found" << endl;
            return;
        }
    }

    // new link
    prev -> next = ptr -> next;

    // tail node to be deleted, change the tptr
    if(ptr == tptr){
        tptr = tptr -> next;
    }

    // single element left, and this is to be deleted
    // if(ptr == ptr -> next){
    //     tptr = NULL;
    // }
    // // Not needed because tptr = tptr -> next = NULL;

    delete ptr;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){

    Node* tail = NULL;
    print(tail);

    InsertAfterVal(tail, 5, 3);
    print(tail);
    InsertAfterVal(tail, 3, 5);
    print(tail);
    InsertAfterVal(tail, 5, 7);
    print(tail);
    InsertAfterVal(tail, 7, 9);
    print(tail);
    InsertAfterVal(tail, 5, 6);
    print(tail);
    InsertAfterVal(tail, 9, 10);
    print(tail);

    DeleteVal(tail, 10);
    print(tail);
    DeleteVal(tail, 6);
    print(tail);
    DeleteVal(tail, 7);
    print(tail);
    DeleteVal(tail, 3);
    print(tail);
    DeleteVal(tail, 5);
    print(tail);
    DeleteVal(tail, 9);
    print(tail);
}