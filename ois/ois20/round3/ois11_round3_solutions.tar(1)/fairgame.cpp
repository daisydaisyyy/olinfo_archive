/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <deque>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = 1'000'000'000'000'000'000L;

// input data
int N, K, M, P, Q;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(5 == scanf("%d%d%d%d%d", &N, &K, &M, &P, &Q));

    deque<pair<int, ll>> A, B;
    A.emplace_back(0, Q-P);
    for (int i = 1; i <= N; i++) {
        while (!A.empty() && A.front().first+K < i) A.pop_front();
        while (!B.empty() && B.front().first+K < i) B.pop_front();

        ll best = -INF;
        if (!A.empty()) {
            best = max(best, -A.front().second - (i&1) * M);
        }

        if (!B.empty()) {
            best = max(best, -B.front().second - (1 - (i&1)) * M);
        }

        if (i&1) {
            while (!B.empty() && B.back().second >= best) B.pop_back();
            B.emplace_back(i, best);
        } else {
            while (!A.empty() && A.back().second >= best) A.pop_back();
            A.emplace_back(i, best);
        }
    }

    // insert your code here

    printf("%lld\n", ((N&1) ? B.back().second : A.back().second)); // print the result
    return 0;
}
