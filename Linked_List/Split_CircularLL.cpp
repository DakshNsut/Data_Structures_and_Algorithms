#include <iostream>
#include <vector>
#include <queue>
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

// ---------- METHOD 1 ------------
vector<Node*> HalfLL(Node* hptr){

    vector<Node*> ans;
    // Finding length of LL
    Node* temp = hptr;
    int len = 0;
    do{
        temp = temp -> next;
        len++;
    }while(temp != hptr);

    Node* ptr = hptr;
    if(len % 2 == 0){
        // Creating first half
        int i = 1;
        while( i < (len/2) ){
            ptr = ptr -> next;
            i++;
        }
        // it is at the (len/2)th node
        Node* nextHead = ptr -> next;
        // Node* head1 = head;
        ptr -> next = hptr;

        ans.push_back(hptr);

        i++;
        // Creating second half
        ptr = nextHead;
        while(i < len){
            ptr = ptr -> next;
            i++;
        }
        cout << endl;
        // Node* head2 = nextHead;
        ptr -> next =  nextHead;
        ans.push_back(nextHead);
    }

    else{
        // Creating first half
        int i = 1;
        while( i < (len/2)+1 ){
            ptr = ptr -> next;
            i++;
        }
        // it is at the (len/2)th node
        Node* nextHead = ptr -> next;
        // Node* head1 = head;
        ptr -> next = hptr;

        ans.push_back(hptr);

        i++;
        // Creating second half
        ptr = nextHead;
        while(i < len){
            ptr = ptr -> next;
            i++;
        }

        // Node* head2 = nextHead;
        ptr -> next =  nextHead;
        ans.push_back(nextHead);

    }

    return ans;
}

// ----------- METHOD 2 --------------
vector<Node*> HalfLL(Node* hptr){
    vector<Node*> ans;
    if(hptr == NULL){
        return {NULL, NULL};
    }

    Node* slow = hptr;
    Node* fast = hptr;

    while(fast->next != hptr && fast->next->next != hptr){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // -------------------- Creating first half --------------------
    Node* nextHead;
    nextHead = slow -> next;
    slow->next = hptr;

    ans.push_back(hptr);

    // -------------------- Creating second half --------------------

    // for one element LL
    if(hptr == hptr -> next){
        ans.push_back(NULL);
        return ans;
    }

    if(fast->next->next == hptr){
        fast->next->next = nextHead;
    }

    else if (fast->next = hptr){
        fast->next = nextHead;
    }

    ans.push_back(nextHead);

    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

void InsertAtHead(Node* &hptr, Node* &tptr, int item){
    Node* newNode = new Node(item);

    // Empty Linked List // Special Case
    if(hptr == NULL){
        hptr = newNode;
        tptr = newNode;
        return;
    }

    newNode -> next  = hptr;
    hptr = newNode;
}

void print(Node* hptr){
    if(hptr == NULL){
        return;
    }

    Node* curr = hptr;
    cout << curr->data << " ";
    curr = curr->next;

    while(curr != NULL && curr != hptr){
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 33);
    InsertAtHead(head, tail, 22);
    InsertAtHead(head, tail, 11);
    InsertAtHead(head, tail, 55);
    InsertAtHead(head, tail, 66);
    InsertAtHead(head, tail, 88);
    tail->next = head;
    print(head);

    vector<Node*> res = HalfLL(head);
    print(res[0]);
    print(res[1]);
    return 0;
}