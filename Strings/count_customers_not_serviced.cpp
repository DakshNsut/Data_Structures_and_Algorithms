#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// count customers who were not given service

// Given an integer representing the capacity of a cyber cafe and a sequence
// representing entry/exit logs of customers, find the total number of customers
// who could not get any computer.
// The first occurrence in the given sequence indicates the arrival, and the
// second occurrence indicates the departure for a customer. A customer cannot be
// serviced when the cafe capacity is full (when all computers are allocated).

#define WORD_LENGTH 26

int checkCustomerNotInService(int *inCafe){
    for(int i=0; i<26; i++){
        if(inCafe[i] == 1){
            // First Come - First Serve Basis
            return i;
        }
    }
    return -1;
}

int runCustomerSimulation(int n, string customers){
    int countInService = 0, numbOfCustomers = customers.size(), countAns = 0;
    int inCafe[WORD_LENGTH] = {0};
    // 0 -> not in cafe
    // 1 -> in cafe but service not granted
    // 2 -> in cafe and service granted

    for(int i=0; i<numbOfCustomers; i++){
        // Entry of a customer
        if(inCafe[customers[i]-'A'] == 0){
            // The customer is visited
            inCafe[customers[i]-'A'] = 1;
            // Checking if it can be assigned a computer
            if(countInService < n){
                inCafe[customers[i]-'A'] = 2;
                countInService++;
            }
        }
        // Exit of a customer
        else{
            // The service is taken from the customer, if it was assigned
            if(inCafe[customers[i]-'A'] == 2){
                // The customer is not in cafe
                countInService--;
                inCafe[customers[i]-'A'] = 0;
                // check for customers who are not in service and give them service
                int indCust = checkCustomerNotInService(inCafe);
                if(indCust != -1){
                    inCafe[indCust] = 2;
                }
            }
            else{ // The customer departed but service wasn't given
                inCafe[customers[i]-'A'] = 0;
                countAns++;
            }
        }
    }
    return countAns;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    cout << runCustomerSimulation (2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation (3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation (3, "GACCBDBDAGEE") << endl;
    cout << runCustomerSimulation (3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation (1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}