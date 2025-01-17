// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N, K;
vector<int> C, T, Q;

int main() {
    cin >> N >> K;
    C.resize(N);
    for (int i=0; i<N; i++)
        cin >> C[i];

    T.resize(K);
    Q.resize(K);
    for (int i=0; i<K; i++)
        cin >> T[i] >> Q[i];
    long price = 0;
    vector<long> bin(N, 0);
     
    for (int i = 0; i < K; i++) {
        if (bin[T[i]] + Q[i] > C[T[i]]) {
            price += C[T[i]] - bin[T[i]];
            bin[T[i]] = Q[i];
        }
        else 
        {
            bin[T[i]] += Q[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (bin[i] != 0) {
            price += C[i] - bin[i];
        }
    }

    cout << price << endl;
    return 0;
}
