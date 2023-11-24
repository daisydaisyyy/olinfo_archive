// Solution to islands by lucach
// DFS from every inner position, being careful with borders and
// stopping at the sea.

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int R, C, i, j;
int M[MAXN][MAXN];
bool visited[MAXN][MAXN];

int visit(int x, int y) {
    visited[x][y] = true;
    if (M[x][y] == 1 and (x == 0 or x == R-1 or y == 0 or y == C-1))  // border, not an island
        return 0;
    if (M[x][y] == 0) // touched the sea, do not explore further
        return 1;
    int up = 1, down = 1, left = 1, right = 1;
    if (!visited[x-1][y]) up    = visit(x-1, y);
    if (!visited[x+1][y]) down  = visit(x+1, y);
    if (!visited[x][y-1]) left  = visit(x, y-1);
    if (!visited[x][y+1]) right = visit(x, y+1);
    
    if (up + down + left + right == 4)  // everything is fine
        return 1;
    else
        return 0;
}

int main() {
    assert(2 == scanf("%d %d", &R, &C));
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    int islands = 0;
    for (i = 1; i < R-1; i++)
        for (j = 1; j < C - 1; j++)
            if (!visited[i][j] and M[i][j] == 1)
                islands += visit(i, j);

    printf("%d\n", islands);
    return 0;
}
