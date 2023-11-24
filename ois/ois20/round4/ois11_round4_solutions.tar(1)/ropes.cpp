/* Solution by edomora97
 * At the end there should be a path from the root to a leaf
 * So, for each knot we must untie degree-1 ropes, keeping the one to the
 * parent and the most costly one.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, i;
int P[MAXN], T[MAXN];
int mostc[MAXN+1];

int main() {
    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &P[i]));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &T[i]));

    int sol = 0;
    for (int i = 0; i < N; i++) {
        int p = P[i];
        int t = T[i];
        // new max? the old one was not the max, so it has to be cut
        if (t >= mostc[p]) {
            sol += mostc[p];
            mostc[p] = t;
        // not the max, cut it
        } else {
            sol += t;
        }
    }
    printf("%d\n", sol);
    return 0;
}
