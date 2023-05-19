#include <iostream>
using namespace std;

// Given a linked list that contains pointers of two types: next and child
// return a linked list containing all nodes connected using next pointer only.
// The resultant linked list should also be sorted

class Node{
    public:
    int data;
    Node* next, *child;

    Node(int data){
        this -> data = data;
        this -> child = this -> next = NULL;
    }
};

// ------------------ If horizontal LL is to be returned ----------------------------
void printChildLL(Node* hptr){
    if(hptr == NULL){
        cout << "Empty List" << endl;
        return;
    }

    while(hptr){
        cout << hptr -> data << " ";
        hptr = hptr -> child;
    }
    cout << endl;
}

void print(Node* hptr){
    if(hptr == NULL){
        cout << "Empty List" << endl;
        return;
    }

    while(hptr){
        cout << "datanode = " << hptr -> data << " ";
        cout << "childLL = ";
        printChildLL(hptr -> child);
        hptr = hptr -> next;
    cout << endl;
    }
}

Node* merge(Node* hptr1, Node* hptr2){

    if(hptr1 == NULL){
        return hptr2;
    }

    if(hptr2 == NULL){
        return hptr1;
    }

    // Left edge Case
    if(hptr1 -> data > hptr2 -> data){
        Node* temp = hptr1;
        hptr1 = hptr2;
        hptr2 = temp;
    }

    Node* ptr = hptr2;
    Node* prev = hptr1;
    Node* curr = hptr1 -> next;

    while(curr != NULL && ptr != NULL){
        if(ptr->data >= prev->data && ptr->data <= curr->data){
            Node* nextPtr = ptr->next;
            prev->next = ptr;
            ptr->next = curr;

            prev = ptr;
            ptr = nextPtr;
        }
        else{
            prev = curr;
            curr = curr -> next;
        }
    }

    // Right edge Case
    if(curr == NULL){
        prev -> next = ptr;
        return hptr1;
    }

    // had to be returned which head (leftHead/hptr1 or rightHead/hptr2) has the result
    return hptr1;
}

Node* flattenLL(Node* head){

    if(head == NULL){
        return NULL;
    }

	Node* nextLL = head -> next;
    Node* left = head;
    head -> next = NULL;

    // // flat 'down' LL
    Node* downTail = left;

    while(downTail != NULL){

        // Changing Links
        Node* nextChildNode = downTail -> child;
        downTail -> next = downTail -> child;
        downTail -> child = NULL;

        // Modifying pointers
        downTail = nextChildNode;
    }

    // flat 'right side' LL
    Node* right = flattenLL(nextLL);

    // Merging two LLs
    Node* ans = merge(left, right);

    return ans;
}

int main(){

    // Main LL
    Node* n1 = new Node(3);
    Node* n2 = new Node(5); n1 -> next = n2;

    // Child LL
    Node* c11 = new Node(4);
    Node* c12 = new Node(6); c11 -> child = c12;

    Node* c21 = new Node(11);
    Node* c22 = new Node(14); c21 -> child = c22;

    // child pointers
    n1 -> child = c11;
    n2 -> child  = c21;

    Node* head = n1;
    print(head);

    Node* ans = flattenLL(head);
    cout << "ans is == " << endl;
    print(ans);
    return 0;
}

// ------------------ If vertical LL is to be returned ----------------------------
void print(Node* hptr){
    if(hptr == NULL){
        cout << "Empty List" << endl;
        return;
    }

    while(hptr){
        cout << hptr -> data << " ";
        hptr = hptr -> child;
    }
    cout << endl;
}

Node* merge(Node* hptr1, Node* hptr2){

    if(hptr1 == NULL){
        return hptr2;
    }

    if(hptr2 == NULL){
        return hptr1;
    }

    // Left edge Case
    if(hptr1 -> data > hptr2 -> data){
        Node* temp = hptr1;
        hptr1 = hptr2;
        hptr2 = temp;
    }

    Node* ptr = hptr2;
    Node* prev = hptr1;
    Node* curr = hptr1 -> child;

    while(curr != NULL && ptr != NULL){
        if(ptr->data >= prev->data && ptr->data <= curr->data){
            Node* nextPtr = ptr->child;
            prev->child = ptr;
            ptr->child = curr;

            prev = ptr;
            ptr = nextPtr;
        }
        else{
            prev = curr;
            curr = curr -> child;
        }
    }

    // Right edge Case
    if(curr == NULL){
        prev -> child = ptr;
        return hptr1;
    }

    // had to be returned which head (leftHead/hptr1 or rightHead/hptr2) has the result
    return hptr1;
}

Node* flattenLL(Node* head){

    if(head == NULL){
        return NULL;
    }

	Node* nextLL = head -> next;
    Node* down = head;
    head -> next = NULL;

    // flat 'down' LL (no need already flat)

    // flat 'right side' LL
    Node* right = flattenLL(nextLL);

    // Merging two LLs
    Node* ans = merge(down, right);

    return ans;
}

// Time Complexity: O(n*m)
// Auxiliary space: O(n)

int main(){

    // Main LL
    Node* n1 = new Node(3);
    Node* n2 = new Node(5); n1 -> next = n2;

    // Child LL
    Node* c11 = new Node(4);
    Node* c12 = new Node(6); c11 -> child = c12;

    Node* c21 = new Node(11);
    Node* c22 = new Node(14); c21 -> child = c22;

    // child pointers
    n1 -> child = c11;
    n2 -> child  = c21;

    Node* head = n1;
    Node* ptr = head;

    while(ptr){
        print(ptr);
        ptr = ptr -> next;
    }

    Node* ans = flattenLL(head);
    print(ans);
    return 0;
}
