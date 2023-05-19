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

// Loop doesn't mean from last node to any node, it means any node to any node
void DetectLoop(Node* hptr){
    unordered_map<Node*, bool> m;

    Node* ptr = hptr;
    while (1){

        m[ptr] = true;
        ptr = ptr -> next;

        if(ptr == NULL){
            cout << "No loop" << endl;
            return;
        }

        if(m[ptr]){
            cout << "Yes loop" << endl;
            return;
        }

    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)

// Floyd's Cycle Detecting Algorithm
void DetectLoop (Node* hptr){

    if(hptr == NULL){
        cout << "No loop";
        return;
    }

    Node* slow = hptr;
    Node* fast = hptr;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                cout << "Yes loop";
                return;
            }
        }

        // Here because, never slow == fast became true and either fast or fast -> next == NULL
        cout << "No loop";
        return;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)

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

    tail->next = head->next->next;
    DetectLoop(head);    
    return 0;
}