/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <assert.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
// constraints
#define MAXN 100000

// input data
int N, K, i;


int search_pos(int N, int K, int D[]) {
    sort(D, D + N);
    int best_pos = -1;
    int best_d = 0;
    for(int i = 0; i < N - 1; i++) {
        int cur_pos = (D[i] + D[i + 1]) / 2;
        int cur_d = min(cur_pos - D[i], D[i + 1] - cur_pos);
        if (cur_d > best_d) {
            best_d = cur_d;
            best_pos = cur_pos;
        }
    }

    if (D[0] > best_d)   {
        best_pos = 0;
        best_d = D[0];
    }

    if (K - D[N - 1] > best_d)   {
        best_pos = K;
        best_d = K - D[N - 1];
    }

    assert(0 <= best_pos <= K);
    return best_pos;
}

int D[MAXN];
int main() {
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input0.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    ifstream cin("input0.txt");
    cin >> N;
    cin >> K;
    // assert(2 == scanf("%d %d", &N, &K));
    for (i = 0; i < N; i++)    cin >> D[i];
    
    //assert(1 == scanf("%d", &d[i]));

    // insert your code here
    // prendo max distanza tra 2 malls, faccio/2 arrotondando per eccesso
    cout << search_pos(N, K, D) << endl;

    // printf("%d\n", 42);  // change 42 with actual answer
    return 0;
}
