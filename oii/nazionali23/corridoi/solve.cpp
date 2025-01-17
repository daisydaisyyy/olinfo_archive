#include <bits/stdc++.h>
using namespace std;
#define MAXN 100'000
typedef long long ll;
vector<pair<int,int>> adj[MAXN];
bitset<MAXN> visited;


void dijkstra(int N, int source, vector<ll> &dist) {
	visited.reset(); 
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
	q.emplace(dist[source] = 0, source); 
	while(!q.empty()) {
		auto [d, node] = q.top(); q.pop(); 
		if(visited.test(node)) continue; 
		visited.set(node);
		for(auto [prox,weight]: adj[node]) {
			if(d + weight < dist[prox]) 
				q.emplace(dist[prox] = d + weight, prox);
		}
	}

}



vector<long long> shorten(int N, int M, int Q, vector<long long> K, vector<int> A, vector<int> B, vector<int> C) {
    for(int i = 0; i < M; i++) {
		adj[A[i]].emplace_back(B[i],C[i]);
		adj[B[i]].emplace_back(A[i],C[i]);
	}

	vector<ll> room0(N, 1e18), room1(N,1e18), room2(N,1e18); 
	dijkstra(N, 0, room0);
	dijkstra(N, 1, room1);
	dijkstra(N, 2, room2);

	ll one = 1e18; 
	vector<pair<ll,ll>> paths(N + 1);
	paths[N] = {1e18, 1e18};

	for(int i = 0; i < N; i++) { // costo percorso di andata e ritorno passando per le tre stanze da tutti i nodi
		paths[i] = {2 * room1[i] + room0[i] + room2[i], room1[i]};
	}
	sort(paths.begin(), paths.end());

	vector<ll> ans(Q); 
	vector<pair<ll,int>> carts(Q);

	for(int i = 0; i < Q; i++) carts[i] = {K[i], i}; // capienza, idx carrello
	sort(carts.begin(), carts.end());

	int end = 0; 
	for(auto [pos, idx]: carts) {
		while(paths[end].second < pos) { // andata
			one  = min(one, paths[idx].first - paths[end].second);
			end++;
		}

		ans[idx] = min(paths[idx].first - 2 * pos, one - pos); // ritorno
		if(ans[idx] <= 0) {
			ans[idx] = 0; 
			break;
		}
	}

    return ans;
}



int main() {
	ifstream cin("corridoi.input0.txt");
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<long long> K(Q);
    for (int i = 0; i < Q; i++) {
        cin >> K[i];
    }
    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<long long> soluzione = shorten(N, M, Q, K, A, B, C);
    cout << soluzione.size() << "\n";
    for (int i = 0; i < soluzione.size(); i++) {
        cout << soluzione[i] << ' ';
    }
    cout << "\n";
}

