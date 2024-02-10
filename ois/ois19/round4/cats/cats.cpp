/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
// constraints
#define MAXN 1000

// input data
int Nm, Nf, i;
int M[MAXN], F[MAXN];
int dp[MAXN][MAXN]; // m:, f:

int score(int idxm, int idxf) {
    return abs(M[idxm] - F[idxf]);
}


int solve(int idxm, int idxf) {
    if(idxm == Nm || idxf == Nf) return 0;

    if(dp[idxm][idxf] == -1) { // not checked yet
        int al = score(idxm, idxf) + solve(idxm + 1, idxf + 1); // if m and f aligned: continue the line
        int skipM = solve(idxm + 1, idxf); // skip one male
        int skipF = solve(idxm, idxf + 1); // skip one female
        dp[idxm][idxf] = max(al, max(skipF, skipM)); // best 
    }
    return dp[idxm][idxf];

}



int main() {
//  uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Nm, &Nf));
    for(i=0; i<Nm; i++)
        assert(1 == scanf("%d", &M[i]));
    for(i=0; i<Nf; i++)
        assert(1 == scanf("%d", &F[i]));

    // insert your code here
        for (int i = 0; i < Nm; i++)
        for (int j = 0; j < Nf; j++)
            dp[i][j] = -1;

    
    printf("%d\n", solve(0,0)); 
    return 0;
}
