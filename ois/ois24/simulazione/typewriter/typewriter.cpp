/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
// constraints
#define MAXL 100010
using namespace std;

vector<pair<int, char>> runlength(string s) {
    vector<pair<int, char>> res;

    char block = s[0];
    int cnt = 1;

    for (int i=1; i<s.length(); i++) {
        if (s[i] != block) {
            res.push_back({cnt, block});

            // new block
            block = s[i];
            cnt = 1;
        } else {
            // same block
            cnt += 1;
        }
    }

    res.push_back({cnt, block});
    return res;
}

int main() {
    const int K = 3;
    string S[K];
    vector<pair<int, char>> v[K];

    for (int i=0; i<K; i++) {
        cin >> S[i];
        v[i] = runlength(S[i]);
    }

    for (int i=1; i<K; i++) {
        if (v[i].size() != v[0].size()) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }

        for (int j=0; j<v[0].size(); j++) {
            if (v[i][j].second != v[0][j].second) {
                cout << "IMPOSSIBLE" << endl;
                exit(0);
            }
        }
    }

    vector<int> rep(v[0].size());
    for (int j=0; j<v[0].size(); j++) {
        vector<int> temp(K);

        for (int i=0; i<K; i++) {
            temp[i] = v[i][j].first;
        }

        sort(temp.begin(), temp.end());

        rep[j] = temp[K / 2];
    }

    for (int j=0; j<v[0].size(); j++) {
        while (rep[j]--) {
            cout << v[0][j].second;
        }
    }

    cout << endl;
}