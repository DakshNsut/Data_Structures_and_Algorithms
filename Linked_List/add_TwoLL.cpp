#include <iostream>
using namespace std;

// Add two numbers represented by linked list

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void reverse(Node* &hptr){
    Node* curr = hptr;
    Node* prev = NULL;
    Node* nextCurr;

    while(curr){
        // Changing the links
        nextCurr = curr -> next;
        curr -> next = prev;

        // Updating the pointers
        prev = curr;
        curr = nextCurr;
    }

    hptr = prev;
}

void insertAtHead(Node* &hptr, int item){
    Node* newNode = new Node(item);

    newNode -> next = hptr;
    hptr = newNode;
}

void addTwoLists(Node* hptr1, Node* hptr2, Node* &ans){

    if(hptr1 == NULL){
        ans = hptr2;
        return;
    }

    else if(hptr2 == NULL){
        ans = hptr1;
        return;
    }

    reverse(hptr1);
    reverse(hptr2);

    Node* curr1 = hptr1;
    Node* curr2 = hptr2;
    int sum = 0;
    int carry = 0;

    while(curr1 != NULL && curr2 != NULL){
        sum = carry + curr1 -> data + curr2 -> data;
        carry = sum/10;

        insertAtHead(ans, sum%10);

        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }

    while(curr1 != NULL){
        sum = carry + curr1 -> data;
        carry = sum/10;

        insertAtHead(ans, sum%10);

        curr1 = curr1 -> next;
    }

    while(curr2 != NULL){
        sum = carry + curr2 -> data;
        carry = sum/10;

        insertAtHead(ans, sum%10);

        curr2 = curr2 -> next;
    }

    while(carry){
        insertAtHead(ans, carry%10);
        carry = carry / 10;
    }
}

// Time Complexity: O(n1+n2)
// Auxiliary space: O(ans.size())

void InsertAtHead(Node* &hptr, int item){
    Node* newNode = new Node(item);

    // Empty Linked List - Special Case
    if(hptr == NULL){
        hptr = newNode;
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

int main(){
    Node* head1 = NULL;

    InsertAtHead(head1, 9);
    InsertAtHead(head1, 9);
    InsertAtHead(head1, 9);
    print(head1);
    cout << "+" << endl;

    Node* head2 = NULL;
    InsertAtHead(head2, 3);
    InsertAtHead(head2, 0);
    InsertAtHead(head2, 1);
    print(head2);
    cout << "=" << endl;

    Node* res = NULL;
    addTwoLists(head1, head2, res);
    print(res);
    
    return 0;
}