#include <iostream>
using namespace std;

// Deque linked list implementation

struct Node
{
    int data;
    Node *prev, *next;
    // Function to get a new node
    static Node* getnode(int data)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};

struct Deque{
    Node* front, *rear;
    int Size;

    Deque(){
        front = NULL;
        rear = NULL;
        Size = 0;
    }

    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    bool isEmpty();
    int GetSize();
    void print(){
        if(front == NULL){ cout << "Empty"; return; }
        Node *f = front;
        Node *r = rear;
        while(f != r){
            cout << f->data << " ";
            f = f->next;
        }
        cout << r->data << endl;
    }
};

int Deque::GetSize(){
    return Size;
}

bool Deque::isEmpty(){
    return front == NULL;
}

void Deque::insertFront(int data) {
    Node *newNode = newNode->getnode(data);
    Size++;
    if(front == NULL){
        front = newNode;
        rear = newNode;
        return;
    }
    newNode -> next = front;
    front -> prev = newNode;
    front = newNode;
}

// Function to insert an element
// at the rear end
void Deque::insertRear(int data) {
    Node *newNode = newNode->getnode(data);
    Size++;
    if(rear == NULL){
        front = newNode;
        rear = newNode;
        return;
    }
    rear -> next = newNode;
    newNode -> prev = rear;
    rear = newNode;
}

// Function to delete the element
// from the front end
void Deque::deleteFront() {
    if(front == NULL) return;
    Node* node = front;
    front = front -> next;
    if(front == NULL) rear = NULL;
    else front -> prev = NULL;
    delete node;
    Size--;
}

// Function to delete the element
// from the rear end
void Deque::deleteRear() {
    if(rear == NULL) return;
    Node* node = rear;
    rear = rear -> prev;
    if(rear == NULL) front = NULL;
    else rear -> next = NULL;
    delete node;
    Size--;
}

// Driver program
int main(){
    Deque dq = Deque();
    dq.insertRear(6);
    dq.print();
    cout << "Size = " << dq.GetSize() << endl;
    dq.insertFront(64);
    dq.print();
    cout << "Size = " << dq.GetSize() << endl;
    dq.deleteRear();
    dq.print();
    cout << "Size = " << dq.GetSize() << endl;
    return 0;
}