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

// ---------------------- RECURSIVELY -------------------
Node* Reverse_K(Node* hptr, int k){

    // Base Case
    // If we reached the end nextHead == NULL
    // The remaining part of the list will be reversed and connected to head -> next
    if(hptr == NULL){
        return NULL;
    }

    // Reversing 'k' blocks of elements
    Node* curr = hptr;
    Node* prev = NULL;
    Node* nextHead = NULL;
    int count = 0;

    while(curr != NULL && count < k ){
        nextHead = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = nextHead;
        count++;
    }

    hptr -> next = Reverse_K(nextHead, k);

    // This will be the head of the new list,
    // and also the head of the reversed list to be connected to the head -> next
    return prev;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// -------------------- ITERATIVELY -------------------
Node* Reverse_K(Node* hptr, int k){
    Node* start = hptr;
    Node* globalPrev = NULL;
    Node* ans = NULL;

    while(start){
        int count = 1;
        Node* curr = start;
        Node* prev = NULL;
        Node* nextCurr = NULL;

        while(curr && count<=k){
            nextCurr = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = nextCurr;
            count++;
        }

        if(ans == NULL){
            ans = prev;
        }

        if(globalPrev != NULL){
            globalPrev -> next = prev;  //gloablPrev = end of last reversed LL // prev = start of next reversed LL 
        }

        globalPrev = start;
        start = curr; // because curr = nextCurr (which is to be addressed)
    }

    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

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

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 33);
    InsertAtHead(head, tail, 22);
    InsertAtHead(head, tail, 11);
    InsertAtHead(head, tail, 55);
    InsertAtHead(head, tail, 66);
    InsertAtHead(head, tail, 88);
    printLL(head);

    head = Reverse_K(head, 2);
    printLL(head);
    return 0;
}