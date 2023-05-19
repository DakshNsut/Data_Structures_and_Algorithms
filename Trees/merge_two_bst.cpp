#include <iostream>
#include <vector>
using namespace std;

// to merge two BSTs

// ----------------- Using inorder traversal -------------------

void storeInorder(Node* root, vector<int> &res){
    if(!root) return;
    storeInorder(root->left, res);
    res.push_back(root->data);
    storeInorder(root->right, res);
}

void merge(vector<int> &in1, vector<int> &in2, vector<int> &res){
    int n = in1.size(), m = in2.size();
    int i=0, j=0;

    while(i<n && j<m){
        if(in1[i] < in2[j]) res.push_back(in1[i++]);
        else res.push_back(in2[j++]);
    }
    while(i<n) res.push_back(in1[i++]);
    while(j<m) res.push_back(in2[j++]);
}

Node* build(vector<int> &in, int s, int e){
    if(s > e) return NULL;
    int mid = (s+e)/2;
    int val = in[mid];

    Node* node = new Node(val);
    node->left = build(in, s,mid-1);
    node->right = build(in, mid+1,e);
    return node;
}

void printInorder(Node* node)
{
    if (!node) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

Node* Merge2BST(Node* root1, Node* root2){
    if(!root1) return root2;
    if(!root2) return root1;

    vector<int> in1, in2, in;
    storeInorder(root1, in1);
    storeInorder(root2, in2);

    merge(in1, in2, in);

    int n = in.size();
    return build(in, 0, n-1);
}

int main(){
    Node* root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node* root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node* mergedTree = Merge2BST(root1, root2);
    printInorder(mergedTree);
    return 0;
}

// Time Complexity: O(n+m)
// Auxiliary Space: O(h1+h2)

// ------------------------ Using DLL -------------------------
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int a){
        data = a;
        left = right = NULL;
    }
};

void printInorder(Node* node)
{
    if (!node) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void convertBSTtoDLL(Node* root, Node* &prev, Node* &head){
    if(!root) return;
    convertBSTtoDLL(root->left, prev, head);
    if(!prev){
        head = root;
    }
    else{
        root->left = prev; // left = previous link
        prev->right = root; // right = next link
    }
    prev = root;
    convertBSTtoDLL(root->right, prev, head);
}

void traverse(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

Node* mergeDLL(Node* h1, Node* h2){
    if(!h1) return h2;
    if(!h2) return h1;

    if(h1->data > h2->data){
        Node* temp = h1;
        h1 = h2;
        h2 = temp;
    }

    Node* ptr = h2;
    Node* curr = h1->right;
    Node* prev = h1;

    while(curr && ptr){
        if(ptr->data >= prev->data && ptr->data <= curr->data){
            Node* nextPtr = ptr->right;
            prev->right = ptr;
            ptr->left = prev;
            ptr->right = curr;
            curr->left = ptr;

            prev = ptr;
            ptr = nextPtr;
        }
        else{
            prev = curr;
            curr = curr->right;
        }
    }

    if(!curr) prev->right = ptr;

    return h1;
}

Node* buildBST(Node* &head, int n){
    if(n <= 0) return NULL;

    Node* left = buildBST(head, n/2); // root of left subtree is returned
    Node* root = new Node(head->data);
    root->left = left;
    head = head->right;
    root->right = buildBST(head, n-n/2-1);
    return root;
}

int countNodes(Node* h){
    int cnt = 0;
    while(h){
        h = h->right;
        cnt++;
    }
    return cnt;
}

Node* Merge2BST(Node* root1, Node* root2){

    // Convert two BSTs to DLL
    Node* prev = NULL, *head1, *head2, *head;
    convertBSTtoDLL(root1, prev, head1);
    prev = NULL;
    convertBSTtoDLL(root2, prev, head2);

    // Merge the two sorted DLL
    head = mergeDLL(head1, head2);

    // buildBST
    int n = countNodes(head);
    return buildBST(head, n);
}

// Time Complexity: O(n+m)
// Auxiliary Space: O(max(h1,h2))

int main(){
    Node* root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node* root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node* mergedTree = Merge2BST(root1, root2);
    printInorder(mergedTree);
    return 0;
}