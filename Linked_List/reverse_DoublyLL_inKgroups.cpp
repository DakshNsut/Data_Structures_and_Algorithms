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

// ----------------- ITERATIVELY ----------------
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
            curr -> prev = nextCurr;

            prev = curr;
            curr = nextCurr;
            count++;
        }

        if(ans == NULL){
            ans = prev;
            ans -> prev = NULL;
        }

        if(globalPrev != NULL){
            globalPrev -> next = prev;
            prev -> prev = globalPrev;
        }

        globalPrev = start;
        start = curr;
    }

    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// ----------------- RECURSIVELY -----------------
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
    int count = 1;
    while(curr != NULL && count <= k ){
        nextHead = curr -> next;
        curr -> next = prev;
        curr -> prev = nextHead;

        prev = curr;
        curr = nextHead;
        count++;
    }

    hptr -> next = Reverse_K(nextHead, k);
    if(hptr -> next!=NULL){
        hptr -> next -> prev = hptr;
    }

    prev -> prev = NULL;
    // This will be the head of the new list,
    // and also the head of the reversed list to be connected to the head -> next
    return prev;
}

// Time Complexity: O(n)
// Auxiliary space: O(k)

int main(){
    Node* head = NULL, *tail = NULL;
    InsertAtHead(head, tail, 8);
    InsertAtHead(head, tail, 56);
    InsertAtHead(head, tail, 12);
    InsertAtHead(head, tail, 6);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 3);
    print(head);

    head = Reverse_K(head, 2);
    print(head);

    head = Reverse_K(head, 3);
    print(head);

    return 0;
}