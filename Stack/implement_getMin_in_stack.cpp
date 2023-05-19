#include <iostream>
#include <stack>
#include <climits>
using namespace std;

// implement GetMin() function in a stack in O(1) time

// ----------------------- O(n) space -----------------------
class Solution{
    stack<int> s;
    stack<int> minst;

    public:
        int getMin(){
            if(minst.empty()) return -1;
            return minst.top();
        }

        int pop(){
            if(s.empty()) return -1;
            minst.pop();
            int a = s.top();
            s.pop();
            return a;
        }

        void push(int x){
            s.push(x);
            if(minst.empty()){
                minst.push(x);
                return;
            }
            int minEle = min(minst.top(), x);
            minst.push(minEle);
        }
};

// ----------------------- O(1) space for +ve elements only -----------------------
class Solution{
    stack<int> s;
    int mine;

    public:
        int getMin(){
            if(s.empty()) return -1;
            return mine;
        }

        int pop(){
            if(s.empty()) return -1;
            int x = s.top();
            s.pop();
            if(x < 0){
                int ret = mine;
                mine = mine - x;
                return ret;
            }
            else{
                return x;
            }
        }

        void push(int x){
            if(s.empty()){
                mine = x;
                s.push(x);
            }
            else if(x < mine){
                s.push(x - mine);
                mine = x;
            }
            else{
                s.push(x);
            }
        }
};

// ---------------- O(1) space for -ve also -----------------
class Solution{
    stack<int> s;
    int mine;

    public:
        int getMin(){
            if(s.empty()) return -1;
            return mine;
        }

        int pop(){
            if(s.empty()) return -1;
            int x = s.top();
            s.pop();
            if(x < mine){
                int ret = mine;
                mine = 2*mine - x;
                return ret;
            }
            else{
                return x;
            }
        }

        void push(int x){
            if(s.empty()){
                mine = x;
                s.push(x);
            }
            else if(x < mine){
                s.push(2*x - mine);
                mine = x;
            }
            else{
                s.push(x);
            }
        }
};

int main(){
    Solution obj;
    obj.push(3);
    cout << "Pushed: 3" << endl;
    obj.push(5);
    cout << "Pushed: 5" << endl;
    cout << "Minimum element is: " << obj.getMin() << endl;
    obj.push(2);
    cout << "Pushed: 2" << endl;
    obj.push(1);
    cout << "Pushed: 1" << endl;
    cout << "Minimum element is: " << obj.getMin() << endl;
    cout << "Popped element is: " << obj.pop() << endl;
    cout << "Minimum element is: " << obj.getMin() << endl;
    cout << "Popped element is: " << obj.pop() << endl;
    return 0;
}