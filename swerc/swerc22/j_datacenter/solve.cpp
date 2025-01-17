#include<bits/stdc++.h>
using namespace std;
#define MAXN 105 

typedef pair<int,int> pii; 
typedef pair<int, pii> node; // source, (dest, cost)
/* ogni anno:
 * s -> 2 servers dello stesso colore di s
 * s -> t , se stesso colore s1-t1, s2-t2, 
 * altrimenti s1-t2, s2-t1
 *
 * ottengo nuovo grafo connesso
*/

// max dist in k anni
int diam, n, m, k; ;
int colors[MAXN];
int visited[MAXN][2]; 
vector<int> adj[MAXN]; // vector<vector<int>>

int dist(int odd, int even) {
  if (even == -1 || odd == -1)
    return max(even + k, odd + k);
  int mx = min(odd + k, even);
  for (int i = 0; i <= k; i++)
    mx = max(mx, min(odd + k - i, even + i));
  return mx;
}




// sparse graph ->  use max queue
int solve(int source) {
	queue<node> q;
	q.push(node(source, pii(0,0)));
	
	for(int i = 0; i < n; i++) 
		visited[i][0] = visited[i][1] = -1; 

	while(!q.empty()) {
		node neigh = q.front();
		q.pop(); 

		int idx = neigh.first; 
		int dist = neigh.second.first; 
		int par = neigh.second.second;

		if(visited[idx][par] != -1 and visited[idx][par] <= dist) continue; 

		visited[idx][par] = dist;

		// visit neighbours
		for(int i = 0; i < int(adj[idx].size());i++) {
			int adjidx = adj[idx][i]; 
			int adjdist = dist+1;

			// calcola nuova parita' del percorso 
			// se i due server hanno diverso colore, 
			// ho 1 path del colore "a" e un altro del colore "b" 
			// quindi cambio la parita' dei due cammini aggiungendo solo un arco e non 2
			// se colori diversi -> +1, altrimenti +0 (si mantiene la parita')
			int adjpar = (par + (colors[idx] != colors[adjidx])) % 2; // se pari

			if(visited[adjidx][adjpar] != -1 and visited[adjidx][adjpar] <= adjdist) continue;
			q.push(node(adjidx, pii(adjdist, adjpar)));
		}
	}

	for(int i = 0; i < n; i++) {
		diam = max(diam, dist(visited[i][0], visited[i][1]));
	}

}


int main() {
	ifstream cin("input0.txt");
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
		cin >> colors[i];

	int a, b; 
	for(int i = 0; i < m; i++) {
		adj[a].push_back(b); 
		adj[b].push_back(a);
	}

	diam = 0; 
	for(int i = 0; i < n; i++) 
		solve(i);

	cout << diam << endl;
	return 0;

}
