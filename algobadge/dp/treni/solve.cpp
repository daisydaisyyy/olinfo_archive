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



 // giorno, scelta 0, 1, 2

int solve(const int A[], const int B[], const int &N, const int &day, const bool &taken, vector<vector<int>> &dp){
    if(day == N){
        return 0;
    }
    if(dp[day][taken] == -1){
        int a=0, b=0, c=0;
        a = solve(A, B, N, day+1, true, dp) + A[day];
        c = solve(A, B, N, day+1, false, dp);
        if(!taken){
            b = solve(A, B, N, day+1, true, dp) + B[day];
        }
        dp[day][taken] = max(max(a,b),c);
    }
    return dp[day][taken];
}

int tempo_massimo(int N, int a[], int b[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(a, b, N, 0, 0, dp);   
}


int main()
{
    int n;
    FILE *in = fopen("input.txt", "r"), *out = stdout;
    // cout << "a";
    assert(fscanf(in, "%d", &n) == 1);
    int a[n];
    int b[n];

    
    for(int i=0; i<n; i++){
      assert(fscanf(in, "%d", &a[i]) == 1);
      assert(fscanf(in, "%d", &b[i]) == 1);
    }

    int answ = tempo_massimo(n, a, b);
    fprintf(out, "%d\n", answ);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}


