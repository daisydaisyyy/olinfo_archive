#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set> 
using namespace std;

string f(const unordered_set<string>& U, const string& S) {
    if (U.find(S) == U.end()) {
        return S;
    }

    for (int i = 1; ; ++i) {
        string tryUsername = S + to_string(i);
        if (U.find(tryUsername) == U.end()) {
            return tryUsername;
        }
    }
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    string S;
    cin >> S;
    
    int N;
    cin >> N;
    
    unordered_set<string> U;
    string a;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        U.insert(a);
    }
    
    string T = f(U, S);
    cout << T << endl;

    return 0;
}
