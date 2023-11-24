// Complexity: O(N log N).
// Notice that D can be removed, by artificially modifying L[] and P[]
// to include its effect.
// Compute sending[] time of the message from left to right.
// Maintain a set of maximal antennas so far: antennas sending later
// with a lower power are not included.

#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <iterator>
#include <set>

// constraints
#define INF  2000000000
#define MAXN 100000

using namespace std;

// input data
int N, D;
int L[MAXN], P[MAXN], S[MAXN], T[MAXN], sending[MAXN];

set<pair<int,int>> incoming; // stores pairs (P[i],sending[i])

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &D));
    for (int i=0; i<N; i++) {
        assert(4 == scanf("%d %d %d %d", &L[i], &P[i], &S[i], &T[i]));
        L[i] += D*i;
        P[i] += D*i;
        sending[i] = INF;
    }
    
    sending[0] = S[0];
    incoming.emplace(P[0],sending[0]);
    for (int i=1; i<N; ++i) {
        auto it = incoming.upper_bound({L[i],-1}); // best with power above threshold
        if (it == incoming.end()) continue; // no message received
        int best = it->second; // when first message received
        sending[i] = S[i] + T[i] * ((best-S[i]+T[i])/T[i]); // first sending after receive
        it = incoming.upper_bound({P[i],-1}); // first with not lower power
        if (it != incoming.end() and it->second <= sending[i]) continue; // current is not interesting
        if (it != incoming.begin() or it->first == P[i]) {
            if (it == incoming.end() or it->first > P[i]) --it; // last with not greater power
            while (it->second >= sending[i]) { // if worse than current
                it = incoming.erase(it); // erase it
                if (it == incoming.begin()) break;
                else --it;
            }
        }
        incoming.emplace(P[i], sending[i]); // add the current to the incoming messages
    }
    
    printf("%d\n", sending[N-1] == INF ? -1 : sending[N-1]); // print the result
    return 0;
}
