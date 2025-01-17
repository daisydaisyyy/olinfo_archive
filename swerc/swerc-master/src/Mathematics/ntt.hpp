#include <bits/stdc++.h>
#include "utility.hpp"

using namespace std;

using u64 = unsigned long long int;

// MUST BE TRUNCATED TO PAIRS WITH first < 2^32
//static vector<pair<u64, u64>> MAGIC = {{0ULL, 0ULL}, {3ULL, 2ULL}, {5ULL, 2ULL}, {17ULL, 3ULL}, {17ULL, 3ULL}, {97ULL, 5ULL}, {193ULL, 5ULL}, {257ULL, 3ULL}, {257ULL, 3ULL}, {7681ULL, 17ULL}, {12289ULL, 11ULL}, {12289ULL, 11ULL}, {12289ULL, 11ULL}, {40961ULL, 3ULL}, {65537ULL, 3ULL}, {65537ULL, 3ULL}, {65537ULL, 3ULL}, {786433ULL, 10ULL}, {786433ULL, 10ULL}, {5767169ULL, 3ULL}, {7340033ULL, 3ULL}, {23068673ULL, 3ULL}, {104857601ULL, 3ULL}, {167772161ULL, 3ULL}, {167772161ULL, 3ULL}, {167772161ULL, 3ULL}, {469762049ULL, 3ULL}, {2013265921ULL, 31ULL}, {3221225473ULL, 5ULL}, {3221225473ULL, 5ULL}, {3221225473ULL, 5ULL}, {75161927681ULL, 3ULL}, {77309411329ULL, 7ULL}, {77309411329ULL, 7ULL}, {206158430209ULL, 22ULL}, {206158430209ULL, 22ULL}, {206158430209ULL, 22ULL}, {2061584302081ULL, 7ULL}, {2748779069441ULL, 3ULL}, {2748779069441ULL, 3ULL}, {6597069766657ULL, 5ULL}, {6597069766657ULL, 5ULL}, {39582418599937ULL, 5ULL}, {79164837199873ULL, 5ULL}, {263882790666241ULL, 7ULL}, {1231453023109121ULL, 3ULL}, {1337006139375617ULL, 3ULL}, {3799912185593857ULL, 5ULL}, {4222124650659841ULL, 19ULL}, {7881299347898369ULL, 6ULL}, {7881299347898369ULL, 6ULL}, {31525197391593473ULL, 3ULL}, {31525197391593473ULL, 3ULL}, {180143985094819841ULL, 6ULL}, {180143985094819841ULL, 6ULL}, {180143985094819841ULL, 6ULL}, {1945555039024054273ULL, 5ULL}, {4179340454199820289ULL, 3ULL}, {15564440312192434177ULL, 5ULL}, {15564440312192434177ULL, 5ULL}};
static vector<pair<u64, u64>> MAGIC = {{0ULL, 0ULL}, {3ULL, 2ULL}, {5ULL, 2ULL}, {17ULL, 3ULL}, {17ULL, 3ULL}, {97ULL, 5ULL}, {193ULL, 5ULL}, {257ULL, 3ULL}, {257ULL, 3ULL}, {7681ULL, 17ULL}, {12289ULL, 11ULL}, {12289ULL, 11ULL}, {12289ULL, 11ULL}, {40961ULL, 3ULL}, {65537ULL, 3ULL}, {65537ULL, 3ULL}, {65537ULL, 3ULL}, {786433ULL, 10ULL}, {786433ULL, 10ULL}, {5767169ULL, 3ULL}, {7340033ULL, 3ULL}, {23068673ULL, 3ULL}, {104857601ULL, 3ULL}, {167772161ULL, 3ULL}, {167772161ULL, 3ULL}, {167772161ULL, 3ULL}, {469762049ULL, 3ULL}, {2013265921ULL, 31ULL}, {3221225473ULL, 5ULL}, {3221225473ULL, 5ULL}, {3221225473ULL, 5ULL}};

u64 fastexp(u64 b, u64 e, u64 m) {
    if(e == 0) {
        return 1;
    }
    u64 tmp = fastexp(b, e / 2, m);
    tmp *= tmp;
    tmp %= m;
    if(e % 2 == 1) {
        return (tmp * b) % m;
    } else {
        return tmp;
    }
}

bool is_pow2(u64 n) {
	return __builtin_popcount(n) == 1;
}

u64 next_pow2(u64 n) {
    u64 k = 1;
    while(k < n) k <<= 1;
    return k;
}

u64 bit_reverse(u64 x) {
    u64 c1 = 0x5555555555555555ULL;
    u64 c2 = 0x3333333333333333ULL;
    u64 c3 = 0x0F0F0F0F0F0F0F0FULL;
    u64 c4 = 0x00FF00FF00FF00FFULL;
    u64 c5 = 0x0000FFFF0000FFFFULL;
    x = ((x >> 1) & c1) | ( (x & c1) << 1);
    x = ((x >> 2) & c2) | ( (x & c2) << 2);
    x = ((x >> 4) & c3) | ( (x & c3) << 4);
    x = ((x >> 8) & c4) | ( (x & c4) << 8);
    x = ((x >>16) & c5) | ( (x & c5) <<16);
    x = ((x >>32)     ) | ( (x     ) <<32);
    return x;
}

pair<u64, u64> sel_magic(u64 n, u64 max_el) {
    u64 k = next_pow2(max_el+1);
    auto pri = upper_bound(MAGIC.begin()+(u64)log2(n)+1, MAGIC.end(), make_pair((n+1)*(k-1)*(k-1), 0ULL));
    assert(pri != MAGIC.end());
    return *pri;
}

void ntt(vector<u64>& v, bool inv=false, u64 max_el=1) {
    u64 n = v.size();
    assert(is_pow2(n));
    auto pri = sel_magic(n, max_el);
    u64 p = pri.first;
    u64 g = inv ? fastexp(pri.second, p - 2, p) : pri.second;
    u64 root = fastexp(g, (p - 1) / n, p); // n-th root of unity

    auto nlog = __builtin_ctzll(n);
    vector<u64> radix(nlog);
    for(u64 i = 0; i < n; i++) {
        u64 rev = bit_reverse(i) >> (64 - nlog);
        if(i < rev) {
            swap(v[i], v[rev]);
        }
    }
    radix[0] = root;
    for(u64 i = 1; i < nlog; i++) {
        radix[i] = (radix[i - 1] * radix[i - 1]) % p;
    }
    for(u64 s = 1; s <= nlog; s++) {
        u64 r = nlog - s, w = 1 << s;
        for(u64 i = 0; i < n; i += w) {
            u64 tf = 1;
            for(u64 j = i; j < i + w / 2; j++, tf = (tf * radix[r]) % p) {
                u64 t = (tf * v[j + w / 2]) % p;
                u64 u = v[j];
                v[j] = (u + t) % p;
                v[j + w / 2] = (u + (p - t)) % p;
            }
        }
    }

    if(inv) {
        u64 f = fastexp(n, p - 2, p);
        for(auto& x: v) x = (x * f) % p;
    }
}

vector<u64> mul(vector<u64>& a, vector<u64>& b, u64 base=2) {
    assert(a.size() == b.size());
    u64 max_el = base - 1;
    ntt(a, false, max_el);
    ntt(b, false, max_el);
    auto pri = sel_magic(a.size(), max_el);
    vector<u64> c(a.size());
    for(size_t i = 0; i < c.size(); ++i) {
       c[i] = (a[i] * b[i]) % pri.first;
    }
    ntt(c, true, max_el);
    return c;
}
