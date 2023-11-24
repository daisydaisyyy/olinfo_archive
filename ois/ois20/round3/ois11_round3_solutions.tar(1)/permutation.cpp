/// O(N * logN)

#include <cstdio>
#include <vector>

//FILE *fin = fopen("bonus3.in", "r"), *fout = fopen("bonus3.out", "w");

std::vector < int > aib;

inline void update(int p) {
    while (p < (int)aib.size()) {
        aib[p]++;
        p += p & (-p);
    }
}

inline int query(int p) {
    int ans = 0;
    while (p) {
        ans += aib[p];
        p -= p & (-p);
    }
    return ans;
}

inline void solve() {
    int n;
    scanf("%d", &n);

    std::vector < int > v(n);
    for (auto &x : v)
        scanf("%d", &x);
    std::vector < int > p(n + 1);
    for (int i = 0; i < n; i++)
        p[v[i]] = i;

    int ans = 0;
    aib.clear();
    aib.resize(n + 1);
    for (int i = 0; i < n; i++) {
        ans += i - query(v[i]);
        update(v[i]);
    }

    int acum = ans;
    for (int i = 1; i < n; i++) {
        acum += 2 * p[n - i + 1] - n + 1;
        if (acum < ans)
            ans = acum;
    }

    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);

    for (; t; t--)
        solve();

//    fclose(fin);
//    fclose(fout);
    return 0;
}
