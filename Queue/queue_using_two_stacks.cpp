#include <iostream>
#include <stack>
using namespace std;

// implement a queue using two stacks

class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
};

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
}

// Time Complexity: O(1)
// Auxiliary space: O(n)

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()) return -1;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    int a = s2.top();
    s2.pop();
    
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    
    return a;
}

// Time Complexity: O(n)
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