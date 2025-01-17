/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
using namespace std;
// constraints
#define MAXN 100000

// input data
int N, i;
int A[MAXN], T[MAXN+1];
int best[MAXN+1];
int tree[4*MAXN];

/*
a -> Ca 
Sj > Sj+1 o Sj+1 = C_Sj
 */

// note a, b; l = left, r = right
int solve(int a, int b, int l, int r, int n) {
	if(b < l || a > r) 
		return 0; 

	if (l >= a && r <= b) // already calculated
		return tree[n]; 

	return max(solve(a,b,l, (l+r)/2, n *2),solve(a,b, (l+r)/2+1, r, n *2+1)); // return max of the 2 branches 

}


int solve(int i) {
	return solve(i, N, 1, N, 1);
}

// create a segment tree (1st element = root)
void update(int i, int v, int l, int r, int n) {
	if (i < l || i > r)
		return;

	if (i == l && l == r) {
		tree[n] = v; 
		return;
	}

	update(i, v, l, (l+r)/2, n*2); // build first branch 
	update(i, v, (l+r)/2+1,r, n*2+1); // 2nd branch 
	tree[n] = max(tree[n*2], tree[n*2+1]); // update with max 

}


void update(int i, int v) {
	update(i, v, 1, N, 1);
}


int main() {
//  uncomment the following lines if you want to read/write from files
	freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &A[i]));

    for(i=1; i<=N; i++)
        assert(1 == scanf("%d", &T[i]));

    // WARNING! C is indexed from 1!
    // In particular C[i] is the complementary pitch 
	// of pitch i.

    // insert your code here
	for(i = N-1; i >= 0; i--) {
		best[A[i]] = max(best[A[i]], best[T[A[i]]] + 1);
		best[A[i]] = max(best[A[i]], solve(A[i]+1) + 1);
		update(A[i], best[A[i]]);
	}


    printf("%d\n", solve(1)); // print the result
    return 0;
}
