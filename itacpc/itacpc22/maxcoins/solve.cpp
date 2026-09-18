#include <bits/stdc++.h>
using namespace std;

const long long INF = -1e18; // un valore molto negativo (per inizializzare il dp)
int N, M;

/*
find max coins to collect starting from lvl 0 to N-1
problem: the graph can contain cycles, to use dp to find the optimal solution we need an acyclic graph (we may end in a cycle loop instead)

- find strongly connected component (where all nodes are reachable, so if we enter it we are able to collect every coin inside those nodes)
(to find them, on internet i saw kosaraju algorithm, don't know if there is a better way)

- reduce the original graph to a simpler graph by condensing each connected components into a single node obtaining a new acyclic graph
- the edges will be created if there was a connection from a node of the components and another outside that component

- now use dp to find best solution and use a queue to process nodes
*/

int main()
{

    cin >> N >> M;
    vector<long long> coins(N);
    vector<vector<int>> graph(N), graph_t(N);
    for (auto &x : coins)
        cin >> x;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);   // directed graph
        graph_t[b].push_back(a); // directed graph with inverted edges (serve per Kosaraju, per trovare le componenti fortemente connesse)
    }

    // kosaraju's algorithm, find connected components
    vector<int> order;       // ordered nodes from dfs
    vector<int> comp(N, -1); // comp[i] = id della componente di i
    vector<bool> visited(N, false);

    // dfs on the original graph: order nodes for exit time from dfs
    function<void(int)> dfs = [&](int u)
    {
        visited[u] = true;
        for (int v : graph[u])
            if (!visited[v])
                dfs(v);
        order.push_back(u);
    };

    // dfs on the trasposed graph: find connected components
    function<void(int, int)> dfs_t = [&](int u, int c)
    {
        comp[u] = c; // assign component to the node
        for (int v : graph_t[u])
            if (comp[v] == -1)
                dfs_t(v, c);
    };

    for (int i = 0; i < N; i++)
        if (!visited[i])
            dfs(i);

    // sort order
    reverse(order.begin(), order.end());

    // find connected components
    int comp_tot = 0;
    for (int u : order)
        if (comp[u] == -1)
            dfs_t(u, comp_tot++);

    // sum coins for each connected components
    vector<long long> sum(comp_tot, 0);
    for (int i = 0; i < N; i++)
        sum[comp[i]] += coins[i];

    // build directed acyclic graph from connected components, every connected components becomes a node of the new graph
    // in the new graph there will not be cycles!
    vector<vector<int>> new_graph(comp_tot);
    vector<int> in_edges(comp_tot, 0);

    for (int u = 0; u < N; u++)
    {
        for (int v : graph[u])
        {
            if (comp[u] != comp[v])
            { // if there are different components, add an edge
                new_graph[comp[u]].push_back(comp[v]);
                in_edges[comp[v]]++; // inc number of edges entering the node
            }
        }
    }

    // dp on the new graph
    vector<long long> dp(comp_tot, INF);
    dp[comp[0]] = sum[comp[0]];

    queue<int> q;
    for (int i = 0; i < comp_tot; i++)
        if (in_edges[i] == 0)
            q.push(i); // source nodes

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : new_graph[u])
        {
            
            if (dp[u] != INF)
                // sum coins and move to node v if you can reach v from u, and it's a better value than any other route visited to reach v
                dp[v] = max(dp[v], dp[u] + sum[v]);

            // put the node in the queue
            if (--in_edges[v] == 0)
                q.push(v);
        }
    }

    cout << dp[comp[N - 1]] << "\n"; // max value reachable in the last level (N-1)
}
