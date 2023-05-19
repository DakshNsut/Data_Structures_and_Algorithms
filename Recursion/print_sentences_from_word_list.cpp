#include <iostream>
#include <algorithm>
using namespace std;

// to print all sentences that could be made from list of words

#define R 3
#define C 3

void printSentencesUtil(string words[R][C], int r, int c, string output){
    if(r == R-1){
        cout << output << endl;
        return;
    }
    r++;
    for(int j=0; j<C; j++){
        if (!words[r][j].empty())
            printSentencesUtil(words, r, j, output + " " + words[r][j]);
    }
}

void printSentences(string words[][C]){
    // Recuring for each word in first row
    for(int j=0; j<C; j++){
        if (!words[0][j].empty())
        printSentencesUtil(words,0,j,words[0][j]);
    }
}

// Time Complexity: O(C^R)
// Auxiliary space: O(R)

int main(){
    string words[R][C] = {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}};
    printSentences(words);
    return 0;
}