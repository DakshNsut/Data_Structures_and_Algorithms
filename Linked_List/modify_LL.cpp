#include <iostream>
using namespace std;

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
        cout << hptr -> data << " ";
        hptr = hptr -> next;
    }
    cout << endl;
}

// Modifies the list such that all even nodes are before all odd ones
// ------------- Method 1 ---------------
Node* divide(int N, Node *head){
    Node* OddHead = NULL;
    Node* OddTail = NULL;
    Node* EvenHead = NULL;
    Node* EvenTail = NULL;

    Node* temp = head;
    while(temp){
        Node* nextTemp = temp -> next;
        if(temp -> data % 2 == 0){
            if(!EvenHead){
                EvenHead = temp;
                EvenTail = temp;
                temp -> next = NULL;
            }
            else{
                EvenTail -> next = temp;
                EvenTail = temp;
                temp -> next = NULL;
            }
        }

        if(temp -> data % 2 != 0){
            if(!OddHead){
                OddHead = temp;
                OddTail = temp;
                temp -> next = NULL;
            }
            else{
                OddTail -> next = temp;
                OddTail = temp;
                temp -> next = NULL;
            }
        }

        temp = nextTemp;
    }

    if(EvenTail == NULL){
        return OddHead;
    }

    EvenTail -> next = OddHead;
    return EvenHead;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// ---------- Method 2 --------------
Node* divide(int N, Node *head){
    Node* Tail = head;

    while(Tail -> next != NULL){
        Tail = Tail -> next;
    }

    // Finding odd nodes and putting them at the new_tail
    Node* curr = head;
    Node* prev = NULL;
    Node* nextCurr = NULL;
    Node* new_tail = Tail;

    while(curr != Tail){
        nextCurr = curr -> next;
        if(curr -> data % 2 != 0){
            if(prev == NULL){
                head = curr -> next;
                curr -> next = NULL;

                new_tail -> next = curr;
                new_tail = curr;
            }
            else{
                prev->next = curr->next;
                curr->next = NULL;
                    
                new_tail -> next = curr;
                new_tail = curr;
            }
        }
        else{
            prev = curr;
        }
        curr = nextCurr;

        // Special Case, when odd node is at Tail and Tail != tail(if this is so then it is already at its right place)
        if(curr == Tail && Tail!=new_tail){
            if(curr -> data % 2 != 0){
                if(prev == NULL){
                    head = curr -> next;
                    curr -> next = NULL;

                    new_tail -> next = curr;
                    new_tail = curr;
                }
                else{
                    prev->next = curr->next;
                    curr->next = NULL;
                    
                    new_tail -> next = curr;
                    new_tail = curr;
                }
            }
        }
    }
    return head;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    Node* head = new Node(2);
    InsertAtHead(head, 72);
    InsertAtHead(head, 40);
    InsertAtHead(head, 0);
    InsertAtHead(head, 1);
    InsertAtHead(head, 6);
    InsertAtHead(head, 63);
    print(head);

    head = divide(7, head);
    print(head);

    return 0;
}