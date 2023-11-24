// Notice that the maximum sum of digits for a number below 10^9 is 9x9=81.
// Thus, the maximum "sum of sums" is 79 + 16 + 7 = 102, and the decodings of E are above E-102.
// To be fast on decoding intervals of numbers, I precompute encodings of small numbers and
// keep the current sum of digits updated. Then, I start from Emin-102 and save their encoding
// for later use.

#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXD 128 // maximum value for encode(N) - N, obtained for 799.999.999 (and similar)
#define NONE -1  // no decodings found
#define MULT -2  // multiple decodings found

using namespace std;

// input data
int Emin, Emax;

int enc[MAXD], dec[MAXD];

int encode(int N) {
    if (N < 10) return N; // single digit
    int S = 0, K = N;
    for (; K>0; K/=10) S += K%10; // sum of digits
    return N + encode(S);
}

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    
    assert(2 == scanf("%d %d", &Emin, &Emax));
    
    for (int i=0; i<MAXD; i++) {
        enc[i] = encode(i); // precompute encoding of small numbers
        dec[i] = NONE;      // no decoding found so far
    }
    // sum of digits of the number before the start
    int sum = 0;
    if (Emin > MAXD) for (int t=Emin-MAXD-1; t>0; t/=10) sum += t%10;
    else sum = -1;
    // main loop
    for (int E=max(Emin-MAXD,0); E<=Emax; E++) {
        // update sum of digits
        sum++;
        for (int t=E; t>0 and t%10==0; t/=10) sum -= 9;
        // store encoding of E
        int encE = E < 10 ? E : E + enc[sum];
        dec[encE%MAXD] = dec[encE%MAXD] == NONE ? E : MULT;
        // print decodings of E if appropriate
        if (E >= Emin) {
            if      (dec[E%MAXD] == NONE) printf("IMPOSSIBLE\n");
            else if (dec[E%MAXD] == MULT) printf("AMBIGUOUS\n");
            else printf("%d\n", dec[E%MAXD]);
        }
        // reset
        dec[E%MAXD] = NONE;
    }
    return 0;
}
