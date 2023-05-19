#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    char data;
    int freq;
    Node* left, *right;
    Node(char ch, int fr){
        data = ch;
        freq = fr;
        left = right = NULL;
    }
};

struct cmp{
    bool operator()(const Node* nd1, const Node* nd2){
        return nd1->freq > nd2->freq;
    }
};

Node* buildHuffmanTree(char characters[], int frequency[], int n){
    priority_queue<Node*, vector<Node*>, cmp> pq; // min heap

    for(int i=0; i<n; i++){
        Node* node = new Node(characters[i], frequency[i]);
        pq.push(node);
    }

    while(pq.size() > 1){
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        Node* temp = new Node('$', a->freq + b->freq);
        temp->left = a;
        temp->right = b;
        pq.push(temp);
    }

    return pq.top();
}

void print(Node* root){
    if(!root) return;
    cout << root->data << ":" << root->freq << endl;
    print(root->left);
    print(root->right);
}

// Time Complexity: O(n*logn)
// Auxiliary space: O(n)

int main(){
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int n = 6;
    Node* root = buildHuffmanTree(characters, frequency, n);
    print(root);
    return 0;
}