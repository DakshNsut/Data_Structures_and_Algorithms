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

// -------------- Naive Approach ---------------
Node* merge(Node* head1, Node* head2){
        if(head1 == NULL){
            return head2;
        }
        
        if(head2 == NULL){
            return head1;
        }
        
        // left-edge case
        if(head1->data > head2->data){
            Node* temp = head1;
            head1 = head2;
            head2 = temp;
        }

        Node* prev = head1;
        Node* curr = prev -> next;
        Node* curr2 = head2;

        while(curr!=NULL && curr2!=NULL){
            if(curr2->data >= prev->data && curr2->data <= curr->data){
                Node* nextCurr2 = curr2 -> next;
                prev -> next = curr2;
                curr2 -> next = curr;
                
                prev = curr2;
                curr2 = nextCurr2;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
            
        }

        if(curr == NULL){
            prev -> next = curr2;
        }

        return head1;
    }

    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        Node* nextLLHead = arr[0]; // Head of next LL

        for(int i=1; i<K; i++){
            nextLLHead = merge(nextLLHead, arr[i]);
        }

        return nextLLHead;
    }

// Time Complexity: O(n*k)
// Auxiliary space: O(1)

// ------------------------------------ BETTER DIVIDE & CONQUER APPROACH --------------------------
    Node* merge(Node* head1, Node* head2){
        if(head1 == NULL){
            return head2;
        }

        if(head2 == NULL){
            return head1;
        }
        
        // left-edge case
        if(head1->data > head2->data){
            Node* temp = head1;
            head1 = head2;
            head2 = temp;
        }

        Node* prev = head1;
        Node* curr = prev -> next;
        Node* curr2 = head2;

        while(curr!=NULL && curr2!=NULL){
            if(curr2->data >= prev->data && curr2->data <= curr->data){
                Node* nextCurr2 = curr2 -> next;
                prev -> next = curr2;
                curr2 -> next = curr;
                
                prev = curr2;
                curr2 = nextCurr2;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
            
        }

        if(curr == NULL){
            prev -> next = curr2;
        }

        return head1;
    }

    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        int last = K-1;
        while(last != 0){
            int i=0, j =last;
            while(i<j){
                arr[i] = merge(arr[i], arr[j]);
                i++; j--;
            }
            
            last = j; // i >= j here
        }
        
        return arr[0];
    }

// Time Complexity: O(nlog(k))
// Auxiliary space: O(1)

int main(){
    // Number of linked lists
    int N = 3;
 
    // Number of elements in each list
    int K = 4;
 
    // An array of pointers storing the
    // head nodes of the linked lists
    Node* arr[N];
 
    // Creating k = 3 sorted lists
    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);
    print(arr[0]);
 
    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);
    print(arr[1]);
 
    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    print(arr[2]);
 
    // Merge the k sorted lists
    Node* head = mergeKLists(arr, N);
    print(head);

    return 0;
}