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

// ---------------- Method 1 ----------------
void RemoveDuplicates(Node* hptr){
    Node* curr = hptr;

    while(curr){
        Node* temp = curr;
        while(temp){
            if(temp -> next != NULL && curr -> data == temp -> next -> data){
                Node* nodeToBeDeleted = temp -> next;
                temp -> next = temp -> next -> next;
                delete nodeToBeDeleted;
            }
            temp = temp -> next;
        }
        curr = curr -> next;
    }
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// --------------- Method 2 --------------
// sort LL and follow sorted LL approach

// Time Complexity: O(nlogn)
// Auxiliary space: O(1)

// ---------------- Method 3 ----------------
void RemoveDuplicates(Node* hptr){
    unordered_map <int, bool> m;
    Node* curr = hptr;
    Node* prev = NULL;
    // now curr will behave as prev;

    while(curr != NULL){
        if(m[curr -> data]){
            prev -> next = curr -> next;
            // don't change prev
            delete curr;
            curr = prev -> next;
        }
        else{
            m[curr -> data] = true;
            prev = curr;
            curr = curr -> next;
        }
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    Node* n1 = new Node(1);
    Node* n2 = new Node(2); n1 -> next = n2;
    Node* n3 = new Node(333); n2 -> next = n3;
    Node* n4 = new Node(2); n3 -> next = n4;
    Node* n5 = new Node(11);
    head = n1;
    printLL(head);

    RemoveDuplicates(head);
    printLL(head);
    return 0;
}