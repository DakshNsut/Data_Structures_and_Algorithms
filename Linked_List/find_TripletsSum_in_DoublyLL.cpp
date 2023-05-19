#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

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

// -------------------------- HASHING -----------------------------
// can't handle case 1,1,1 to find sum = 3
void findTripletsSum(Node* hptr, int value){

    unordered_set<int> S;
    bool flag = false;

    for(Node* ptr1 = hptr; ptr1 != NULL; ptr1 = ptr1 -> next){
        for(Node* ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2 -> next){
            int sum = ptr1->data + ptr2->data;
            auto found = S.find(value-sum);
            if( found != S.end() && *found != ptr1->data && *found != ptr2->data ){
                cout << ptr1 -> data << " " << ptr2 -> data << " " << *found << endl;
                flag = true;
            }

            S.insert(ptr1->data);
        }
    }

    if(flag == false){
        cout << "Not found" << endl;
    }
}

// can handle case 1,1,1 to find sum = 3
void findTripletsSum(Node* hptr, int value){

    unordered_map<int, Node*> um;
    bool flag = false;

    for(Node* ptr1 = hptr; ptr1 != NULL; ptr1 = ptr1 -> next){
        for(Node* ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2 -> next){
            int sum = ptr1->data + ptr2->data;

            // The other two conditions means to check if the duplicates values are in different nodes /memory blocks
            if( um.find(value - sum) != um.end() && um[value - sum] != ptr1 && um[value - sum] != ptr2 ){
                cout << ptr1 -> data << " " << ptr2 -> data << " " << value-sum << endl;
                flag = true;
            }

            um[ptr1 -> data] = ptr1;
        }
    }

    if(flag == false){
        cout << "Not found" << endl;
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(1); n1 -> next = n2; n2 -> prev = n1;
    Node* n3 = new Node(1); n2 -> next = n3; n3 -> prev = n2;
    Node* n4 = new Node(6); n3 -> next = n4; n4 -> prev = n3;
    Node* n5 = new Node(7); n4 -> next = n5; n5 -> prev = n4;
    Node* head = n1;

    print(head);
    findTripletsSum(head, 3);

}

// ---------------------------- Two-pointer Technique ----------------------------
Node* getTail(Node* hptr){
    while(hptr!=NULL && hptr->next != NULL){
        hptr = hptr -> next;
    }

    return hptr;
}

void findTripletsSum(Node* hptr, int value){

    unordered_map<int, Node*> um;
    bool flag = false;

    for(Node* curr = hptr; curr != NULL; curr = curr -> next){
        Node* ptr1 = curr -> next;
        Node* ptr2 = getTail(hptr);
        int x = value - curr->data;

        while(ptr1!=NULL && ptr2!=NULL && ptr1!=ptr2 && ptr2->next!=ptr1){
            int Pairsum = ptr1->data + ptr2->data;
            if(Pairsum == x){
                cout << ptr1->data << " " << ptr2->data << " " << curr->data << endl;
                flag = true;
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
            else if(Pairsum < x){
                ptr1 = ptr1 -> next;
            }
            else{
                ptr2 = ptr2 -> next;
            }
        }
    }

    if(flag == false){
        cout << "No triplet found";
    }

}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(1); n1 -> next = n2; n2 -> prev = n1;
    Node* n3 = new Node(1); n2 -> next = n3; n3 -> prev = n2;
    Node* n4 = new Node(6); n3 -> next = n4; n4 -> prev = n3;
    Node* n5 = new Node(1); n4 -> next = n5; n5 -> prev = n4;
    Node* head = n1;

    print(head);
    findTripletsSum(head, 3);

}