// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    long long K;
    cin >> N >> K;

    vector<int> u(N - 1), v(N - 1), w(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    // insert your code here

    cout << 42 << endl;  // print the result
    return 0;
}
