/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXP 150000

// input data
int N, P, i;
int X[MAXP], Y[MAXP], R[MAXP];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &P));
    for(i=0; i<P; i++)
        assert(3 == scanf("%d %d %d", &X[i], &Y[i], &R[i]));

    // insert your code here

    printf("%d\n", 42); // print the result
    return 0;
}
