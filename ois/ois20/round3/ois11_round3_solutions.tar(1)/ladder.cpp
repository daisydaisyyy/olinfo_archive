// Observation: the answer is the largest value among
// all the (positive) differences.

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000000

// input data
int N, i;
int V[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &V[i]));

    int sol = V[0], diff;
    
    for (i=1; i<N; i++) {
        diff = V[i] - V[i-1];
        if (diff > sol)
            sol = diff;
    }

    printf("%d\n", sol);
    return 0;
}
