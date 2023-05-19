#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// LRU cache implementation

class LRUCache{
    private:
    int n;
    list<pair<int,int>> dq;
    // mapping of key : address of the node of that key
    unordered_map<int,list<pair<int,int>>::iterator> um;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap){
        n = cap;
    }

    // Function to return value corresponding to the key.
    int GET(int key, int value){
        if(um.find(key) != um.end()){
            int v = um[key] -> second;
            dq.erase(um[key]);
            // Add it to head being the most frequent item
            dq.push_front(make_pair(key,v));
            um[key] = dq.begin();
            return um[key]->second;
        }
        cout << "Not Found, Page Fault." << endl;
        dq.pop_back();
        SET(key, value);
        cout << "Replaced by least recently used and added the page not in cache";
        return -1;
    }

    // Function for storing key-value pair.
    void SET(int key, int value){
        // if not present
        if(um.find(key) == um.end()){
            if(dq.size() == n){
                auto it = dq.back();
                dq.pop_back();
                um.erase(it.first);
            }
        }
        else{
            // if present
            // delete it
            dq.erase(um[key]);
        }

        // Add it to head being the most frequent item
        dq.push_front(make_pair(key,value));
        um[key] = dq.begin();
    }

	// Time Complexity: O(1)
	// Auxiliary space: O(n)
};

int main(){
    LRUCache cache(8);
 
    cache.SET(1,2); // key,value
    cache.SET(2,3);
    cache.SET(1,5);
    cache.SET(4,5);
    cache.SET(6,7);
    cout << cache.GET(4, 5) << endl; // key, returns value
    cache.SET(1,2);
    cout << cache.GET(3, 8) << endl;
}