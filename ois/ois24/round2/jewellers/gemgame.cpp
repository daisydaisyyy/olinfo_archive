// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    
    vector<vector<int>> G(N, vector<int>(N));
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i)
            cin >> G[j][i];
    }
    
    
    // INSERT YOUR CODE HERE
    
    
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N - 1; ++i)
            cout << 42 << " ";
        cout << endl;
    }
    for (int j = 0; j < N - 1; ++j) {
        for (int i = 0; i < N; ++i)
            cout << 42 << " ";
        cout << endl;
    }

    return 0;
}
