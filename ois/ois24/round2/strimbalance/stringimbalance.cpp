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

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int Q;
        cin >> Q;
        
        vector<int> F(Q);
        vector<char> C(Q);
        vector<int> K(Q);
        for (int i = 0; i < Q; ++i)
            cin >> F[i] >> C[i] >> K[i];
        
        vector<int> A(Q);
        
        
        // INSERT YOUR CODE HERE
        
        
        for (int i = 0; i < Q; ++i)
            cout << A[i] << " ";
        cout << endl;
    }

    return 0;
}
