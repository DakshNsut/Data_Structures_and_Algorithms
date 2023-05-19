#include <iostream>
#include <unordered_map>
using namespace std;

// Given a sorted doubly linked list, find pairs whose sum equals given sum

struct Node{
    int data;
    Node *next, *prev;

    Node(int a){
        data = a;
        next = prev = NULL;
    }
};

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

// ---------------------------- Two-pointer Technique ----------------------------
Node* getTail(Node* hptr){
    while(hptr!=NULL && hptr->next!=NULL){
        hptr = hptr -> next;
    }
    return hptr;
}

void findPairSum(Node* hptr, int value){
    Node* low = hptr;
    Node* high = getTail(hptr);
    bool flag = false;

    while(low != high && high -> next != low){
        int sum = low -> data + high -> data;

        if(sum == value){
            cout << low -> data << " " << high -> data << endl;
            flag = true;
            low = low -> next;
            high = high -> prev;
        }

        else if(sum < value){
            low = low -> next;
        }

        else{
            high = high -> prev;
        }
    }

    if(flag == false){
        cout << "No pair Found" << endl;
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    // Sorted List Approach
    Node* n1 = new Node(1);
    Node* n2 = new Node(2); n1 -> next = n2; n2 -> prev = n1;
    Node* n3 = new Node(3); n2 -> next = n3; n3 -> prev = n2;
    Node* n4 = new Node(4); n3 -> next = n4; n4 -> prev = n3;
    Node* n5 = new Node(5); n4 -> next = n5; n5 -> prev = n4;
    Node* head = n1;

    print(head);
    findPairSum(head, 7);
}


// -------------------------- HASHING -----------------------------
void findPairSum(Node* hptr, int value){
    unordered_map<int, Node*> um;
    // we map it to Node* (as in arrays we used to map with index) to check later that it doesn't belong to the same index/address
    bool flag = false;

    for(Node* ptr1 = hptr; ptr1 != NULL; ptr1 = ptr1 -> next){
        int x = value - ptr1->data;
        if(um.find(x) != um.end() && um[x] != ptr1){
            cout << ptr1->data << " " << x << endl;
            flag = true;
        }

        um[ptr1->data] = ptr1;
    }

    if(flag == false){
        cout << "No pair found";
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    Node* n1 = new Node(2);
    Node* n2 = new Node(2); n1 -> next = n2; n2 -> prev = n1;
    Node* n3 = new Node(2); n2 -> next = n3; n3 -> prev = n2;
    Node* n4 = new Node(2); n3 -> next = n4; n4 -> prev = n3;
    Node* n5 = new Node(2); n4 -> next = n5; n5 -> prev = n4;
    Node* head = n1;

    print(head);
    findPairSum(head, 4);
    // should give C(5, 2) = 10 pairs but gives only 4 (anomalous)
}