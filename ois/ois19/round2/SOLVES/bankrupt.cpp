// Scan the area from left to right, considering only existing x-values.
// Since the perimeter is given clockwise, "upwards" sides are opening a
// new area, while "downwards" sides are closing one.
// Thus I keep updated the "span" by summing the sides as I encounter them.

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

// constraints
#define MAXN 1024000

using namespace std;

// input data
int N, i;
int X[MAXN], Y[MAXN];
vector<pair<int,int>> verticals; // vertical segments by X and dY (with sign)

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    
    assert(1 == scanf("%d", &N));
    for (i=0; i<N; i++)
        assert(2 == scanf("%d %d", &X[i], &Y[i]));
    X[N] = X[0];
    Y[N] = Y[0];
    i = X[0] == X[1] ? 0 : 1;
    verticals.emplace_back(-1, 0);
    for (; i<N; i+=2)
        verticals.emplace_back(X[i], Y[i+1]-Y[i]);
    sort(verticals.begin(), verticals.end());

    long long span = 0; // the current vertical span of the polygon
    long long area = 0; // the area of the polygon
    for (i=0; i<N/2; i++) {
        area += (verticals[i+1].first - verticals[i].first) * span; // use old span until now
        span += verticals[i+1].second; // update span with new vertical segment
        assert(span >= 0);
    }
    assert(span == 0); // at the end, there should be no more vertical span
    
    printf("%lld\n", area);
    return 0;
}
