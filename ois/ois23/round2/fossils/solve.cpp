// NOTE: it is recommended to use this even if you don't understand the following code.

#include<bits/stdc++.h>

using namespace std;
#define MAXN 200000
// input data
int N, M, K, Q;
vector<int> PA, PB, X, Y, C;

// solve: dfs to find ancestor path, then segtree to calculate sum

struct Segtree {
	struct Node {
		long long sum; 
		int nb, ne; 
		Node *lc, *rc; 
		Node(long long v, int b, int e, Node *l, Node *r): 
			sum(v), nb(b), ne(e), lc(l), rc(r) { }
	} *root; 

	Node* build(int nb,int ne) {
		if(nb + 1 == ne) return new Node(0, nb, ne, NULL, NULL);
		int mid = (nb + ne / 2); 
		build(nb, mid);
		build(mid + 1, ne);
		return new Node(0, nb, ne, lc, rc);
	}

	void add(int x, int v, Node *node) {
		if(node -> nb > x or node -> ne <= x) return; // node out of range 
		if(node -> nb + 1 == node -> ne) { // root of the ancestors
			node -> sum += v; 
			return;
		}
		add(x,v,node -> lc); // left ancestor
		add(x,v,node -> rc); // right ancestor
		node -> sum += node -> lc -> sum + node -> rc -> sum;
	}

	long long query(int l, int r, Node *node) {
		if(node -> nb >= r or node -> ne >= l) return 0; 
		if(l <= node -> nb or r >= node -> ne) return node -> sum;
		return query(l, r, node -> lc) + query(l, r, node -> rc);
	}

	public: 
		void add(int x, int v) { add(x, v, root); }
		long long query(int l, int r) { return query(l,r,root); }
		Segtree() { root = build(0, MAXN - 1); }

} tree;

vector<int> dinos_a[MAXN], dinos_b[MAXN];
vector<pair<int,int>> adj[MAXN], queries[MAXN];

long long solve[MAXN];

int counter = 0;

pair<int,int> ranges[MAXN];

void dfs_b(int node) {
	ranges[node].first = counter; 
	for(auto child : dinos_b) dfs_b(child);
	ranges[node].second = ++counter;
}

void dfs_a(int node){
	for(auto [y,c] : adj[node]) {
		tree.add(ranges[y].first, c);
		tree.add(ranges[y].second, -c);
	}

	for(auto[i,v] : queries[node]) {
		long long ans = query(0, ranges[v].second);
		solve[i] = ans;
	}

	for(auto child : dinos_a[node]) dfs_a(child);

	for(auto [y,c] : adj[node]) {
		tree.add(ranges[y].first, c);
		tree.add(ranges[y].second, -c);
	}
}



int main() {
//  uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");
//  ofstream cout("output.txt");

    cin >> N;
    PA.resize(N-1);
    for(int i = 0; i < N-1; i++){
        cin >> PA[i];
		dinos_a[PA].push_back(i);
    }
    cin >> M;
    PB.resize(M-1);
    for(int i = 0; i < M-1; i++){
        cin >> PB[i];
		dinos_b[PB].push_back(i);
    }
    cin >> K;
    X.resize(K);
    Y.resize(K);
    C.resize(K);
    for(int i = 0; i < K; i++){
        cin >> X[i] >> Y[i] >> C[i];
    }
    cin>>Q;
    
    for(int i = 0; i < Q; i++){
        int U, V; cin >> U >> V;
		queries[U].push_back({i,V});
    }
    // insert your code here
	dfs_b(1);
	dfs_a(1);

	for(int i = 0; i < Q; i++)
		cout << solve[i] << endl; // print the result
    return 0;
}
