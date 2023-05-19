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

// ------------ With Data Replacement -------------
void sort_012(Node* hptr){
    Node* curr = hptr;
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;

    while(curr) {
        if(curr -> data == 0){
            count_0++;
        }

        else if(curr -> data == 1){
            count_1++;
        }

        else if(curr -> data == 2){
            count_2++;
        }
        curr = curr -> next;
    }

    curr = hptr;
    while(curr){
        while(count_0){
            curr -> data = 0;
            count_0--;
            curr = curr -> next;
        }

        while(count_1){
            curr -> data = 1;
            count_1--;
            curr = curr -> next;
        }

        while(count_2){
            curr -> data = 2;
            count_2--;
            curr = curr -> next;
        }
    }
}

// ------------ Without Data Replacement -------------
void sort_012(Node* &hptr){

    // Dummy Nodes for the Three LLs
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail =twoHead;

    // --------------------------------- Creating Three LLs ---------------------------------
    Node* curr = hptr;
    while(curr){

        if(curr -> data == 0){
            zeroTail -> next = curr;
            zeroTail = curr;
        }

        else if(curr -> data == 1){
            oneTail -> next = curr;
            oneTail = curr;
        }

        else if(curr -> data == 2){
            twoTail -> next = curr;
            twoTail = curr;
        }

        curr = curr -> next;
    }

    zeroTail -> next = NULL;
    oneTail -> next = NULL;
    twoTail -> next = NULL;

    // --------------------------------- Merging Three LLs ---------------------------------

    // If OneLL is empty (is the only problem)
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
        oneTail -> next = twoHead -> next;
    }
    else{
        zeroTail -> next = twoHead -> next;
    }

    // New head
    hptr = zeroHead -> next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

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

void print(Node* hptr){
    if(hptr == NULL){
        return;
    }

    Node* curr = hptr;
    cout << curr->data << " ";
    curr = curr->next;

    while(curr != NULL && curr != hptr){
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);
    cout << "Linked List before sorting: ";
    print(head);

    sort_012(head);
    cout << "Linked List after sorting: ";
    print(head);
    return 0;
}