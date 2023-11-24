#include <iostream>
#include <vector>
#include <fstream>
#define MAXP 60
using namespace std;


vector<pair<int, int>> precalculateMatches() {
    vector<pair<int, int>> matches;

    for (int i = 11; i <= 60; ++i) {
        for (int j = 0; j <= min(i - 2, 60); ++j) {
            if (i - j >= 2 && (j < 11 || j - i < 2)) {
                matches.emplace_back(i, j);
            }
        }
    }

    return matches;
}

bool simulateGame(int A, int B, vector<pair<int, int>>& sets) {
    vector<pair<int, int>> matches = precalculateMatches();

    for (const auto& match : matches) {
        int remainingA = A;
        int remainingB = B;
        sets.clear();

        while (remainingA > 0 || remainingB > 0) {
            if (remainingA >= match.first && remainingB >= match.second) {
                sets.emplace_back(match.first, match.second);
                remainingA -= match.first;
                remainingB -= match.second;
            } else {
                break;
            }
        }

        if (remainingA == 0 && remainingB == 0) {
            return true;
        }
    }

    return false;
}

void reconstructGame(int A, int B) {
    vector<pair<int, int>> sets;

    if (simulateGame(A, B, sets)) {
        for (const auto& set : sets) {
            cout << set.first << " " << set.second << endl;
        }
    } else if (simulateGame(B, A, sets)) {
        for (const auto& set : sets) {
            cout << set.second << " " << set.first << endl;
        }
    } else {
        cout << "-1 -1" << endl;
    }
}
int main() {
    int T;
    ifstream cin("input0.txt");
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int A, B;
        cin >> A >> B;
        reconstructGame(A, B);
    }

    return 0;
}