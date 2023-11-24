/*
 * COMPLEXITY: O(M inverse_ackermann(M)), that is approximately O(M)
 * IDEA: I keep an union-find structure, enhanced with an indication of potential of nodes
 * relative to their root. If the structure breaks, I have found the error.
 */

#include <assert.h>
#include <stdio.h>
#include <algorithm>

#define MAXN 102400

using namespace std;

int pot[MAXN], rnk[MAXN], parent[MAXN];

// finds the root of x, attaching x to it
int find(int x) {
    if (x == parent[x]) // already root, nothing to do
        return x;
    int root = find(parent[x]); // fix parent and get root
    pot[x] += pot[parent[x]]; // pot relative to root instead of parent
    parent[x] = root; // change parent to root
    return root;
}

// unites x and y while ensuring potential difference z:
// pot[x] + pot[fx] = pot[y] + pot[fy] + z should hold at the end.
// returns false if doesn't succeed
bool unite(int x, int y, int z) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) // same root, just checking
        return pot[x] == pot[y] + z;
    z += pot[y] - pot[x]; // pot[fx] = pot[fy] + (z + pot[y] - pot[x]) should hold
    if (rnk[fx] > rnk[fy]) { // better attach them in the other way
        swap(fx, fy);
        z = -z;
    }
    parent[fx] = fy;
    pot[fx] = z;
    if (rnk[fx] == rnk[fy])
        rnk[fy] += 1;
    return true;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    int N, M;
    assert(2 == scanf("%d %d", &N, &M));
    for (int i = 0; i < N; i++) parent[i] = i;
    for (int i = 0; i < M; i++) {
        int a, b, z;
        assert(3 == scanf("%d %d %d", &a, &b, &z));
        if (not unite(a, b, z)) {
            printf("%d\n", i);  // print the result
            return 0;
        }
    }

    printf("%d\n", M);  // print the result
    return 0;
}
