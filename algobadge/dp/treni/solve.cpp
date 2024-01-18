#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;



#define MAXN 1000000
#define MAXT 1000
/*
a = superfast 
b = hyperfast -> solo se il giorno prima non prendo nessun treno
*/

vector<int> a;
vector<int> b;

// int dp[MAXN + 1][MAXT + 1]; // giorno, tempo
std::vector<std::vector<int>> dp(MAXN + 1, std::vector<int>(MAXT + 1, -1));

int tempo_massimo(int n, int t) {
    if(n < 0) return 0; // base case

    if(dp[n][t] == -1) 
        dp[n][t] = max(tempo_massimo(n-2, t) + b[n], tempo_massimo(n-1, t) + a[n]);
    
    cout << "n: " << n << "\tt: " << t << "\tdp: " << dp[n][t] << endl;
    
    return dp[n][t];
    

}

int main()
{
    int n;
    FILE *in = fopen("input.txt", "r"), *out = stdout;
    cout << "a";
    assert(fscanf(in, "%d", &n) == 1);

    a.resize(n);
    b.resize(n);
    cout << "what";
   
    // // giorno 0: tempo max 
    for(int i = 1; i < MAXT; i++) dp[0][i] = MAXT;

    for(int i=0; i<n; i++){
      assert(fscanf(in, "%d", &a[i]) == 1);
      assert(fscanf(in, "%d", &b[i]) == 1);
    }

    int answ = tempo_massimo(n, 0);
    fprintf(out, "%d\n", answ);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}


