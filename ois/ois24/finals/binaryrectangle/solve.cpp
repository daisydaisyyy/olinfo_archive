#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M; cin >> N >> M;
    vector<string> field(N);
    for (auto &line : field) cin >> line;
    
    int l = INT_MAX , r = -INT_MAX, t = INT_MAX, b = -INT_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(field[i][j] == '1') {
                t = min(t, i);
                b = max(b, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }
    
    if(l == INT_MAX) { 
        cout << "0" << endl;
        return;
    }
    
    for(int i = t; i <= b; i++) {
        for(int j = l; j <= r; j++) {
            if(field[i][j] == '0') { 
                cout << "0" << endl;
                return;
            }
        }
    }
    
    cout << "1" << endl;
}

int main() {
    int T; 
    cin >> T;
    while(T--) solve();
}
