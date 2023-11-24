// Keep track of the number of friends (deg) that already took the dessert.
// Once this number reaches the limit L for a member,
// it is added to a stack of people waiting to order the dessert.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>

// constraints
#define MAXN 1000000

using namespace std;

// input data
int N, R, i, j;
int M[MAXN], L[MAXN], *F[MAXN], deg[MAXN];
vector<int> adj[MAXN], stack;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (i=0; i<N; i++) {
        assert(2 == scanf("%d %d", &M[i], &L[i]));
        F[i] = (int*)malloc(M[i]*sizeof(int));
        for (j=0; j<M[i]; ++j)
            assert(1 == scanf("%d", &F[i][j]));
    }

    for (i=0; i<N; i++)
        for (j=0; j<M[i]; ++j)
            adj[F[i][j]].push_back(i);
    for (i=0; i<N; i++)
        if (L[i] == 0)
            stack.push_back(i);
    
    while (!stack.empty()) {
        R++;
        i = stack.back();
        stack.pop_back();
        for (int f : adj[i]) {
            deg[f]++;
            if (deg[f] == L[f])
                stack.push_back(f);
        }
    }
    
    printf("%d\n", R); // print the result
    return 0;
}
