#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* arb;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> arb = NULL;
    }
};

// ------------- METHOD 1 --------------
void print(Node* hptr){
    if(hptr == NULL){
        cout << "Empty List" << endl;
        return;
    }

    while(hptr){
        if(hptr -> arb != NULL){
            cout << "data = " << hptr -> data << " " << "random = " << hptr -> arb -> data << endl;
        }
        else{
            cout << "data = " << hptr -> data << " " << "random = NULL" << endl;
        }

        hptr = hptr -> next;
    }
    cout << endl;
}

void InsertAtTail(Node* &tptr, int item){
    Node* newNode = new Node(item);
    tptr -> next = newNode;
    tptr = newNode;
}

Node* cloneLL(Node* hptr){
    Node* clone = NULL;
    Node* cloneTail = NULL;

    // ----------------------------- Cloning next pointer -----------------------------

    // cloning first node
    Node* curr = hptr;
    Node* newNode = new Node(curr -> data);
    // updating head and tail both
    clone = newNode;
    cloneTail = newNode;
    // updating curr pointer
    curr = curr -> next;

    while(curr != NULL){
        InsertAtTail(cloneTail, curr -> data);
        curr = curr -> next;
    }

    // ----------------------------- Cloning arb pointer -----------------------------
    unordered_map<Node*, Node*> connect; // connect between original node and clone node
    curr = hptr; // original node
    Node* ptr2 = clone; // clone node

    while(curr != NULL){
        connect[curr] = ptr2;

        curr = curr -> next;
        ptr2 = ptr2 -> next;
    }

    curr = hptr;
    ptr2 = clone;
    while(ptr2 != NULL){
        ptr2 -> arb = connect[curr -> arb];

        curr = curr -> next;
        ptr2 = ptr2 -> next;
    }

    return clone;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// ------------ METHOD 2 -------------
Node* cloneLL(Node* hptr){
    Node* clone = NULL;
    Node* cloneTail = NULL;

    // ----------------------------- Cloning next pointer -----------------------------
    // cloning first node has been done seperately so that head pointer will be updated at first,
    // because later it is not needed to be updated

    // cloning first node
    Node* curr = hptr;
    Node* newNode = new Node(curr -> data);
    // updating head and tail both
    clone = newNode;
    cloneTail = newNode;
    // updating curr pointer
    curr = curr -> next;

    while(curr != NULL){
        InsertAtTail(cloneTail, curr -> data);
        curr = curr -> next;
    }

    // ------------------- Adding Clone Nodes in b/w Original Nodes -------------------

    Node* ptr1 = hptr;
    Node* ptr2 = clone;

    while(ptr1){
        Node* next1 = ptr1 -> next;
        Node* next2 = ptr2 -> next;
        ptr1 -> next = ptr2;
        ptr2 -> next = next1;

        ptr1 = next1;
        ptr2 = next2;
    }

    // -------------------------- Joining random pointers for cloneLL --------------------------
    Node* temp = hptr;
    while(temp != NULL){
        if(temp->arb != NULL){
            temp->next->arb = temp->arb->next;
        }

        temp = temp->next->next;
    }

    // ---------------------- Reverse back all the broken 'next' pointers ----------------------
    temp = hptr;
    while(temp){
        Node* nextTemp = temp->next;
        if(temp->next != NULL){
            temp -> next = temp->next->next;
        }
        temp = nextTemp;
    }

    return clone;
}

int main(){

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // Next pointers
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;

    // Random Pointers
    n1 -> arb = n2;
    n2 -> arb = n4;

    Node* head = n1;
    print(head);

    Node* result = cloneLL(head);
    print(result);

    return 0;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)