// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// q richieste 
// turista a x metri dalla sorgente, vuole andare int y (punto + lontano) 
// max vi escursioni 
// min ui escursioni (non ripetute)
// escursioni devono essere consecutive
// se non possibile, return -1, altrimenti ritorna yi (punto + lontano)

struct Path{
	int self_paths; // numero di percorsi che puntano al nodo stesso (circolare, il turista stara' fermo)
	vector<ll> adj; // vettore adiacenze
	Path(): self_paths(0), adj() { }
};


int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");
    int N, l, r;
    cin >> N;
	map<ll, Path, greater<>> paths; // idx : vettore di adj : counter per gli archi su se stessi

    for (int i = 0; i < N; i++) {
        cin >> l >> r; 
		if(l == r) paths[l].self_paths++;
		else paths[l].adj.push_back(r);
	}	

	map<ll, vector<ll>> dp;
	for(auto [l, path] : paths) {
		auto [self, adj] = path; 
		dp[l].assign(N + 1, -1);
		dp[l][0] = l;

		for(auto r : adj) {
			dp[l][1] = max(dp[l][1],r); 
			if(paths.count(r)) { // if there is at least one path
				for(int i = 1; i < N; i++) {
					dp[l][i] = max(dp[l][i], dp[r][i-1]); // max y arrival from source l 
					//cout << dp[l][i] << " ";
				}
				//cout << endl;
			}
		}

		// count self/circular paths and take the best dist
		vector<ll> old_dp = dp[l]; 
		for(int i = 1 ; i <= self; i++) {
			for(int j = i; j <= N; j++) {
				dp[l][j] = max(dp[l][j],old_dp[j-i]);
			}
		}
	}

    int Q;
    cin >> Q;


    while(Q--) {
		ll x; cin >> x; 
		ll u, v; cin >> u >> v; 

		if(!paths.count(x)) {
			if(u == 0) cout << x << ' ';
			else cout << -1 << ' ';
		}
		else cout << *max_element(dp[x].begin() + u,dp[x].begin() + v + 1) << ' ';
	}
	cout << endl;

    return 0;
}
