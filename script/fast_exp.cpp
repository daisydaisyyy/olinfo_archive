
// fast modular pow
ll fast_exp(ll base, ll exp) {
    ll res = 1; 
    for(; exp; exp >>= 1) { 
        if (exp & 1) res = (res * base) % MOD; 
        base = (base * base) % MOD;
    }
    return res;
}
