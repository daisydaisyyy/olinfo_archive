#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 61;
const int MAX_B = 61;
const int MAX_ROUNDS = 3;

int dp[MAX_A][MAX_B][MAX_ROUNDS + 1][MAX_ROUNDS + 1];
vector<pair<int, int>> result;

int T;

bool solve(int pts_a, int pts_b, int rounds_a, int rounds_b) {
    // Check if we are in an invalid state
    if (pts_a < 0 || pts_b < 0 || rounds_a > MAX_ROUNDS || rounds_b > MAX_ROUNDS) return false; 

    // If both players have exhausted their rounds
    if (rounds_a == MAX_ROUNDS && rounds_b == MAX_ROUNDS) {
        return (pts_a == 0 && pts_b == 0); // Check if points are exactly zero
    }

    // If we reached a state we've already calculated
    if (dp[pts_a][pts_b][rounds_a][rounds_b] != -1) return dp[pts_a][pts_b][rounds_a][rounds_b];

    // Try for player A winning
    for (int x = 0; x <= 10; ++x) {
        if (solve(pts_a - 11, pts_b - x, rounds_a + 1, rounds_b)) {
            result.push_back({11, x}); 
            dp[pts_a][pts_b][rounds_a][rounds_b] = 1; // Found a valid state
            return true;
        }
    }

    // Try for player B winning
    for (int x = 0; x <= 10; ++x) {
        if (solve(pts_a - x, pts_b - 11, rounds_a, rounds_b + 1)) {
            result.push_back({x, 11}); 
            dp[pts_a][pts_b][rounds_a][rounds_b] = 1; // Found a valid state
            return true;
        }
    }

    // Mark as impossible
    dp[pts_a][pts_b][rounds_a][rounds_b] = 0; 
    return false;
}

int main() {
    // Uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int A, B;
        cin >> A >> B;

        memset(dp, -1, sizeof dp); // Set to -1 to indicate uncalculated states
        result.clear();

        // Start solving from the initial points and rounds
        if (solve(A, B, 0, 0)) {
            for (auto &r : result) {
                cout << r.first << " " << r.second << endl;
            }
        } else {
            cout << "-1 -1" << endl; // Output if no solution is found
        }
    }

    return 0;
}

