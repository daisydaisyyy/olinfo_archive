// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h> 
using namespace std;
int N;
// vector<string> U;
string S;
string f(const unordered_set<string>& U) {

   if (U.find(S) == U.end()) {
        // If the desired username is not taken
        return S;
    }

    // If the desired username is taken, try appending numbers
    for (int i = 1; ; ++i) {
        string tryUsername = S + to_string(i);
        if (U.find(tryUsername) == U.end()) {
            // If the modified username is not taken
            return tryUsername;
        }
    }
 
  
}


using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    unordered_set<string> U;

    cin >> S;
    
    int N;
    cin >> N;
    // U.resize(N);
    
    
    string a;
    for (int i = 0; i < N; ++i)
        cin >> a; 
        U.insert(a);


    
    string T = f(U);
    
    
    // INSERT YOUR CODE HERE
    
    
    cout << T << endl;

    return 0;
}
