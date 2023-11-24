/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// input data
int Emin, Emax;
int encode(int N) {
    
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Emin, &Emax));

    // insert your code here
    for (int E=Emin; E<=Emax; E++) {
        printf("%d\n", 42); // change 42 with actual answers
    }
    return 0;
}
