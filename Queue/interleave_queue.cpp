#include <iostream>
#include <queue>
using namespace std;

// rearrange the elements by interleaving the first half of the queue with the second half of the queue.  

// ------------ METHOD:1 ---------------
void InterleaveQueue(queue<int> &q){
    int n = q.size();
    int *temp = new int[n];

    // Copying queue elements to array temp
    int i = 0;
    while(!q.empty()){
        temp[i] = q.front();
        q.pop();
        i++;
    }

    // Interleaving temp array contents to queue
    int j = n/2;
    i = 0;
    while(q.size() < n){
        q.push(temp[i++]);
        if(q.size() < n) q.push(temp[j++]);
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// ----------- METHOD:2 ----------------
void InterleaveQueue(queue<int> &q){
    queue<int> temp;
    int n = q.size();

    for(int i=0; i<n/2; i++){
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty()){
        q.push(temp.front());
        q.push(q.front());
        temp.pop();
        q.pop();
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

void print(queue<int> &q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    InterleaveQueue(q);
    print(q);
}