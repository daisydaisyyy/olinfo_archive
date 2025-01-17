#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rank_c;

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank_c[a] < rank_c[b]) swap(a, b);
        parent[b] = a;
        if (rank_c[a] == rank_c[b]) rank_c[a]++;
    }
}

void solve() {
	ifstream cin("input0.txt");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }

        parent.resize(n + 1);
        rank_c.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);

        vector<int> company(m, 0);
        int k = 1;

        // First, build a spanning tree using Kruskal's algorithm
        for (int i = 0; i < m; ++i) {
            int u = edges[i].first, v = edges[i].second;
            if (find(u) != find(v)) {
                unite(u, v);
                company[i] = k;
            }
        }

        k++;  // We need at least two companies
        for (int i = 0; i < m; ++i) {
            if (company[i] == 0) {
                company[i] = (k > 2) ? (i % k) + 1 : 2;
            }
        }

        cout << k << '\n';
        for (int i = 0; i < m; ++i) {
            cout << company[i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

