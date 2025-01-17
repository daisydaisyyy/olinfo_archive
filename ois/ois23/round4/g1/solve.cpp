// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, Q;
    cin >> N >> Q;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        // insert your code here

        cout << 42 << endl;  // print the result
    }
    return 0;
}
