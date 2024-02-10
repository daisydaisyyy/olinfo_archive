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

    int N, K;
    cin >> N >> K;

    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];

    int M;
    cin >> M;

    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i)
        cin >> A[i] >> B[i];

    int P = 0;


    // INSERT YOUR CODE HERE


    cout << P << endl;

    return 0;
}
