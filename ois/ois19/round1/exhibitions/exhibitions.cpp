/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, M, i, opponent, count;
int A[MAXN], P[MAXN], G[MAXN], E[MAXN], R[MAXN];

int main() {

/*
    uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/
    freopen("input0.txt", "r", stdin);

    assert(2 == scanf("%d %d", &N, &M));
    for (i=0; i<M; i++)
        assert(1 == scanf("%d", &E[i]));
    for (i=0; i<N; i++)
        assert(3 == scanf("%d %d %d", &A[i], &P[i], &G[i]));
    
    // insert your code here

    //if pet = max and e controlled by it: wins
    //if pet = max , e not controlled by it, other pets A < pet: wins

    //find best pet
    int best = 0;
    for (i = 1; i < N; i++) if(A[i] > A[best])  best = i;

    //wins by default
    for (i = 1; i < N; i++)  R[i] = P[best];

    //find other pet best if e not controlled by that pet
    opponent = N;
    A[opponent] = -1;
    for (i = 1; i < N; i++) 
        if(P[i] != P[best] and G[i] != P[best] and A[i] > A[opponent])  // if other pet, the guide is of the other pet and it's the current max A
            opponent = i; // set the current best opponent

    //if A[i] <= A[best] then the opponent wins if controlled by the same pet
    for( i = 0; i < N; i++) 
        if (G[i] == P[opponent] and A[i] <= A[opponent]) {
            R[i] = P[opponent];
            count++;
        }
    

    if(count == 1)  R[opponent] = P[best]; // only one exhibition: the other pet wins

    for (i = 0; i < M; i++)  printf("%d ", R[E[i]]); // change 42 with actual answer for i-th group
    
    printf("\n");
    return 0;
}
