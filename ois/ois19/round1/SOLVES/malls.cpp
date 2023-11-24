// sort the input: the best position is always at the extremes (beginning, end) or in the middle of two consecutive malls
#include <assert.h>
#include <stdio.h>
#include <algorithm>

#define MAXN 100000

using namespace std;

int advise(int N, int K, int D[]) {
    sort(D, D + N);
    int best_pos = -1;
    int best_dist = 0;
    for (int i = 0; i < N - 1; i++) {
        int cur_pos = (D[i] + D[i + 1]) / 2;
        int cur_dist = min(cur_pos - D[i], D[i + 1] - cur_pos);
        if (cur_dist > best_dist) {
            best_dist = cur_dist;
            best_pos = cur_pos;
        }
    }
    if (D[0] > best_dist) {
        best_pos = 0;
        best_dist = D[0];
    }
    if (K - D[N - 1] > best_dist) {
        best_pos = K;
        best_dist = K - D[N - 1];
    }

    assert(0 <= best_pos <= K);

    return best_pos;
}

int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = stdin;
    fw = stdout;
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for (i = 0; i < N; i++) assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", advise(N, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
