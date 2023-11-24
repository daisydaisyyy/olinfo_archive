/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
long long N, i;
long long S[MAXN], P[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%lld", &N));
    for(i=0; i<N; i++) {
        assert(1 == scanf("%lld", &S[i]));
        assert(1 == scanf("%lld", &P[i]));
    }

    long long sumP = 0;
    long long sumS = 0;
    for (i = 0; i < N; i++) {
        sumP += P[i];
        sumS += S[i];
    }

    long long best = 0;
    for (i = 0; i < N; i++) {
        if ((sumS - S[i]) * (sumP - P[best]) >= (sumS - S[best]) * (sumP - P[i])) {
            best = i;
        }
    }

    printf("%lld\n", best); // print the result
    return 0;
}
