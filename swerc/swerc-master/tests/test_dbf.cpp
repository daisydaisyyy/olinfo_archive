#include <Strings/dbf.hpp>
#include <bits/stdc++.h>

using namespace std;

void test(const string& s, vector<u64> correct) {
    auto dbf = DBF(s);
    assert(dbf.back() == correct);
}

int main() {
    test("bananas", {4, 1, 5, 2, 6, 3, 7, 0});
    test("panamappa", {8, 3, 6, 2, 5, 4, 9, 7, 1, 0});
}

int main2() {
    size_t n;
    cin >> n;
    string s;
    cin >> s;
    assert(n == s.size());

    auto dbf = DBF(s);
    u64 lo = 0, hi = n;
    while(lo + 1 < hi) {
        u64 mid = (lo + hi) / 2;
        const u64 length = mid;
        unordered_set<pair<u64, u64>, hash_pair> substr;
        bool found = false;
        for(size_t i = 0; i < n - length + 1 && !found; i++) {
            u64 depth = log2(length);
            u64 align = 1 << depth;
            pair<u64, u64> couple = make_pair(dbf[depth][i], 
                dbf[depth][i + length - align]);
            if(substr.count(couple)) {
                found = true;
            } else {
                substr.insert(couple);
            }
        }
        if(found) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return 0;
}
