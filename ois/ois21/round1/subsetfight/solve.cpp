/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXK 100
#define MAXV 200000
constexpr int MOD = 1e9 + 7;
typedef long long ll;
// input data
int K, i;
int V[MAXK];

ll fast_exp(ll base, ll exp) {
	ll res = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			res = res * base % MOD;
		}
		base = base * base % MOD;
		exp /= 2;
	}
	return res;
}


int main() {
//  uncomment the following lines if you want to read/write from files
	freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &K));
    for(i=0; i<K; i++)
        assert(1 == scanf("%d", &V[i]));

    // insert your code here
	vector<ll> factorials(MAXV + 1, 1);
	vector<ll> inv_factorials(MAXV + 1, 1);
	for (int i = 1; i <= MAXV; i++) {
		factorials[i] = factorials[i - 1] * i % MOD;
		inv_factorials[i] = fast_exp(factorials[i], MOD - 2); // inverso modulare
	}

	vector<int> old_dp(K), new_dp(K), tmp_dp(K);
	old_dp[0] = 1;

	// calcola le sottocombinazioni di dimensione i per ogni seme
	for (int i = 1; i <= K; i++) {
		int amount = V[i-1];
		fill(tmp_dp.begin(), tmp_dp.end(), 0);
		fill(new_dp.begin(), new_dp.end(), 0);

		for(int c = 0; c <= amount; c++) {
			int v = (ll) c * i; // value of the subset of size i
			ll res = factorials[v] * inv_factorials[c] % MOD * inv_factorials[v - c] % MOD; // ways of the subset of size i
			tmp_dp[v] += res; tmp_dp[v] %= MOD;	
		}

		for(int start = 0; start < K; start++) {
			for(int seed = 0; seed < K; seed++) {
				new_dp[(start + seed) % K] += (ll) old_dp[start] * tmp_dp[seed] % MOD;
				new_dp[(start + seed) % K] %= MOD;
			}
		}
		swap(old_dp, new_dp);
	}
    
    printf("%d\n", old_dp[0]); // print the result
    return 0;
}
