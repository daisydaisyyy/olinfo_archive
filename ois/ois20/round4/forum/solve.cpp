/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <vector> 
#include <iostream> 
using namespace std;
// constraints
#define MAXD 500000
#define MAXP 500000
#define MAXE 500000

/*
 * D directories , containing another d or 0 or more posts identified by integers from 0 to D-1
 * p posts identified by integers from D to D+P-1, D = 0 is root  
 * post with id = i is in dir A[i]
 * A[0] = -1 
 * E events, type T_j and id_j, 
 * types: 0 - unsub 1 - subscribed to d or post with id_j, recursive 2 - new commend on post id_j

find if user not sub to any dir or post with id_j 
A = events list 
*/


// input data
int D, P, E, i;
int A[MAXD+MAXP];
int T[MAXE], id[MAXE];
vector<vector<int>> adj;
vector<int> left_v, right_v;

int t = 0; // branch of the tree
void calc_times(int u) {
	left_v[u] = t++;
	for(auto v : adj[u]) calc_times(v);
	right_v[u] = t-1;
}

vector<int> tree;

void propagate(int id) { // propagate changes in the adj dirs
	if (tree[id] != 0) {
		tree[id * 2] = tree[id*2+1] = tree[id]; 
	}
	tree[i] = 0;
}

void update(bool active, int b, int node, int l = 0, int r = D+P-1, int id = 1) {
	if(node < l || b > r)	return; 
	if(l >= b && r <= node) { // if at the edge of left and right range
		if(active) tree[id] = 1; // node active 
		else tree[id] = -1; // node inactive
		return;
	}
	propagate(id); // propagate node status 
	update(active, b, node, l, (l+r)/2, id*2); // update 1st branch 
	update(active, b, node, (l+r)/2+1, r, id*2+1);
}


int get(int node, int l = 0, int r = D+P-1, int id = 1) {
	if(l == r) {
		return tree[id];
	}

	propagate(id);
	if(node <= (l+r)/2) {
		return get(node, l, (l+r)/2, id * 2);
	}
	return get(node, (l+r)/2+1, r, id * 2 + 1); 
}


int main() {
//  uncomment the following lines if you want to read/write from files
    //freopen("input1.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d%d%d", &D, &P, &E));
    for(i=0; i<D+P; i++)
        assert(1 == scanf("%d", &A[i]));
    for(i=0; i<E; i++)
        assert(2 == scanf("%d%d", &T[i], &id[i]));

    // insert your code here
	adj.resize(D+P); 
	for(int i = 1; i < D+P; i++) {
		adj[A[i]].push_back(i); // numerate events
	}

	left_v.resize(D+P); 
	right_v.resize(D+P); 

	calc_times(0); // calc depth of the tree
				   //
	tree.assign(4*(D+P), -1);

	for(int i = 0; i < E; i++) {
		if(T[i] == 2) { // new comment, see if subscribed or not 
			int res = get(left_v[id[i]]); 
			printf("%d\n", (res == -1 ? 0:1));
		} else { // == 0 -> unsubscribed, else subscribed
			update((T[i] == 0 ? false : true), left_v[id[i]], right_v[id[i]]); 
		}
	}
	
    return 0;
}
