// Notice that when a person reaches the exit, all its descendants
// become contenders for the exit together with the existing contenders.
// Complexity: O(N log N).

#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include <queue>
#include <vector>

// constraints
#define MAXN 1000000

using namespace std;

// input data
int N, i, c;
int E[MAXN], A[MAXN];

priority_queue<pair<int,int>> Q;
vector<int> adj[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &E[i])); // evacuation directions
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &A[i])); // arrogance

    for (int i=0; i<N; i++)
        if (E[i] < 0) Q.emplace(A[i], i);
        else adj[E[i]].push_back(i);
    while (not Q.empty()) {
        c++;
        int top = Q.top().second;
        printf("%d ", top);
        Q.pop();
        for (int i : adj[top]) Q.emplace(A[i], i);
    }
    printf("\n");
    assert(c == N);
    return 0;
}
