#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll p = 31;

int main() {
    // Uncomment the following lines if you want to read/write from files
    ifstream cin("1.in");

    string a; 
    cin >> a;
    cout << "S: " << a << endl;
    
    int N;
    cin >> N;
    vector<string> S(N);
    for (auto &s : S) cin >> s;

    int M = a.size(); // Length of string 'a'
    
    // Precompute hashes and powers
    vector<ll> hashes(M + 1, 0); // Use M + 1 since we hash the entire string
    vector<ll> pows(M + 1, 1); // Compute powers up to M
    for (int i = 0; i < M; i++) {
        hashes[i + 1] = hashes[i] * p + (a[i] - 'a' + 1); // Calc partial hash
        pows[i + 1] = p * pows[i]; // Increment exp
    }

    auto compute_hash = [&](const string &s) {
        ll hash_value = 0;
        for (char c : s) {
            hash_value = hash_value * p + (c - 'a' + 1);
        }
        return hash_value;
    };

    auto range_hash = [&](int l, int r) -> ll { // Specify return type as ll
        if (l < 0 || r > M || l >= r) return -1; // Bounds checking
        return hashes[r] - hashes[l] * pows[r - l];
    };

    cout << N << endl;
    int acceptable_count = 0;
    for (const auto &s : S) {
        cout << "Checking: " << s << endl;
        ll s_hash = compute_hash(s);
        cout << "Hash: " << s_hash << endl;
        cout << "Size: " << s.size() << endl;

        // Ensure we don't go out of bounds
        if (s.size() > M) {
            cout << "String is too long for the source string." << endl;
            continue;
        }

        for (int i = 0; i <= M - s.size(); ++i) {
            cout << "Checking range: [" << i << ", " << i + s.size() << ")" << endl;
            ll sub_hash = range_hash(i, i + s.size());
            cout << "Subhash: " << sub_hash << endl;

            if (sub_hash == s_hash) {
                cout << "Match at: " << i << endl;
                acceptable_count++;
                break; // Stop checking this string on first match
            }
        }
    }

    cout << "Number of acceptable strings found: " << acceptable_count << endl;

    return 0;
}

