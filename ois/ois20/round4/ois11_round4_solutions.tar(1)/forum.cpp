/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

// constraints
#define MAXD 500000
#define MAXP 500000
#define MAXE 500000

// input data
int D, P, E, i;
int A[MAXD+MAXP];
int T[MAXE], id[MAXE];
vector<vector<int>> adj;
vector<int> left, right;

int t = 0;
void calc_times(int u) {
    left[u] = t++;
    for (int v : adj[u]) {
        calc_times(v);
    }
    right[u] = t-1;
}

vector<int> st;

void propagate(int id) {
    if (st[id] != 0) {
        st[id*2] = st[id*2+1] = st[id];
    }
    st[id] = 0;
}

void update(bool active, int b, int e, int l = 0, int r = D+P-1, int id=1) {
    if (e < l || b > r)
        return;
    if (l >= b && r <= e) {
        if (active) {
            st[id] = 1;
        } else {
            st[id] = -1;
        }
        return;
    }
    propagate(id);
    update(active, b, e, l, (l+r)/2, id*2);
    update(active, b, e, (l+r)/2+1, r, id*2+1);
}

int get(int v, int l = 0, int r = D+P-1, int id = 1) {
    if (l == r) {
        return st[id];
    }

    propagate(id);
    if (v <= (l+r)/2) {
        return get(v, l, (l+r)/2, id*2);
    }
    return get(v, (l+r)/2+1, r, id*2+1);
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d%d%d", &D, &P, &E));
    for(i=0; i<D+P; i++)
        assert(1 == scanf("%d", &A[i]));
    for(i=0; i<E; i++)
        assert(2 == scanf("%d%d", &T[i], &id[i]));

    adj.resize(D+P);
    for (int i = 1; i < D+P; i++) {
        adj[A[i]].push_back(i);
    }

    left.resize(D+P);
    right.resize(D+P);

    calc_times(0);

    st.assign(4*(D+P), -1);

//    for (int i = 0; i < D+P; i++) {
//        printf("%d: %d %d\n", i, left[i], right[i]);
//    }

    for (int i = 0; i < E; ++i) {
        if (T[i] == 2) {
            int res = get(left[id[i]]);
            printf("%d\n", (res == -1 ? 0 : 1));
        } else {
            update((T[i] == 0 ? false : true), left[id[i]], right[id[i]]);
        }

//        for (int i = 1; i < st.size(); i++) {
//            printf("%d ", st[i]);
//        }
//        puts("");
    }

    return 0;
}
