// consider dishes by H decreasing, and put each dish on the stove that allows it to finish earlier

#include <assert.h>
#include <stdio.h>
#include <algorithm>

// constraints
#define MAXN 10000
#define MAXM 10000

using namespace std;

// input data
int N, M, i, value = 0;
pair<int,int> H[MAXN];
int T[MAXM], TC[MAXM], P[MAXN]; // TC[i]: current time spent on stove i, P[i]: stove assigned to dish i


int main() {
    assert(2 == scanf("%d%d", &N, &M));
    for (i = 0; i < N; i++) {
        assert(1 == scanf("%d", &H[i].first));
        H[i].second = i;
    }
    sort(H, H+N);
    for (i = 0; i < M; i++)
        assert(1 == scanf("%d", &T[i]));

    // for each dish, in increasing order of H
    for (int dish = N-1; dish >= 0; dish--) {
        // find the stove that allows to finish earlier
        int stove=-1, end=1000000000;
        for (int j=0; j<M; j++) {
            int tmp = TC[j] + H[dish].first * T[j];
            if (tmp < end) stove=j, end=tmp;
        }
        P[H[dish].second] = stove;
        TC[stove] = end;
        value = max(value, end);
    }
    printf("%d\n", value);
    for (i = 0; i < N; i++) printf("%d ", P[i]);
    printf("\n");
    return 0;
}
