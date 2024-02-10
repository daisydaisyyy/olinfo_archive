/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;

/*
E = euros remaining
p = prices
*/

// constraints
#define MAXN 100000

// input data
int N, E, i;
int p[MAXN];
int r[MAXN]; // max money at item i


int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &E));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &p[i]));

    p[N] = 0;
    r[0] = min(E, p[0] - 1); // not buying first (waste p[0] -1 euros before walking)
    r[1] = E - p[0]; // buy first
    r[2] = max(r[1], r[0]) - p[1]; // buy second
    // insert your code here
    for(i  = 2; i <= N; i++ ){
        r[0] = min(max(r[0], r[i - 2]), p[i-1] - 1);
        r[i+1] = max(max(r[i], r[i-1]), r[0]) - p[i]; // max(buy i-1, buy i, waste euros of item i-1 and buy i)

    }

    printf("%d\n", r[N+1]); // change 42 with actual answer
    return 0;
}
