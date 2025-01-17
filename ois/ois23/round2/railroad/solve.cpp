#include <bits/stdc++.h>
#define MAXN 100'000
using namespace std;

int N, M; 
vector<tuple<int,int,bool>> adj[MAXN]; 
long long dst[MAXN];
bool visited[MAXN];

long long dijkstra1() {
	fill(dst, dst + N, 1e18); 
	vector<int> from(N,-2); 

	priority_queue<tuple<long long, int, int>> q; 
	q.push({0,0,-1}); 
	dst[0] = 0; 
 
	while(!q.empty()) { 		
		auto [d, note, origin] = q.top(); 
		q.pop(); 
		if(from[node] != -2) continue;

		d *= -1; 
		from[node] = origin; 
		for (auto [n, w, c]: adj[node]) {
			if (d + w < dst[n]) {
				dst[n] = d + w; 
				q.push({-dst[n], n, node});
			}
		}
	}

	fill(visited, visited + N, false); 
	for(int i = N - 1; i != -1; i = from[i]) visited[i] = true; 
	for(int i = 0; i < N; i++) {
		for(auto &[n, w, c]: adj[i]) {
			if(visited[i] && visited[n]) c = false; 
		}
	}
	return dst[N-1];
}





long long dijkstra3() { // vanilla implementation 
	fill(dst, dst + N, 1e18); 
	fill(visited, visited + N, false); 

	priority_queue<tuple<long long, int, int>> q; 
	q.push({0,0}); 
	dst[0] = 0; 
 
	while(!q.empty()) {
		auto [d, node] = q.top(); 
		q.pop(); 
		if(visited[node]) continue;

		d *= -1; 
		visited[node] = true; 
		for (auto [n, w, c]: adj[node]) {
			if (d + w < dst[n]) {
				dst[n] = d + w; 
				q.push({-dst[n], n, node});
			}
		}
	}
	return dst[N-1];
}

int fastscan() {
    int ans = 0;
    char c;
    while ((c = getchar_unlocked()) >= '0')
        ans = 10 * ans + c - 48;
    return ans;
}




int main() {
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input0.txt");
    //  ofstream cout("output.txt");
	N = fastscan();
    M = fastscan();
    for (int i = 0; i < M; i++) {
        int A = fastscan(), B = fastscan(), T = fastscan();

        adj[A].push_back({B, T, true});
        adj[B].push_back({A, T, true});
    }

	long long best = dijkstra1(); // find best path 
    
	if(true == true) { // normal dijkstra for small graphs
		long long mi = INT_MAX; 
		for(int i = 0; i < N; i++) {
			for(auto &[n,w,c]: adj[i]) {
				if(!c) continue; 
				int old_w = w; 
				w = 1; 
				long long dst = dijkstra3(); 
				if(dst < best) {
					mi = min(mi, old_w - best + dst);
				}
				w = old_w;
			}
		}
		if(mi == INT_MAX) mi = -1;
		cout << mi << endl; 
		return 0;
	}

	int l = 1, r = 1e9; 
    cout << 0 << endl; // print the result

    return 0;
}
