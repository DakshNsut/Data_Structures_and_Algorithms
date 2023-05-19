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

void print(Node* hptr){
    if(hptr == NULL){
        cout << "Empty List" << endl;
        return;
    }

    while(hptr){
        cout << hptr->data << " ";
        hptr = hptr -> next;
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

Node* mergeSort(Node* hptr){

    // Base Case
    if(hptr == NULL || hptr -> next == NULL){
        return hptr;
    }

    // -------------------------------------- Finding middle of LL --------------------------------------
    Node* slow = hptr;
    Node* fast = hptr;

    // (from s to mid-1)
    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // ---------------------------------- Breaking the LL into two halves ----------------------------------
    // here mid = slow (from s to mid-1)
    Node* leftHead = hptr;
    Node* rightHead = slow -> next;

    slow -> next = NULL;

    // ------------------------------ Performing merge sort of the two halves ------------------------------
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    // merging the two halves
    Node* result = merge(leftHead, rightHead);

    // had to be taken likethat, not directly return leftHead
    // because result can be = leftHead or rightHead
    // because we are doing merging operation without Data replacement
    return result;
}

// Time Complexity: O(nlogn)
// Auxiliary space: O(logn)

int main(){

    Node* n1 = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(9);
    Node* n4 = new Node(5);
    Node* n5 = new Node(1);

    // Next pointers
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;

    Node* head = n1;
    cout << "Linked List before sorting: ";
    print(head);

    Node* ans = mergeSort(head);
    cout << "Linked List after sorting: ";
    print(ans);
    return 0;
}