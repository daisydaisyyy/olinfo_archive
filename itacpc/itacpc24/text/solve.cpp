#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll p = 31;

int main() {
    // Uncomment the following lines if you want to read/write from files
    //ifstream cin("2.in");
    // ofstream cout("output.txt");

    string a; 
    cin >> a;
    int N; 
    cin >> N;
    vector<string> S(N);
    for (auto &s : S) cin >> s;

    size_t M = a.size(); // Use size_t for string sizes

    // Precompute hashes and powers
    vector<ll> hashes(M + 1, 0);
    vector<ll> pows(M + 1, 1); // Compute powers up to M
    for (size_t i = 0; i < M; i++) {
        hashes[i + 1] = hashes[i] * p + (a[i] - 'a' + 1); // Calculate partial hash
        pows[i + 1] = p * pows[i]; // Increment exp
    }

    auto compute_hash = [&](const string &s) {
        ll hash_value = 0;
        for (char c : s) {
            hash_value = hash_value * p + (c - 'a' + 1);
        }
        return hash_value;
    };

    auto range_hash = [&](int l, int r) -> ll { 
        if (l < 0 || r > static_cast<int>(M) || l >= r) return -1; // Bounds checking
        return hashes[r] - hashes[l] * pows[r - l]; 
    };

    vector<pair<int, int>> found;
	vector<bool> covered(M, false);
    for (const auto &s : S) {
        ll s_hash = compute_hash(s);
        
        if (s.size() > M) continue;
        for (size_t i = 0; i <= M - s.size(); ++i) {
            ll sub_hash = range_hash(i, i + s.size());
            if (sub_hash == s_hash) {
				fill(covered.begin() + i, covered.begin() + i + s.size(), true);
                //found.push_back({static_cast<int>(i), static_cast<int>(i + s.size())});
            }
        }
    }
	 int uncovered_count = 0;
    for (bool is_covered : covered) {
        if (!is_covered) uncovered_count++;
    }
	cout << uncovered_count << endl;
    return 0;
}

