#include<bits/stdc++.h>
using namespace std;
#define MAXN 1500
bool adj[MAXN][MAXN];

void solve(int t) {
	memset(adj, 0, sizeof(adj));

    int N, M, a, b;
    cin >> N >> M;

	vector<pair<int,int>> edges;
	edges.reserve(M);
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b; 
		if(adj[a][b]) continue; 
		adj[a][b] = adj[b][a] = true;
		edges.emplace_back(a,b);
    }

    int risposta = 0;
	for(int i = 0; i < M ; i++) {
		auto [a1,b1] = edges[i];
		//cout << a1 << " " << b1 << endl;
		for(int j = i + 1; j < M ; j++) {
			auto [a2,b2] = edges[j];
			//cout << a2 << " " << b2 << endl;

			// if same edges, skip them 
			if(a1 == a2 or a1 == b2) continue; 
		    if(b1 == a2 or b1 == b2) continue;

			if(adj[a1][a2] and adj[b1][b2] and !adj[a1][b2] and !adj[b1][a2]) risposta++;
			if(!adj[a1][a2] and !adj[b1][b2] and adj[a1][b2] and adj[b1][a2]) risposta++;
		}
	}

    risposta /= 2;

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}

