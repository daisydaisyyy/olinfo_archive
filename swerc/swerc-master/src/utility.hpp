#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    for(size_t i = 0; i < v.size(); i++) {
        o << v[i];
        if(i != v.size() - 1) {
            o << ", ";
        }
    }
    o << "]";
    return o;
}

template<typename T>
ostream& operator<<(ostream& o, const unordered_set<T>& s) {
    o << "{";
    auto it = s.begin();
    for(size_t i = 0; i < s.size(); i++, ++it) {
        o << *it;
        if(i != s.size() - 1) {
            o << ", ";
        }
    }
    o << "}";
    return o;
}

template<typename T>
vector<vector<T>> transpose_adj(const vector<vector<T>>& adj) {
    T n_trans = T(0);
    for(const auto& v: adj) {
        n_trans = max(n_trans, *max_element(v.begin(), v.end()) + 1);
    }
    vector<vector<T>> adjT(n_trans);
    for(size_t i = 0; i < adj.size(); i++) {
        for(const auto& j: adj[i]) {
            adjT[j].push_back(i);
        }
    }
    return adjT;
}
