#include <iostream>
using namespace std;

// first circular tour problem
// The information consists of the distance of the (i+1)th petrol pump from the
// (i)th one (in arr[i][1]) and the amount of petrol stored in ith petrol pump
// (in arr[i][0]).

// The task is to find the index of the first starting point such that the truck
// can visit all the petrol pumps and come back to that starting point.

// ------------ Naive Approach --------------
int CircularTour(int petrol[], int dist[], int n){
    for(int i=0; i<n; i++){
        int UnitsInHand = petrol[i] - dist[i], j;
        for(j=i+1; j != i && UnitsInHand >= 0; j = (j+1) % n){
            UnitsInHand += petrol[j] - dist[j];
        }

        if(UnitsInHand >= 0 && j == i) return i+1;
    }
    return -1;
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

int main(){
    int p[] = {4,6,7,4};
    int d[] = {6,5,3,5};
    int n = 4;
    cout << CircularTour(p,d,n);
    return 0;
}

// -------------- Better Solution ----------------

struct petrolPump{
    public:
        int petrol;
        int distance;
};

int CircularTour(petrolPump p[],int n)
{
    int currPetrol = p[0].petrol - p[0].distance, end = 1, start = 0;
    // end is the index still not visited
    while(end!=start || currPetrol < 0){
        while(currPetrol < 0 && start != end){
            currPetrol -= (p[start].petrol - p[start].distance);
            start = (start+1) % n;
            if(start == 0) return -1;
        }

        // Moving forward from end to next index
        currPetrol += (p[end].petrol - p[end].distance);
        end = (end+1) % n;
    }

    return start;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    petrolPump p[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = 3;
    cout << CircularTour(p,n);
    return 0;
}

// --------------- Best Solution ----------------
int CircularTour(int petrol[], int dist[], int n){
    int UnitsInHand = 0;
    int prevUnitsInHand = 0;
    int start = 0;
    for(int i=0; i<n; i++){
        UnitsInHand += (petrol[i] - dist[i]);
        if(UnitsInHand < 0){
            prevUnitsInHand += UnitsInHand;
            UnitsInHand = 0;
            start = i+1;
        }
    }

    return (UnitsInHand + prevUnitsInHand) >= 0 ? start + 1 : -1;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int p[] = {4,6,7,4};
    int d[] = {6,5,3,5};
    int n = 4;
    cout << CircularTour(p,d,n);
    return 0;
}