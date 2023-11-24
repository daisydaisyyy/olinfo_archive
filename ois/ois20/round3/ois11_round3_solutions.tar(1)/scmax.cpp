/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <algorithm>

// constraints
#define MAXN 100000

using namespace std;

// input data
int N, i;
int A[MAXN], T[MAXN+1];
int best[MAXN+1];
int tree[4*MAXN];

int get(int a, int b, int l, int r, int n) {
    if (b < l || a > r) {
        return 0;
    }

    if (l >= a && r <= b) {
        return tree[n];
    }

    return max(get(a, b, l, (l+r)/2, n*2), get(a, b, (l+r)/2+1, r, n*2+1));
}

int get(int i) {
    return get(i, N, 1, N, 1);
}

void update(int i, int v, int l, int r, int n) {
    if (i < l || i > r) return;
    if (i == l && l == r) {
        tree[n] = v;
        return;
    }
    update(i, v, l, (l+r)/2, n*2);
    update(i, v, (l+r)/2+1, r, n*2+1);
    tree[n] = max(tree[n*2], tree[n*2+1]);
}

void update(int i, int v) {
    update(i, v, 1, N, 1);
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &A[i]));

    for(i=1; i<=N; i++)
        assert(1 == scanf("%d", &T[i]));

    // WARNING! T is indexed from 1!
    // In particular T[i] is the preferred number of i.

    // insert your code here

    for (int i = N-1; i >= 0; i--) {
        best[A[i]] = max(best[A[i]], best[T[A[i]]]+1);
        best[A[i]] = max(best[A[i]], get(A[i]+1)+1);
        update(A[i], best[A[i]]);
    }

    printf("%d\n", get(1)); // print the result
    return 0;
}
