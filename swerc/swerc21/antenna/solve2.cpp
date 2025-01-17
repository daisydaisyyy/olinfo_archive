#include <bits/stdc++.h>
using namespace std;

void solve() {
	ifstream cin("input0.txt");
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b; // Read number of antennas and indices a, b
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i]; // Read the power of each antenna
        }
        
        // Convert 1-based indexing to 0-based
        a--; b--;
        
        vector<int> dist(n, -1); // Distance array, -1 means unvisited
        queue<int> q;
        
        // Start BFS from node `a`
        q.push(a);
        dist[a] = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            int range = p[curr];
            
            // Explore all reachable antennas within range
            for (int i = curr + 1; i <= min(n - 1, curr + range); ++i) {
                if (dist[i] == -1) { // If not visited
                    dist[i] = dist[curr] + 1;
                    q.push(i);
                }
            }
            
            for (int i = curr - 1; i >= max(0, curr - range); --i) {
                if (dist[i] == -1) { // If not visited
                    dist[i] = dist[curr] + 1;
                    q.push(i);
                }
            }
        }
        
        // Output the result for this test case
        cout << dist[b] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

