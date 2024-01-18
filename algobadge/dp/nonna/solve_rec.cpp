#include <stdio.h>
#include <assert.h>
#include <cstring>
#include<limits>
#include<iostream> 
using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

/*
N = portate 
K = minimo P totale
P min ma almeno == K
*/

int P[MAXN];
int N, K, i;
int dp[MAXN + 1][MAXK + 1]; // num portata, peso


int mangia(int n, int k) {
    // printf("n: %d\tk: %d\n", n, k);
    // Mettete qui il codice della soluzione
    
    if(k < 0) return 0;
    
    if(dp[n][k] == -1) // compute subproblem
        dp[n][k] = min(mangia(n - 1, k - P[n - 1]) + P[n - 1], mangia(n - 1, k)); // 1: take the serving, 2: skip to next serving
     
    return dp[n][k];
}

int main() {
    FILE *fr, *fw;
    memset(dp, -1, sizeof dp);

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));


    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));

    for(i = 1; i <= K; i++) dp[0][i] = MAXP;
   
    int sol = mangia(N, K);
 
    fprintf(fw, "%d\n", sol);
    fclose(fr);
    fclose(fw);
    return 0;
}
