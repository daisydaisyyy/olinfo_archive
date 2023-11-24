// sort by start, then do dynamic programming storing in val[i] the best you can have at time i of the current day

#include <stdio.h>
#include <assert.h>
#include <algorithm>

// constraints
#define MAXN 100000
#define MAXT 1024

using namespace std;

struct tournament {
    int D, S, E, B, P, i;
    
    bool operator<(const tournament& o) const {
        if (D != o.D) return D < o.D;
        if (S != o.S) return S < o.S;
        return i < o.i;
    }
};

// input data
int N, M, i, d, e;
int D[MAXN], S[MAXN], E[MAXN], B[MAXN], P[MAXN];
tournament T[MAXN];
int val[MAXT], num[MAXT];

int main() {
/*
    uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/

    assert(2 == scanf("%d %d", &N, &M));
    for(i=0; i<N; i++) {
        assert(5 == scanf("%d %d %d %d %d", &D[i], &S[i], &E[i], &B[i], &P[i]));
        T[i].D = D[i];
        T[i].S = S[i];
        T[i].E = E[i];
        T[i].B = B[i];
        T[i].P = P[i] - B[i]; // effective prize
        T[i].i = i;
    }
    sort(T, T+N);

    d = e = 0;
    val[0] = M;
    for (tournament& t : T) {
        // update val until the new start
        if (t.D > d) {
            for (; e<MAXT; e++) if (val[e+1] < val[e]) val[e+1] = val[e], num[e+1] = num[e];
            for (int i=0; i<MAXT; i++) val[i] = val[MAXT-1], num[i] = num[MAXT-1];
            d = t.D;
            e = t.S;
        } else for (; e<t.S; e++) if (val[e+1] < val[e]) val[e+1] = val[e], num[e+1] = num[e];
        // if possible to take the tournament, and worth it
        if (val[e] >= t.B and val[t.E] < val[e]+t.P)
            val[t.E] = val[e]+t.P, num[t.E] = num[e]+1; // update val of the end
    }
    for (; e<MAXT; e++) if (val[e+1] < val[e]) val[e+1] = val[e], num[e+1] = num[e];
    printf("%d\n", val[MAXT-1]);
//  printf("tournaments taken: %d/%d\n", num[MAXT-1], N); // if too low or too high, the test case is weak
    return 0;
}
