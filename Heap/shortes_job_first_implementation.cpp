#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// to implement shortest job first algorithm

struct process{
    int ID; // Process ID
    int AT; // arrival time
    int BT; // burst time
};

bool cmp(process &p1, process &p2){
    if(p1.AT == p2.AT){
        if(p1.BT == p2.BT){
            return p1.ID < p2.ID;
        }
        else return p1.BT < p2.BT;
    }
    else return p1.AT < p2.AT;
}

void SJF(vector<process> v){
    int n = v.size();
    // sorting the processes acc. to AT-BT-ID
    sort(v.begin(), v.end(), cmp);

    // create a min-heap of BT-AT-ID
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({v[0].BT, v[0].AT, v[0].ID});
    int i = 1; // the next process to be taken, due to least arrival time
    int curr_time = 0;

    vector<int> ans; // contains id of processes according to the order in which they have to be executed
    while(!pq.empty()){
        int id = pq.top()[2];
        int bt = pq.top()[0]; pq.pop();
        ans.push_back(id);
        curr_time = curr_time + bt; // this process will execute completely, no preemption

        // Processes which have arrived will now be taken for comparison of BT
        while(i < n && v[i].AT <= curr_time) pq.push({v[i].BT, v[i].AT, v[i++].ID});
    }

    for(int i : ans) cout << i << " ";
    cout << endl;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

int main(){
    int n;
    cin >> n; // Enter number of processes

    // Input all the processes
    vector<process> processes;
    for(int i=0; i<n; i++){
        process temp;
        cin >> temp.ID;
        cin >> temp.AT;
        cin >> temp.BT;

        processes.push_back(temp);
    }

    SJF(processes);
    return 0;
}