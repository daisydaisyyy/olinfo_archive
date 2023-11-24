#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int R, C, N;
    cin >> R >> C >> N;

    vector<int> rr(N), cc(N);
    for (int i = 0; i < N; ++i)
        cin >> rr[i] >> cc[i];

    vector<vector<int>> chessboard(R, vector<int>(C, 0));
    vector<bool> used(R * C, false);
    vector<int> comp;
    // vector<vector<pair<int, int>>> connected;

    stack<int> st;

    // build chessboard
    for (int i = 0; i < N; ++i) {
        int r = rr[i] - 1;
        int c = cc[i] - 1;
        chessboard[r][c] = -1; // mark as occupied
    }

    auto isValid = [&](int x, int y) { // is valid position
        return x >= 0 && x < R && y >= 0 && y < C && chessboard[x][y] == -1;
    };


    // dfs to find connected pieces
    auto dfs = [&](int v) {
        st.push(v);

        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            if (!used[curr]) {
                used[curr] = true;
                comp.push_back(curr);

                int row = curr / C;
                int col = curr % C;

                // check row
                for (int j = 0; j < C; ++j) {
                    if (isValid(row, j)) {
                        st.push(row * C + j);
                    }
                }

                // check column
                for (int i = 0; i < R; ++i) {
                    if (isValid(i, col)) {
                        st.push(i * C + col);
                    }
                }

                // check diag
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        if (isValid(i, j) && abs(row - i) == abs(col - j)) {
                            st.push(i * C + j);
                        }
                    }
                }
            }
        }
    };

    auto find_comps = [&]() {
        int count = 0;
        fill(used.begin(), used.end(), false);
        for (int v = 0; v < R * C; ++v) {
            if (!used[v] && chessboard[v / C][v % C] == -1) { // start dfs on every not visited node
                comp.clear();
                dfs(v);

                // output
                // cout << "connected:";
                // for (int u : comp) {
                //     int row = u / C + 1;
                //     int col = u % C + 1;
                //     // cout << " (" << row << "," << col << ")";
                    
                //     if (count >= connected.size()) {
                //         connected.push_back({{row, col}});
                //     } else {
                //         connected[count].push_back({row, col});
                //     }
                // }
                // cout << endl;
                count++;
            }
        }
        return count;
    };

    int c = find_comps();

    // if more pieces are connected, each group has 2 possible configurations (all rooks or bishops)
    // else, a piece not connected can be either rook and bishop

    int sol = 1;
    sol = static_cast<int>(pow(2, c)) % MOD; // possible chessboard configurations (2**groups of connected pieces)

    cout << sol << endl;

    // debug print
    //    cout << "connected v: " << endl;
    // for(auto u : connected) {
    //     for(auto i : u) {
    //         cout << i.first << " " << i.second << endl;
    //     }
    //     cout << endl;
    // }

    return 0;
}

 
