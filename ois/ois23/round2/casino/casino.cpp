// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<string> R(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    // insert your code here

    cout << 42 << endl; // print the result
    
    return 0;
}
