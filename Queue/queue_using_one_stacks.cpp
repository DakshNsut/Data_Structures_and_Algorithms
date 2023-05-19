#include <iostream>
#include <stack>
using namespace std;

// implement a queue using one stack

class StackQueue{
private:   
    stack<int> s;
public:
    void push(int);
    int pop();
};

// Function to push an element in queue by using 2 stacks.
void StackQueue::push(int x) {
    s.push(x);
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue::pop() {
    if(s.empty()) return -1;
        
    int x = s.top();
    s.pop();
    if(s.empty()) return x;
        
    int item = pop();
    s.push(x); // Backtracking and pushing 'x' back that was removed
    return item;
}

// Time Complexity: O(1)
// Auxiliary space: O(n)

int main(){
    StackQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
  
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    return 0;
}