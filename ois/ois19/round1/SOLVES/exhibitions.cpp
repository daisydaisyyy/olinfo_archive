// the most awesome pet wins everywhere, except on exhibitions controlled by the
// other pet and no better than the best exhibition of the other pet controlled
// by the other pet

#include <assert.h>
#include <stdio.h>

// constraints
#define MAXN 102400

// input data
int N, M, i, best, opponent, count;
int A[MAXN], P[MAXN], G[MAXN], E[MAXN], R[MAXN];

int main() {
    assert(2 == scanf("%d %d", &N, &M));
    for (i = 0; i < M; i++) assert(1 == scanf("%d", &E[i]));
    for (i = 0; i < N; i++) assert(3 == scanf("%d %d %d", &A[i], &P[i], &G[i]));

    // find the most awesome exhibition
    for (i = 1; i < N; i++)
        if (A[i] > A[best]) best = i;
    // by default, this pet wins everywhere
    for (i = 0; i < N; i++) R[i] = P[best];

    // find the most awesome exhibition of the other pet, controlled by a guide
    // of the other pet
    opponent = N;
    A[opponent] = -1;
    for (i = 0; i < N; i++)
        if (P[i] != P[best] and G[i] != P[best] and A[i] > A[opponent])
            opponent = i;
    // the other pet may win on exhibitions with A[i] <= A[opponent] controlled
    // by the other pet
    for (i = 0; i < N; i++)
        if (G[i] == P[opponent] and A[i] <= A[opponent]) {
            R[i] = P[opponent];
            count++;
        }
    // but if there is only one such exhibition, the other pet has no chance
    if (count == 1) R[opponent] = P[best];

    for (i = 0; i < M; i++) printf("%d ", R[E[i]]);
    printf("\n");
    return 0;
}
