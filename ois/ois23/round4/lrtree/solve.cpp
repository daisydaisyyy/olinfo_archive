#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

// fast modular pow
ll fast_exp(ll base, ll exp) {
    ll res = 1; 
    for(; exp; exp >>= 1) { 
        if (exp & 1) res = (res * base) % MOD; 
        base = (base * base) % MOD;
    }
    return res;
}

int main() {
    // Uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    // strat: compute catalan number (see cp-alg) to find all possible confs
    ll cat_even = 1;
    
    // Iterate from k = 2 to k = N to compute C_N using the multiplicative formula:
    // C_N = (2N)! / (N! * (N+1)!) = product_{k=2}^{N} (N + k) / k , k: 2 -> N
    for(int k = 2; k <= N; k++) {
        cat_even = (cat_even * (N + k)) % MOD; 
        cat_even = (cat_even * fast_exp(k, MOD - 2)) % MOD;
    }

    // If N is odd, then we could have right children == left children 
    // Handle this case: 
    ll cat_odd = 1; 
    for(int k = 2; k <= (N / 2); k++) {
        cat_odd = (cat_odd * (N / 2 + k)) % MOD; 
        cat_odd = (cat_odd * fast_exp(k, MOD - 2)) % MOD;
    }
    
    // cout << cat_even << endl; // Remove or comment out to prevent extra output
    
    bool odd = N & 1; 
    ll final_cat; 
    if(odd)
        final_cat = (cat_even - cat_odd + MOD) % MOD; // subtract cat_odd to remove possibilities of right children == left ones 
    else 
        final_cat = cat_even; 

    ll inv = fast_exp(2, MOD - 2); // modular inverse of 2 with MOD 
    // divide by 2 to remove configurations where 
	// conf1 == mirrored conf2 
	// (where conf1 has lc > rc and conf2 rc > lc) -> remove conf2, we don't need it
    ll res = (final_cat * inv) % MOD;
    
    cout << res << endl;  // Print the result
    return 0;
}

