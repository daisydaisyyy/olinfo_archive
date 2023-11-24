/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include<vector>
#include<iostream>
// constraints
#define MAXN 1000000
using namespace std;
// input data
int N, K, i;
vector<int> T(MAXN);

int find_max() {
    int maxsum = 0;
    for(int i = 0; i < K; i++) maxsum += T[i];

    int currsum = maxsum;

    // calc all sums
    for(int i = K; i < N; i++) {
        currsum += T[i] - T[i - K];
        maxsum = max(maxsum, currsum);
    }

    return maxsum;
}


int main() {
//  uncomment the following lines if you want to read/write from files
    // freopen("muffin.input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &K));
    for (i = 0; i < N; i++)
        assert(1 == scanf("%d", &T[i]));

    // insert your code here

    printf("%d\n", find_max()); // change 42 with actual answer
    return 0;
}
