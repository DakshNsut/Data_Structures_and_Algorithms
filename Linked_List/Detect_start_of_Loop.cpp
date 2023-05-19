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

Node* DetectLoopStart (Node* hptr){

    if(hptr == NULL){
        cout << "No loop";
        return NULL;
    }

    Node* slow = hptr;
    Node* fast = hptr;
    bool flag = false;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            cout << "Yes loop" << endl;
            flag = true;
            break;
        }
    }

    // No loop
    if(!flag){
        cout << "No loop" << endl;
        return NULL;
    }

    // Yes loop, now find it's start
    slow = hptr;
    // fast = is at its position

    while(slow != fast){
        fast = fast -> next;
        slow = slow -> next;
    }

    return slow;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    Node* n1 = new Node(5);
    Node* n2 = new Node(6); n1 -> next = n2;
    Node* n3 = new Node(3); n2 -> next = n3;
    Node* n4 = new Node(4); n3 -> next = n4;
    Node* n5 = new Node(8);
    head = n1;

    // Loop
    n4 -> next = n2;

    Node* ans = DetectLoopStart(head);
    if(ans != NULL){
        cout << "Start of the Loop is: " << ans -> data << endl;
    };

    return 0;
}