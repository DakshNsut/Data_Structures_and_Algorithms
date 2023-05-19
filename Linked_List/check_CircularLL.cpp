#include <iostream>
#include <unordered_map>
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

void print(Node* hptr){
    if(hptr == NULL){
        return;
    }

    while(hptr != NULL){
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

void isCircular (Node* hptr){
    if(hptr == NULL){
        cout << "Is a Circular Linked List" << endl;
        return;
    }

    Node* ptr = hptr;
    do{
        ptr = ptr -> next;
    } while(ptr != NULL && ptr != hptr); // ptr != NULL (for a Singly LL), ptr != hptr (for a Circular LL)
    
    if(ptr == NULL){
        cout << "Not a Circular Linked List" << endl;
        return;
    }

    else if(ptr == hptr){
        cout << "Is a Circular Linked List" << endl;
        return;
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// To check a loop (last node can be connected to any node)
void isCircular (Node* hptr){
    unordered_map<Node*, bool> m;

    Node* ptr = hptr;
    while (1){
        m[ptr] = true;
        ptr = ptr -> next;

        if(ptr == NULL){
            cout << "Not a CLL" << endl;
            return;
        }

        if(m[ptr]){
            cout << "Is a CLL" << endl;
            return;
        }
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

void InsertAtHead(Node* &hptr, Node* &tptr, int item){
    Node* newNode = new Node(item);

    // Empty Linked List // Special Case
    if(hptr == NULL){
        hptr = newNode;
        tptr = newNode;
        return;
    }

    newNode -> next  = hptr;
    hptr = newNode;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 33);
    InsertAtHead(head, tail, 22);
    InsertAtHead(head, tail, 11);
    InsertAtHead(head, tail, 55);
    InsertAtHead(head, tail, 66);
    InsertAtHead(head, tail, 88);
    print(head);

    isCircular(head);
    tail->next = head;
    isCircular(head);
    return 0;
}