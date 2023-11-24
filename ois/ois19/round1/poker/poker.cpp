/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;
// constraints
#define MAXN 100000
#define MAXT 1024 // 10 ^ 9, contraint for b, p
// input data
int N, M, i;
int D[MAXN], S[MAXN], E[MAXN], B[MAXN], P[MAXN];
// d = day, s = start, e = end, b = fee, p = prize
int currM;
vector<vector<int>> dp(N);

struct tournament {
    int D, S, E, B, P, i;

    bool operator<(const tournament &o) {
        if(D != o.D)    return D < o.D;
        if(S != o.S)    return S < o.S;
        return i < o.i;
    }
};

tournament T[MAXN];
int val[MAXT], num[MAXT]; // val stores money held, num stores curr t idx

int main() {
    //  uncomment the following lines if you want to read/write from files
     freopen("input0.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    // ifstream cin("input0.txt");
    assert(2 == scanf("%d %d", &N, &M));
    currM = M;
    for(i=0; i<N; i++) {
        assert(5 == scanf("%d %d %d %d %d", &D[i], &S[i], &E[i], &B[i], &P[i]));
        T[i].D = D[i];
        T[i].S = S[i];
        T[i].E = E[i];
        T[i].B = B[i];
        T[i].P = P[i] - B[i];
        T[i].i = i;
    }

    // insert your code here
    sort(T, T+N);

    int d, e;
    d = e = 0; // e = curr start, d = curr day
    val[0] = M;

    for(auto t : T) {
        // day ended, update new val
        if(t.D > d) {
            for(; e < MAXT; e++) if(val[e + 1] < val[e]) val[e + 1] = val[e]; num[e + 1] = num[e]; // set the next money by default
            for(int i = 0; i < MAXT; i++) val[i] = val[MAXT - 1]; num[i] = num[MAXT - 1];
            e = t.S;
            d = t.D;
        } else for(; e < t.S; e++) if (val[e + 1] < val[e]) val[e+1] = val[e], num[e+1] = num[e]; // set the current money you have for all curr day before another t starts
        
        // start new if worth
        if(val[e] >= t.B and val[t.E] >= val[e] + t.P) // if worth (i have money and the new t prize is > the curr best money i would have at the end of the curr t)
            val[t.E] = val[e] + t.P, num[t.E] = num[e] + 1;
    
    }

    for(; e < MAXT; e++) if(val[e + 1] < val[e]) val[e + 1] = val[e], num[e + 1] = num[e];
 

    
    printf("%d\n", val[MAXT-1]); // change 42 with actual answer
    return 0;
}
