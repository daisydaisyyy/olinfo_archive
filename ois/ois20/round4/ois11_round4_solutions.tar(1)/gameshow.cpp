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
int N, M, i;
int P[MAXN], C[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &P[i]));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));

    // insert your code here
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (M >= P[i]) {
            count++;
            M -= P[i];
        } else {
            M += C[i];
        }
    }
    
    printf("%d %d\n", count, M); // print the result
    return 0;
}
