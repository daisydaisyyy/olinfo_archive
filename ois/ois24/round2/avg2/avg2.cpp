#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int N;
    long long K;
    ifstream cin("input1.txt");
    cin >> N >> K;

    vector<long long> P(N);
    long long pos = 0, neg = 0;

    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        long long diff = P[i] - K;
        
        if (diff > 0) {
            pos += diff;
        } else {
            neg += abs(diff);
        }
    }

    long long max_adj = max(pos, neg);
    long long C = (max_adj + N - 1) / N;  // Ceiling division

    cout << C << endl;
    return 0;
}
