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

// -------------- METHOD 1 ---------------
void checkPali(Node* hptr){
     int* arr = new int[1000];

     int len = 0;
     while(hptr){
         *(arr + len) = hptr -> data;
         hptr = hptr -> next;
         len++;
     }

     int s = 0;
     int e = len -1;

     while(s <= e){
         if(arr[s] != arr[e]){
             cout << "Not Palindromic" << endl;
             return;
         }
         s++;
         e--;
     }

     cout << "Palindromic" << endl;
 }
 
// Time Complexity: O(n)
// Auxiliary space: O(n)

// -------------- METHOD 2 --------------
void reverse(Node* startPrevious){
    Node* curr = startPrevious -> next;
    Node* prev = NULL;
    Node* nextCurr;

    while(curr){
        nextCurr = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = nextCurr;
    }

    startPrevious -> next = prev;
}

void checkPali(Node* hptr){
    Node* slow = hptr;
    Node* fast = hptr;

    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // Odd number of elements
    if(fast -> next == NULL){
        reverse(slow);
    }

    // Even number of elements
    else if (fast -> next -> next == NULL){
        reverse(slow);
    }

    Node* ptr1 = hptr;
    Node* ptr2 = slow -> next;

    while(ptr2 != NULL){
        if(ptr1 -> data != ptr2 -> data){
            cout << "Not a Palindrome" << endl;
            return;
        }

        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }

    cout << "Is a Palindrome" << endl;

    // Reverse back the original LL, so that the code doesn't do any changes to the original LL
    // so that if this LL is to be used further it can be
    reverse(slow);
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
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 0);
    print(head);

    checkPali(head);

    return 0;
}