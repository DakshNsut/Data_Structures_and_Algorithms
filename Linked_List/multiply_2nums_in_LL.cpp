#include <iostream>
#define mod 1000000007
using namespace std;

// to find product of multiplying two numbers represented as a linked list

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
        cout << hptr -> data;
        hptr = hptr -> next;
    }
}

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long num1 = 0;
    Node* ptr1 = l1;

    while(ptr1){
        num1 = (ptr1 -> data + (num1 * 10) % mod) % mod;
        ptr1 = ptr1 -> next;
    }

    long long num2 = 0;
    Node* ptr2 = l2;

    while(ptr2){
        num2 = (ptr2 -> data + (num2 * 10) % mod) % mod;
        ptr2 = ptr2 -> next;
    }

    long long result = ( num1 * num2 ) % mod;

    return result;
}

// Time Complexity: O(n+m)
// Auxiliary space: O(1)

int main(){
    Node* head1 = NULL;
    InsertAtHead(head1, 2);
    InsertAtHead(head1, 2);
    print(head1); cout << " X ";

    Node* head2 = NULL;
    InsertAtHead(head2, 7);
    print(head2); cout << " = ";
 
    cout << multiplyTwoLists(head1, head2) << endl;
    return 0;
}