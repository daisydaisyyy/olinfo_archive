/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000
#define MAXM 1000000

// input data
int N, M, i;
int A[MAXM], B[MAXM];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == scanf("%d %d", &A[i], &B[i]));

    // insert your code here
    
    printf("%d\n", 42); // change 42 with actual answer
    return 0;
}
