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
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

void swap(Node* a, Node* b){
    int temp = a -> data;
    a -> data = b -> data;
    b -> data = temp;
}

// Done with Data replacement
Node* partition(Node* hptr, Node* tail){
    Node* pivot = hptr;
    Node* curr = hptr -> next;
    Node* prev = hptr;

    while(curr != tail->next){
        if(curr->data < pivot->data){
            swap(prev->next, curr); // put curr at back
            prev = prev->next;
        }

        curr = curr->next;
    }

    swap(prev,pivot);
    return prev;
}

void quickSort(Node* hptr, Node* tail){
    // Just like l < h.
    if(hptr == NULL || hptr == tail){
        return;
    }

    Node* pivot = partition(hptr, tail);
    quickSort(hptr, pivot);
    quickSort(pivot->next, tail);
}

// Time Complexity: O(n^2)
// Auxiliary space: O(n)

Node* getTail(Node* hptr){
    while(hptr != NULL && hptr->next != NULL){
        hptr = hptr -> next;
    }

    return hptr;
}

int main(){
    Node* n1 = new Node(20);
    Node* n2 = new Node(6); n1 -> next = n2;
    Node* n3 = new Node(1); n2 -> next = n3;
    Node* n4 = new Node(7); n3 -> next = n4;
    Node* n5 = new Node(10); n4 -> next = n5;
    Node* head = n1;

    Node* tail = getTail(head);
    print(head);
    quickSort(head, tail);
    print(head);
}