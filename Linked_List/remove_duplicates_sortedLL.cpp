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

// remove duplicates in sorted linked list

void RemoveDuplicates(Node* hptr){

    if(hptr == NULL){
        return;
    }

	// Duplicates would surely be adjacent
    Node* curr = hptr;
    while(curr != NULL){
        if(curr -> next != NULL && curr -> data == curr -> next -> data){
            Node* ptr = curr -> next;
            curr -> next = curr -> next -> next;
            delete ptr;
        }
        else{
            curr = curr -> next;
        }
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

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

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    Node* n1 = new Node(1);
    Node* n2 = new Node(2); n1 -> next = n2;
    Node* n3 = new Node(2); n2 -> next = n3;
    Node* n4 = new Node(55); n3 -> next = n4;
    Node* n5 = new Node(80);
    head = n1;
    printLL(head);

    RemoveDuplicates(head);
    printLL(head);
    return 0;
}