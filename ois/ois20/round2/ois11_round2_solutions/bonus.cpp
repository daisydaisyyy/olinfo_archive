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
int N, i;
int S[MAXN], P[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++) {
        assert(1 == scanf("%d", &S[i]));
        assert(1 == scanf("%d", &P[i]));
    }

    int sumP = 0;
    int sumS = 0;
    for (i = 0; i < N; i++) {
        sumP += P[i];
        sumS += S[i];
    }

    int best = 0;
    for (i = 0; i < N; i++) {
        double ratio = 1.0 * (sumS - S[i]) / (sumP - P[i]);
        double best_ratio = 1.0 * (sumS - S[best]) / (sumP - P[best]);
        if (ratio > best_ratio) {
            best = i;
        }
    }

    printf("%d\n", best); // print the result
    return 0;
}
