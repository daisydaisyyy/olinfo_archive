/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints

// input data
int H0, M0, H1, M1;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(4 == scanf("%d%d%d%d", &H0, &M0, &H1, &M1));

    // insert your code here
    int start = H0*60 + M0;
    int end = H1*60 + M1;
    int delta = (end > start ? end-start : 24*60 - start + end);

    printf("%d %d\n", delta/60, delta%60); // print the result
    return 0;
}
