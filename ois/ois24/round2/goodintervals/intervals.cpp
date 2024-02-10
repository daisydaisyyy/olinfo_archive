#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> preprocess(const vector<int>& A, int N) {
    vector<vector<int>> freq(N, vector<int>(N + 1, 0));

    for (int i = 0; i < N; ++i) {
        for (int d = 1; d <= i + 1; ++d) {
            if (A[i] % d == 0) {
                freq[i][d]++;
            }
            if (i > 0) {
                freq[i][d] += freq[i - 1][d];
            }
        }
    }

    return freq;
}

int countGoodSubintervals(const vector<vector<int>>& freq, int l, int r) {
    int count = 0;

    for (int len = 1; len <= r - l + 1; ++len) {
        bool isGood = true;
        for (int i = 0; i < len; ++i) {
            if (freq[l + len - 1][i + 1] - (l > 0 ? freq[l - 1][i + 1] : 0) != i + 1) {
                isGood = false;
                break;
            }
        }
        if (isGood) {
            count++;
        }
    }

    return count;
}

int main() {
    // Uncomment for file input/output
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int& a : A) cin >> a;

        auto freq = preprocess(A, N);

        int Q;
        cin >> Q;
        while (Q--) {
            int l, r;
            cin >> l >> r;
            --l; --r; // Converting to 0-based indexing
            cout << countGoodSubintervals(freq, l, r) << endl;
        }
    }

    return 0;
}
