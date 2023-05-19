#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;

    Node(int a){
        data = a;
        next = prev = NULL;
    }
};

void InsertAtHead(Node* &hptr, Node* &tptr, int item){
    if(hptr == NULL){
        Node* newNode = new Node(item);
        hptr = newNode;
        tptr = newNode;
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

// ------------- Insertion Sort With Data Replacement -------------
void sortKsortedDLL(Node* hptr, int k){

    if(hptr == NULL || hptr->next == NULL){
        return;
    }

    for(Node* curr = hptr -> next; curr != NULL; curr = curr -> next){
        Node* temp = curr;
        int x = curr -> data;

        while(temp->prev != NULL && temp->prev->data > x){
            temp -> data = temp->prev->data;
            temp = temp -> prev;
        }

        temp -> data = x;
    }
}

// Time Complexity: O(n*k)
// Auxiliary space: O(1)

// ----------- Insertion Sort With Link Replacement only -------------
void sortKsortedDLL(Node* &hptr, int k){

    if(hptr == NULL || hptr->next == NULL){
        return;
    }

    for(Node* curr = hptr -> next; curr != NULL; curr = curr -> next){
        Node* temp = curr;
        int x = curr -> data;

        while(temp->prev != NULL && temp->prev->data > x){
            Node* temp1 = temp->prev->prev;
            Node* temp2 = temp->prev;
            temp2->next = temp->next;
            temp2 -> prev = temp;

            if(temp -> next !=  NULL){
                temp->next->prev = temp2;
            }


            if(temp1 != NULL){
                temp1 -> next = temp;
            }

            temp -> prev = temp1;
            temp -> next = temp2;

        }

        if(temp->prev == NULL){
            hptr = temp;
        }

    }
}

// Time Complexity: O(n*k)
// Auxiliary space: O(1)

// -------------- MOST EFFICIENT APPROACH --------------
struct compare{
    bool operator()(Node* p1, Node* p2){
        return p1->data > p2->data;
    }
};

Node* sortKsortedDLL(Node* hptr, int k){

    if(hptr == NULL){
        return hptr;
    }

    // A new LL is being created/ not link replacement is being done
    Node* newHead = NULL;
    Node* newTail = NULL;

    // Creating min-heap and adding first k+1 elements to it
    priority_queue<Node*, vector<Node*>, compare> pq;
    for(int i = 0; hptr != NULL && i <= k; i++){
        pq.push(hptr);
        hptr = hptr -> next;
    }

    // Now taking out elements from min-heap and adding to the array
    while(!pq.empty()){

        if(newHead == NULL){
            newHead = pq.top(); // pq.top == Node* type
            newHead -> prev = NULL;

            newTail = newHead;
        }

        else{
            newTail -> next = pq.top();
            pq.top() -> prev = newTail;
            newTail = pq.top();
        }

        pq.pop();

        if(hptr != NULL){
            // hptr is at the last node which is to be added (k+1 elements were added, now hptr = k+2nd element)
            pq.push(hptr);

            hptr = hptr -> next;
        }
    }

    newTail -> next = NULL;
    return newHead;
}

// Time Complexity: O(n*logk)
// Auxiliary space: O(1)

int main(){
    Node* head = NULL, *tail = NULL;
    InsertAtHead(head, tail, 8);
    InsertAtHead(head, tail, 56);
    InsertAtHead(head, tail, 12);
    InsertAtHead(head, tail, 6);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 3);
    print(head);

    head = sortKsortedDLL(head, 2);
    print(head);

    return 0;
}