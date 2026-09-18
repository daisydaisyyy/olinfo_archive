#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> A;
ll n, k;
vector<vector<ll>> dp;

// 2 3 5 6

ll solve(ll idx, ll used, ll power) {
    if(idx == n) return 0;
    if(used == 0) return power;

    dp[idx][1] = solve(idx+1, used-1, power + (A[n - 1 - idx] - A[idx])); // first to last
    dp[idx][0] = solve(idx+1, used-1, power + (A[idx] - A[n - 1 - idx])); // last to first
    cout << idx << " "  << n - 1 - idx << " " << used << " " << power << " " << dp[idx][0] << " " << dp[idx][1] << endl;
    return max(dp[idx][0], dp[idx][1]);
}


int main() {
    cin >> n >> k;
    ll x;
    for(int i = 0; i  < n; i++) {
        cin >> x;
        A.push_back(x);
    }

    dp.assign(n, vector<long long>(2 + 1, -1));

    sort(A.begin(), A.end());
    cout << solve(0,k,0) << endl;


}

/*
5 3 2
2 3 5

*/