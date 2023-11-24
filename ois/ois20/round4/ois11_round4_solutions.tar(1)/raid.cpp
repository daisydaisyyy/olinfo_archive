/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

// constraints
#define MAXN 100000

// input data
int N, P, i;
int H[MAXN];

bool can_destroy(int i) {
    if (i == 0) {
        return (N == 1 || H[0] > H[1]);
    } else if (i == N-1) {
        return H[N-1] > H[N-2];
    } else {
        return (H[i] > H[i-1]) && (H[i] > H[i+1]);
    }
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &P));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &H[i]));

    vector<int> next;
    for (int i = 0; i < N; i++) {
        if (can_destroy(i)) {
            next.push_back(i);
        }
    }

    for (int p = 0; p < P; p++) {
        vector<int> following;
        for (int i : next) {
            H[i] = 0;
            if (i > 0 && can_destroy(i-1)) {
                following.push_back(i-1);
            }
            if (i < N-1 && can_destroy(i+1)) {
                following.push_back(i+1);
            }
        }

        next = following;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] == 0) {
            count++;
        }
    }
    
    printf("%d\n", count); // print the result
    return 0;
}
