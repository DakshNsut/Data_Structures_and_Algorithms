// ------------------------- METHOD-1 -------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// to find conflicting intervals

struct interval{
    int low;
    int high;
};

bool cmp(interval &a, interval &b){
    if(a.low < b.low) return true;
    return false;
}

void printConflict(interval appt[], int &n){
    sort(appt, appt+n, cmp);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(i != j){
                if(appt[i].low < appt[j].high && appt[i].high > appt[j].low){
                    cout << "[" << appt[i].low << "," << appt[i].high << "]";
                    cout << " <=> ";
                    cout << "[" << appt[j].low << "," << appt[j].high << "]" << endl;
                }
            }
        }
    }
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

int main(){
    interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt)/sizeof(appt[0]);
    printConflict(appt, n);

    return 0;
}

// ---------------------- METHOD-2 -------------------------
#include <iostream>
#include <vector>
using namespace std;

struct interval{
    int low;
    int high;
};

// interval tree implementation
struct ITNode{
    interval *i;
    ITNode* left, *right;
    int max; // the max of i->high of all nodes in the subtree with this node as root
    ITNode(interval *inter){
        i = inter; // no new node is created, the same node is taken as node in ITNode tree Aux space taken = O(H) for recursion call stack spce
        left = right = NULL;
        this->max = inter->high;
    }
};

ITNode* insert(ITNode* root, interval *inter){
    if(!root) return new ITNode(inter);

    if(root->i->low > inter->low)
        root->left = insert(root->left, inter);
    else
        root->right = insert(root->right, inter);

    if(root->max < inter->high) root->max = inter->high;
    return root;
}

bool doOverlap(interval *i1, interval &i2){
    if(i1->low < i2.high && i2.low < i1->high) return true;
    return false;
}

ITNode* overlapSearch(ITNode* root, interval &i){
    if(!root) return NULL;
    if(doOverlap(root->i, i)) return root;
    if(root->left && root->left->max >= i.low) return overlapSearch(root->left, i);
    else return overlapSearch(root->right, i);
}

void printConflict(interval appt[], int &n){
    ITNode *root = NULL;
    root = insert(root, &appt[0]);

    for(int i=1; i<n; i++){
        ITNode *res = overlapSearch(root, appt[i]);
        if(res){
            cout << "[" << appt[i].low << "," << appt[i].high << "]";
            cout << " <=> ";
            cout << "[" << res->i->low << "," << res->i->high << "]" << endl;
        }
        root = insert(root, &appt[i]);
    }
}

// Time Complexity: O(n^2); using balanced interval tree - O(n*logn)
// Auxiliary space: O(n); using balanced interval tree - O(logn)


int main(){
    interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt)/sizeof(appt[0]);
    printConflict(appt, n);

    return 0;
}