#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct max_item {
    long long seg, pref, suf, sum;
};

struct segtree {
    int size;
    vector<max_item> max_seg_even;
    vector<max_item> max_seg_odd;
    max_item MAX_NEUTRAL = {0, 0, 0, 0};

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        max_seg_even.resize(2 * size);
        max_seg_odd.resize(2 * size);
    }

    void build(vector<int> &V, vector<max_item> &max_seg, int nodo, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < V.size()) {
                max_seg[nodo] = max_single(V[lx]);
            }
            return;
        }

        int middle = (lx + rx) / 2;
        build(V, max_seg, 2 * nodo + 1, lx, middle);
        build(V, max_seg, 2 * nodo + 2, middle, rx);
        max_seg[nodo] = max_merge(max_seg[2 * nodo + 1], max_seg[2 * nodo + 2]);
    }

    void build(vector<int> &V, vector<max_item> &max_seg) {
        build(V, max_seg, 0, 0, size);
    }

    max_item max_merge(max_item a, max_item b) {
        return {
            max(a.seg, max(b.seg, a.suf + b.pref)),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
    }

    max_item max_single(int v) {
        if(v > 0)
            return {v, v, v, v};
        return {0, 0, 0, v};
    }

    void set_even(int i, int v, int nodo, int lx, int rx) {
        if(rx - lx == 1) {
            max_seg_even[nodo] = max_single(v);
            return;
        }

        int middle = (lx + rx) / 2;
        if(i < middle) {
            set_even(i, v, 2 * nodo + 1, lx, middle);
        } else {
            set_even(i, v, 2 * nodo + 2, middle, rx);
        }

        max_seg_even[nodo] = max_merge(max_seg_even[2 * nodo + 1], max_seg_even[2 * nodo + 2]);
    }

    void set_even(int i, int v) {
        set_even(i, v, 0, 0, size);
    }

    void set_odd(int i, int v, int nodo, int lx, int rx) {
        if(rx - lx == 1) {
            max_seg_odd[nodo] = max_single(v);
            return;
        }

        int middle = (lx + rx) / 2;
        if(i < middle) {
            set_odd(i, v, 2 * nodo + 1, lx, middle);
        } else {
            set_odd(i, v, 2 * nodo + 2, middle, rx);
        }

        max_seg_odd[nodo] = max_merge(max_seg_odd[2 * nodo + 1], max_seg_odd[2 * nodo + 2]);
    }

    void set_odd(int i, int v) {
        set_odd(i, v, 0, 0, size);
    }

    max_item max_segment_even(int l, int r, int nodo, int lx, int rx) {
        if(lx >= r || l >= rx) return MAX_NEUTRAL;
        if(lx >= l && rx <= r) return max_seg_even[nodo];
        int middle = (lx + rx) / 2;

        max_item sinistra = max_segment_even(l, r, 2 * nodo + 1, lx, middle);
        max_item destra = max_segment_even(l, r, 2 * nodo + 2, middle, rx);
        return max_merge(sinistra, destra);
    }

    max_item max_segment_even(int l, int r) {
        return max_segment_even(l, r, 0, 0, size);
    }

    max_item max_segment_odd(int l, int r, int nodo, int lx, int rx) {
        if(lx >= r || l >= rx) return MAX_NEUTRAL;
        if(lx >= l && rx <= r) return max_seg_odd[nodo];
        int middle = (lx + rx) / 2;

        max_item sinistra = max_segment_odd(l, r, 2 * nodo + 1, lx, middle);
        max_item destra = max_segment_odd(l, r, 2 * nodo + 2, middle, rx);
        return max_merge(sinistra, destra);
    }

    max_item max_segment_odd(int l, int r) {
        return max_segment_odd(l, r, 0, 0, size);
    }
};

int main() {
    int N, q;
    ifstream cin("input0.txt");
	cin>>N>>q;

    segtree st;
    st.init(N);

    vector<int> V(N);
    vector<int> V1(N);
    for(int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if(i % 2 == 1) {V[i] = -x; V1[i] = x;}
        else {V[i] = x; V1[i] = -x;}
    }

    st.build(V, st.max_seg_even);
    st.build(V1, st.max_seg_odd);

    // 5 9 1 2 8 4 6 4 2 8

    while(q--) {
        int op;
        cin>>op;
        if(op == 1) {
            int i, v;
            cin>>i>>v;
            --i;
            if(i % 2 == 1) v = -v;
            st.set_even(i, v);
            st.set_odd(i, -v);
        } else {
            int l, r;
            cin>>l>>r;
            --l;
            cout << max(st.max_segment_odd(l, r).seg, st.max_segment_even(l, r).seg) << '\n';
        }
    }
    return 0;
}
