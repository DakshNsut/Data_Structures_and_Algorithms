#include <iostream>
#include <stack>
using namespace std;

// implement k queues in one array

struct Kqueue{
    int *front,*rear,*next,freeSlot; 
    // points to front index of ith queue,  // points to rear index of ith queue, // index of next freeslot and if element is present then index of previous element of qnTh queue, // points to index of freeSlot in the array
    int *arr;

    Kqueue(int n, int qn){
        front = new int[qn];
        rear = new int[qn];
        next = new int[n];
        arr = new int[n];
        freeSlot = 0;

        for(int i=0; i<qn; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i=0; i<n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    void enqueue(int x, int qn){
        int i = freeSlot;
        if(i == -1){cout << "Couldn't add " << x << " to queue " << qn << endl; return;}
        freeSlot = next[i];
        next[i] = rear[qn-1];
        rear[qn-1] = i;
        if(front[qn-1] == -1) front[qn-1] = i;
        arr[i] = x;
        cout << "Added " << x << " to queue " << qn << endl;
    }
	
	// Time Complexity: O(n)
	// Auxiliary space: O(1)

    int dequeue(int qn){
        if(front[qn-1] == -1){ cout << "Queue Underflow"; return -1;}
        int i = front[qn-1];
        front[qn-1] = next[i];
        next[i] = freeSlot;
        freeSlot = i;
        return arr[i];
    }

	// Time Complexity: O(n)
	// Auxiliary space: O(1)
};

int main(){
    // Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    Kqueue ks(n, k);
 
    // Let us put some items in queue number 3
    ks.enqueue(15, 3);
    ks.enqueue(45, 3);
 
    // Let us put some items in queue number 2
    ks.enqueue(17, 2);
    ks.enqueue(49, 2);
    ks.enqueue(39, 2);
 
    // Let us put some items in queue number 1
    ks.enqueue(11, 1);
    ks.enqueue(9, 1);
    ks.enqueue(7, 1);
 
    cout << "Dequeued element from queue 3 is " << ks.dequeue(3) << endl;
    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
 
    return 0;
}