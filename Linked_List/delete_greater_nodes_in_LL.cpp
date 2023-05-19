#include <iostream>
#define mod 1000000007
using namespace std;

// Delete nodes having greater values of right side

struct Node{
    int data;
    Node *next, *prev;

    Node(int a){
        data = a;
        next = prev = NULL;
    }
};

void InsertAtHead(Node* &hptr, int item){
    if(hptr == NULL){
        Node* newNode = new Node(item);
        hptr = newNode;
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

Node* reverse(Node* hptr){
    Node* curr = hptr;
    Node* prev = NULL;
    Node* nextCurr;

    while(curr){
        nextCurr = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = nextCurr;
    }
        
    return prev;
}

Node *deleteGreaterNodes(Node *head)
{
    head = reverse(head); // step 1

    Node* curr = head;
    int max = curr -> data;

    while(curr -> next != NULL){
        if(curr -> next -> data < max){
            Node* temp = curr -> next;
            curr -> next = temp -> next;
            delete temp;
        }
        else{
            max = curr -> next -> data;
            curr = curr -> next;
        }
    }

    head = reverse(head);
    return head;
}

int main(){
    Node* head = new Node(2);
    InsertAtHead(head, 7);
    InsertAtHead(head, 40);
    InsertAtHead(head, 0);
    InsertAtHead(head, -1);
    InsertAtHead(head, 6);
    InsertAtHead(head, -6);
    cout << "Linked List before deletion: ";
    print(head);

    head = deleteGreaterNodes(head);
    cout << "Linked List after deletion: ";
    print(head);
    return 0;
}