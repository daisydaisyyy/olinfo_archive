/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int R, C, i, j;
int M[MAXN][MAXN];
bool visited[MAXN][MAXN];

/*
 constraints: 
 non sul bordo (i = 0, R-1; j = 0, R-1) 
 celle raggiungibili con i+-1 o j +-1
 */


int visit(int i, int j) {
	visited[i][j] = true;

	// border 
	if(M[i][j] == 1 and (i == 0 or j == 0 or i == R-1 or j == C-1)) return 0; 
	
	// sea 
	if(M[i][j] == 0) return 1; 

	int u = 1, d = 1, r = 1, l = 1;
	if(!visited[i][j+1]) r = visit(i,j+1);
	if(!visited[i][j-1]) l = visit(i,j-1);
	if(!visited[i+1][j]) d = visit(i+1, j);
	if(!visited[i-1][j]) u = visit(i-1, j);

	if(u + d + r + l == 4) return 1; // no borders encountered (never returned 0) 
	return 0;
			
}


int main() {
//  uncomment the following lines if you want to read/write from files
	//freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &R, &C));
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    // insert your code here
	int islands = 0; 
	for (i = 1; i < R - 1; i++) {
		for (j = 1; j < C - 1; j++) {
			if(!visited[i][j] && M[i][j] == 1) {
				islands += visit(i, j);
			}
		}
	}

    printf("%d\n", islands); // print the result
    return 0;
}
