#include <bits/stdc++.h>

using namespace std;

bool cyk(const vector<pair<char, string>>& G, const char S, const string& w) {
    auto n = w.size();
    auto table = vector<vector<unordered_set<char>>>(n);
    for(auto &r: table) {
        r = vector<unordered_set<char>>(n+1, unordered_set<char>());
    }

    for(int i = 0; i < n; ++i) {
        for(auto &p: G) {
            auto &a = p.second;
            if(a.size() == 1 && a[0] == w[i])
                table[i][i+1].insert(p.first);
        }
    }

    for(int l = 2; l <= n; ++l) {
        for(int i = 0; i < n-l+1; ++i) {
            auto j = i + l;
            for(int k = i+1; k < j; ++k) {
                for(auto &p: G) {
                    auto &a = p.second;
                    if(a.size() != 2) continue;
                    if(table[i][k].count(a[0]) && table[k][j].count(a[1]))
                        table[i][j].insert(p.first);
                }
            }
        }
    }

    return (table[0][n].count(S));
}

