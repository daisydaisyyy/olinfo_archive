// source: https://cp-algorithms.com/graph/dijkstra_sparse.html#priority_queue
// find min/max element/path using priority queue, can be also used to find shortest path with best conditions (dijkstra) on a sparse graph
#include <bits/stdc++.h>
using namespace std;
// constraints
#define MAXN 10001
#define MAXM 50000
#define MAXC 100

// input data
int N, M, C_0, P[MAXN], i;
vector<pair<int, int>> adj[MAXN];

int main()
{
	//  uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");
	//  freopen("output.txt", "w", stdout);
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
