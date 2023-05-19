#include <iostream>
#include <stack>
using namespace std;

// implement push,pop,getmiddle,deletemiddle all in O(1) time

// --------- Method -1 -------------
struct Node{
    Node *prev, *next;
    int data;
    Node(){}
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

struct Stack{
    Node *tail, *mid;
    int size;
    Stack(){
        tail = NULL;
        mid = NULL;
        size = 0;
    }

    void push(int x);
    int pop();
    int getMiddleElement();
    int deleteMiddleEle();
};

void Stack::push(int x){
    size++;
    Node* newNode = new Node(x);
    if(size == 1){
        mid = newNode;
        tail = newNode;
        return;
    }

    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;

    if(size % 2 == 0){
        mid = mid -> next;
    }
}

int Stack::deleteMiddleEle(){
    if(size == 0) return -1;
    size--;
    if(size == 0){
        Node* node = tail;
        int a = node -> data;
        mid = NULL;
        tail = NULL;
        delete node;
        return a;
    }

    Node* Prev = mid -> prev;
    Node* Next = mid -> next;
    if(Prev!=NULL) Prev -> next = Next;
    if(Next!=NULL) Next -> prev = Prev;
    Node* node = mid;
    int a = node -> data;
    if(mid == tail) tail = Prev;
    if(size % 2 == 0) mid = Next;
    else mid = Prev;

    delete node;
    return a;
}

int Stack::pop(){
    if(size == 0) return -1;
    size--;
    if(size == 0){
        Node* node = tail;
        int a = node -> data;
        tail = NULL;
        mid = NULL;
        delete node;
        return a;
    }

    if(size & 1){
        mid = mid -> prev;
    }

    Node* node = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    int a = node -> data;

    delete node;
    return a;
}

int Stack::getMiddleElement(){
    if(size == 0) return -1;
    return mid -> data;
}

int main(){
    Stack *st = new Stack;
    st->push(54);
    st->push(34);
    st->push(24);
    st->push(14);
    cout << st->getMiddleElement() << endl;
    cout << st->pop() << endl;
    cout << st->getMiddleElement() << endl;
    return 0;
}

// --------------- Method -2 -------------
struct Stack{
    stack<int> stk;
    deque<int> dq;

    void push(int x);
    int pop();
    int getMiddleElement();
    int deleteMiddleEle();
};

void Stack::push(int x){
    dq.push_back(x);
    if(stk.size() <= dq.size()){
        stk.push(dq.front());
        dq.pop_front();
    }
}

int Stack::getMiddleElement(){
    if(stk.empty()) return -1;
    return stk.top();
}

int Stack::pop(){
    if(stk.empty()) return -1;
    int a;
    if(!dq.empty()){
        a = dq.back();
        dq.pop_back();
    }
    else{
        a = stk.top();
        stk.pop();
    }
    int size = stk.size() + dq.size();

    if(size != 1 && size & 1){
        dq.push_front(stk.top());
        stk.pop();
    }
    return a;
}

int Stack::deleteMiddleEle(){
    if(stk.empty()) return -1;
    int a = stk.top();
    stk.pop();

    if(!dq.empty() && stk.size() == dq.size()){
        stk.push(dq.front());
        dq.pop_front();
    }
    return a;
}

int main(){
    // Stack st = Stack(); // Static Allocation of objects
    Stack *st = new Stack; // Dynamic Allocation of objects
    st->push(23);
    st->push(22);
    st->push(12);
    st->push(5);
    cout << st->pop() << endl;
    st->push(6);
    st->push(7);
    cout << st->deleteMiddleEle() << endl;
    cout << st->getMiddleElement() << endl;
    return 0;
}