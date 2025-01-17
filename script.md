dp 
```cpp 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, K;
vector<int> T;
ll dp[MAXN][MAXN][3]; // cell, turns, doubles
ll solve(int cell, int doubles, int turn) {
	if(turn == K) return 0; // base case
	if (doubles == 3) return solve(cell, 0, turn + 1); // three double throws, go to next turn

	if(dp[cell][turn][doubles] != -1) return dp[cell][turn][doubles]; // already memorized

	ll max_score = LONG_LONG_MIN; 
	for(int first_d = 1; first_d <= 6; ++first_d) { // first and second dice
		for(int second_d = 1; second_d <= 6; ++second_d) {
			int next_cell = (first_d + second_d + cell) % N; // calc next cell position
			if(first_d == second_d) max_score = max(max_score, solve(next_cell, doubles+1, turn) + T[next_cell]); // double throw, continue the turn
			else max_score = max(max_score, solve(next_cell, 3, turn) + T[next_cell]); // not doubles, go to next turn 	
		}
	}
	dp[cell][turn][doubles] = max_score; 
	return dp[cell][turn][doubles];

}
```

string hashing (example checks if f is palindrome)
```cpp 
	const ll p = 31;
	// precompute hashes and pows
	vector<ll> hashes(N+1); 
	vector<ll> pows(N+1,1);
	for(int i = 0; i < N; i++) {
		hashes[i + 1] = hashes[i] * p + S[i] - 'a'; // calc partial hash
		pows[i + 1] = p * pows[i]; // increment exp
	}

	vector<vector<int>> divs(N+1);
	
    for(int i = 2; i <= N; i++) {
		if(!divs[i].empty()) continue;
		for(int j = i; j <= N; j += i) 
			divs[j].push_back(j / i);
	}
    
	auto range_hash = [&](int l, int r) {
		return hashes[r] - (hashes[l] * pows[r - l]);
	};

	int Q;
	cin >> Q;
	while(Q--) {
		int l, r; 
		cin >> l >> r;
		r++;

		bool pal = false; 
		for(auto div: divs[r-l]) {
			if(div == r - l) continue; 
			ll h1 = range_hash(l, r - div); 
			ll h2 = range_hash(l + div, r); 

			if(h1 == h2) {
				pal = true; 
				break;
			}
		}
		if(pal) cout << "YES" << endl; 
		else cout << "NO" << endl;
	}
```

dfs (sparse graph)
```cpp
// Modified bfs to store the parent of nodes along with the
// distance from source node
void bfs(vector<vector<int> >& graph, int S,
         vector<int>& par, vector<int>& dist)
{
    // queue to store the nodes in the order they are
    // visited
    queue<int> q;
    // Mark the distance of the source node as 0
    dist[S] = 0;
    // Push the source node to the queue
    q.push(S);

    // Iterate till the queue is not empty
    while (!q.empty()) {
        // Pop the node at the front of the queue
        int node = q.front();
        q.pop();

        // Explore all the neighbours of the current node
        for (int neighbour : graph[node]) {
            // Check if the neighbouring node is not visited
            if (dist[neighbour] == 1e9) {
                // Mark the current node as the parent of
                // the neighbouring node
                par[neighbour] = node;
                // Mark the distance of the neighbouring
                // node as distance of the current node + 1
                dist[neighbour] = dist[node] + 1;
                // Insert the neighbouring node to the queue
                q.push(neighbour);
            }
        }
    }
}

```

bfs 
```cpp
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}
```

dijkstra
```cpp 
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);
	vector<bool> u(n, false);
	
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v])) v = j;
		}
		
		if (d[v] == INF) break;
		u[v] = true;
		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;
			
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}
```

max_queue example 
```cpp
// find min/max element/path using priority queue, can be also used to find shortest path with best conditions (dijkstra) on a sparse graph
int N, M, C_0, P[MAXN], i;
vector<pair<int, int>> adj[MAXN];

int main()
{
	cin >> N >> M >> C_0;
	for (i = 0; i < N; i++)
		cin >> P[i];

	for (i = 0; i < M; i++)
	{ // build adj
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	adj[N - 1].push_back({N, 0});

	vector<vector<int>> dst(N + 1, vector<int>(MAXC, 2e9));
	vector<vector<bool>> visited(N + 1, vector<bool>(MAXC, false));
	priority_queue<tuple<int, int, int>> q;
	q.push({0, 0, C_0});
	dst[0][C_0] = 0;

	while (!q.empty())
	{
		auto [cost, node, coins] = q.top();
		q.pop();

		if (visited[node][coins])
			continue;

		visited[node][coins] = true;
		cost *= 1; // -1 if min queue

		for (auto [curr, coins] : adj[node])
		{

			// implement logic
			for (int hints = 0; hints <= coins; hints++)
			{
				int new_dst = max(cost, P[node] >> hints); // max between taking it or spending a coin (/2 difficulty)
				int new_coins = coins - hints + coins;
				cout << new_coins << endl;
				if (new_dst < dst[curr][new_coins])
				{
					dst[curr][new_coins] = new_dst;
					q.push({-new_dst, curr, new_coins});
				}
			}
		}
	}
	cout << *min_element(dst[N].begin(), dst[N].end()) << endl;
	return 0;
}

```

disjoint_set_union (find connected components in a graph/group connected elements)
```cpp
const int MOD = 1e9 + 7;

// Fast exponentiation
ll power_mod(ll a, ll b, ll mod_val) {
    ll res = 1;
    a %= mod_val;
    while(b > 0){
        if(b & 1){
            res = res * a % mod_val;
        }
        a = a * a % mod_val;
        b >>= 1;
    }
    return res;
}

struct DSU {
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int find_set(int x){
        if(parent[x] != x){
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }
    void union_set(int x, int y){
        int fx = find_set(x);
        int fy = find_set(y);
        if(fx != fy){
            parent[fx] = fy;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll R, C, N;
    cin >> R >> C >> N;
    struct Cell {
        ll r;
        ll c;
    };
    vector<Cell> cells(N);
    for(int i=0;i<N;i++) cin >> cells[i].r >> cells[i].c;
    
    // Collect unique rows, columns, d1, d2
    vector<ll> rows, columns, d1_list, d2_list;
    rows.reserve(N);
    columns.reserve(N);
    d1_list.reserve(N);
    d2_list.reserve(N);
    for(auto &[r, c] : cells){
        rows.push_back(r);
        columns.push_back(c);
        d1_list.push_back(r - c);
        d2_list.push_back(r + c);
    }
    
    // Sort and remove duplicates
    sort(rows.begin(), rows.end());
    rows.erase(unique(rows.begin(), rows.end()), rows.end());
    
    sort(columns.begin(), columns.end());
    columns.erase(unique(columns.begin(), columns.end()), columns.end());
    
    sort(d1_list.begin(), d1_list.end());
    d1_list.erase(unique(d1_list.begin(), d1_list.end()), d1_list.end());
    
    sort(d2_list.begin(), d2_list.end());
    d2_list.erase(unique(d2_list.begin(), d2_list.end()), d2_list.end());
    
    // Assign unique IDs
    // row IDs: 0 to rows.size()-1
    // column IDs: rows.size() to rows.size() + columns.size()-1
    // d1 IDs: rows.size() + columns.size() to rows.size() + columns.size() + d1_list.size()-1
    // d2 IDs: rows.size() + columns.size() + d1_list.size() to total-1
    ll row_offset = 0;
    ll column_offset = rows.size();
    ll d1_offset = column_offset + columns.size();
    ll d2_offset = d1_offset + d1_list.size();
    ll total_entities = d2_offset + d2_list.size();
    
    // Function to get ID for a row
    auto get_row_id = [&](ll r) -> int {
        return lower_bound(rows.begin(), rows.end(), r) - rows.begin() + row_offset;
    };
    // Function to get ID for a column
    auto get_column_id = [&](ll c) -> int {
        return lower_bound(columns.begin(), columns.end(), c) - columns.begin() + column_offset;
    };
    // Function to get ID for d1
    auto get_d1_id = [&](ll d1) -> int {
        return lower_bound(d1_list.begin(), d1_list.end(), d1) - d1_list.begin() + d1_offset;
    };
    // Function to get ID for d2
    auto get_d2_id = [&](ll d2) -> int {
        return lower_bound(d2_list.begin(), d2_list.end(), d2) - d2_list.begin() + d2_offset;
    };
    
    // Initialize DSU
    DSU dsu(total_entities);
    
    // For each cell, connect row, column, d1, d2
    for(int i=0;i<N;i++){
        ll r = cells[i].r;
        ll c = cells[i].c;
        ll d1 = r - c;
        ll d2 = r + c;
        int row_id = get_row_id(r);
        int column_id = get_column_id(c);
        int d1_id = get_d1_id(d1);
        int d2_id = get_d2_id(d2);
        
        // Connect row with column, row with d1, row with d2
        dsu.union_set(row_id, column_id);
        dsu.union_set(row_id, d1_id);
        dsu.union_set(row_id, d2_id);
    }
    
    // Count the number of unique parents
    unordered_set<int> parents;
    for(int i=0;i<total_entities;i++){
        parents.insert(dsu.find_set(i));
    }
    
    // The number of connected components is the number of unique parents
    ll k = parents.size();
    
    // Compute 2^k mod MOD
    ll answer = power_mod(2, k, MOD);
    
    cout << answer;
}
```

tree example 
```cpp 
vector<int> maxdesc, heights;
vector<vector<int>> adj;

void dist(int node, int h) {
    heights[node] = h;
    maxdesc[node] = h;
    for (auto child : adj[node]) {
        dist(child, h + 1);
        maxdesc[node] = max(maxdesc[node], maxdesc[child]);
    }
}

int pota(int N, vector<int> P) {
    // build tree
    adj.assign(N, vector<int>());
    for (int i = 1; i < N; ++i) {
        adj[P[i]].push_back(i);
    }

    heights.assign(N, 0);
    maxdesc.assign(N, 0);
    dist(0, 0);

    vector<int> source(N + 1, 0), end(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        source[heights[i]]++; // nodi validi fino a una certa altezza h
        end[maxdesc[i] + 1]++; // nodo non piu' valido dalla massima altezza raggiungibile +1
    }
    int curr = 0, keep = 0;
    for (int h = 0; h <= N; ++h) {
        curr += source[h] - end[h];
        keep = max(keep, curr);
    }
    return N - keep;
}
```


segtree with pointers 
```cpp 
struct Node {
    long long sum, max_sub, max_pref, max_suff;
    int nb, ne;

    Node *lc, *rc;
};

class Tree {
    Node *tree, *root;
    int nodes;

    Node* build(int arr[], int nb, int ne) {
        if (nb + 1 == ne) {
            tree[nodes] = {arr[nb], max(0, arr[nb]), max(0, arr[nb]), max(0, arr[nb]), nb, ne, NULL, NULL};
            return &tree[nodes++];
        }
        Node *lc = build(arr, nb, (nb + ne) / 2);
        Node *rc = build(arr, (nb + ne) / 2, ne);
        tree[nodes] = {
            lc->sum + rc->sum,
            max({lc->max_sub, rc->max_sub, lc->max_suff + rc->max_pref}),
            max(lc->max_pref, lc->sum + rc->max_pref),
            max(lc->max_suff + rc->sum, rc->max_suff),
            nb, ne, lc, rc
        };
        return &tree[nodes++];
    }

    void change(int x, int y, Node* node) {
        if (node->nb > x || node->ne <= x) return;
        if (node->nb + 1 == node->ne) {
            node->sum = y;
            node->max_sub = node->max_pref = node->max_suff = y;
            return;
        }
        change(x, y, node->lc);
        change(x, y, node->rc);
        
        node->sum = node->lc->sum + node->rc->sum;
        node->max_pref = max(node->lc->max_pref, node->lc->sum + node->rc->max_pref);
        node->max_suff = max(node->lc->max_suff + node->rc->sum, node->rc->max_suff);
        node->max_sub = max({node->lc->max_sub, node->rc->max_sub, node->lc->max_suff + node->rc->max_pref});
    }

    Node query(int x, int y, Node* node) {
        if (node->nb >= y || node->ne <= x) {
            return {0, -INF, -INF, -INF, node->nb, node->ne, NULL, NULL};
        }
        if (x <= node->nb && node->ne <= y) {
            return *node;
        }

        Node lc = query(x, y, node->lc);
        Node rc = query(x, y, node->rc);

        return {
            lc.sum + rc.sum,
            max({lc.max_sub, rc.max_sub, lc.max_suff + rc.max_pref}),
            max(lc.max_pref, lc.sum + rc.max_pref),
            max(lc.max_suff + rc.sum, rc.max_suff),
            node->nb, node->ne, NULL, NULL
        };
    }

public:

    long long query(int x, int y) {
        return query(x, y, root).max_sub;
    }

    void change(int x, int y) {
        change(x, y, root);
    }

    Tree(vector<int> arr) {
        tree = (Node*)malloc(1000000 * sizeof(Node));
        nodes = 0;
        root = build(arr.data(), 0, arr.size());
    }

};

int N, Q;
vector<int> V1, V2;

int main() {
    cin >> N >> Q;
    V1.resize(N);
    V2.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V1[i];
        if (i & 1) V1[i] *= -1;
        V2[i] = -V1[i];
    }

    Tree seg1(V1), seg2(V2);

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            if (a & 1) {
                seg1.change(a - 1, b);
                seg2.change(a - 1, -b);
            } else {
                seg1.change(a - 1, -b);
                seg2.change(a - 1, b);
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << max(seg1.query(l - 1, r), seg2.query(l - 1, r)) << endl;
        }
    }

    return 0;
}
```

