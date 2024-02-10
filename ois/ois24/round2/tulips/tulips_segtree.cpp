#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

/*
dp with segment tree:
segment tree structure: https://cp-algorithms.com/data_structures/segment_tree.html

can answer to finding the sum of consecutive array elements  
[l ... r] , 
or finding the minimum element in a such a range in  O(log n)  time. 
Between answering such queries, the Segment Tree allows 
modifying the array by replacing one element, or even changing the elements 
of a whole subsegment (e.g. assigning all elements 
 a[l ... r] to any value, or adding a value to all element in the subsegment)

*/


void build(vector<int>& a, vector<int>& tree, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, tree, v*2, tl, tm);
        build(a, tree, v*2+1, tm+1, tr);
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }
}


// l = left, r = right of interval
int queryMin(vector<int>& tree, int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return INT_MAX;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return min(queryMin(tree, v*2, tl, tm, l, min(r, tm)),
               queryMin(tree, v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    int N, K;
    // ifstream cin("input1.txt");
    cin >> N >> K;
    
    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];
    
    // build segment tree to find min 
    vector<int> segTree(4*N);
    build(T, segTree, 1, 0, N-1);

    vector<vector<long long>> dp(N+1, vector<long long>(K+1, LLONG_MIN));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= K; ++k) {
            for (int j = 0; j < i; ++j) {
                int minB = queryMin(segTree, 1, 0, N-1, j, i-1); // find min in [j, i-1] 
                dp[i][k] = max(dp[i][k], dp[j][k-1] + minB); // start a new boquet or take tulip 
            }
        }
    }

    cout << dp[N][K] << endl;


    return 0;
}
