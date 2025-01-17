#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

// Fast exponentiation
ll power_mod(ll a, ll b, ll mod_val) {
    ll res = 1;
    a %= mod_val;
    while(b > 0){
        if(b & 1){
            res = res * a % mod_val;
        }
        a = a * a % mod_val;
        b >>= 1;
    }
    return res;
}

// Disjoint Set Union (Union-Find)
struct DSU {
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int find_set(int x){
        if(parent[x] != x){
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }
    void union_set(int x, int y){
        int fx = find_set(x);
        int fy = find_set(y);
        if(fx != fy){
            parent[fx] = fy;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll R, C, N;
    cin >> R >> C >> N;
    struct Cell {
        ll r;
        ll c;
    };
    vector<Cell> cells(N);
    for(int i=0;i<N;i++) cin >> cells[i].r >> cells[i].c;
    
    // Collect unique rows, columns, d1, d2
    vector<ll> rows, columns, d1_list, d2_list;
    rows.reserve(N);
    columns.reserve(N);
    d1_list.reserve(N);
    d2_list.reserve(N);
    for(auto &[r, c] : cells){
        rows.push_back(r);
        columns.push_back(c);
        d1_list.push_back(r - c);
        d2_list.push_back(r + c);
    }
    
    // Sort and remove duplicates
    sort(rows.begin(), rows.end());
    rows.erase(unique(rows.begin(), rows.end()), rows.end());
    
    sort(columns.begin(), columns.end());
    columns.erase(unique(columns.begin(), columns.end()), columns.end());
    
    sort(d1_list.begin(), d1_list.end());
    d1_list.erase(unique(d1_list.begin(), d1_list.end()), d1_list.end());
    
    sort(d2_list.begin(), d2_list.end());
    d2_list.erase(unique(d2_list.begin(), d2_list.end()), d2_list.end());
    
    // Assign unique IDs
    // row IDs: 0 to rows.size()-1
    // column IDs: rows.size() to rows.size() + columns.size()-1
    // d1 IDs: rows.size() + columns.size() to rows.size() + columns.size() + d1_list.size()-1
    // d2 IDs: rows.size() + columns.size() + d1_list.size() to total-1
    ll row_offset = 0;
    ll column_offset = rows.size();
    ll d1_offset = column_offset + columns.size();
    ll d2_offset = d1_offset + d1_list.size();
    ll total_entities = d2_offset + d2_list.size();
    
    // Function to get ID for a row
    auto get_row_id = [&](ll r) -> int {
        return lower_bound(rows.begin(), rows.end(), r) - rows.begin() + row_offset;
    };
    // Function to get ID for a column
    auto get_column_id = [&](ll c) -> int {
        return lower_bound(columns.begin(), columns.end(), c) - columns.begin() + column_offset;
    };
    // Function to get ID for d1
    auto get_d1_id = [&](ll d1) -> int {
        return lower_bound(d1_list.begin(), d1_list.end(), d1) - d1_list.begin() + d1_offset;
    };
    // Function to get ID for d2
    auto get_d2_id = [&](ll d2) -> int {
        return lower_bound(d2_list.begin(), d2_list.end(), d2) - d2_list.begin() + d2_offset;
    };
    
    // Initialize DSU
    DSU dsu(total_entities);
    
    // For each cell, connect row, column, d1, d2
    for(int i=0;i<N;i++){
        ll r = cells[i].r;
        ll c = cells[i].c;
        ll d1 = r - c;
        ll d2 = r + c;
        int row_id = get_row_id(r);
        int column_id = get_column_id(c);
        int d1_id = get_d1_id(d1);
        int d2_id = get_d2_id(d2);
        
        // Connect row with column, row with d1, row with d2
        dsu.union_set(row_id, column_id);
        dsu.union_set(row_id, d1_id);
        dsu.union_set(row_id, d2_id);
    }
    
    // Count the number of unique parents
    unordered_set<int> parents;
    for(int i=0;i<total_entities;i++){
        parents.insert(dsu.find_set(i));
    }
    
    // The number of connected components is the number of unique parents
    ll k = parents.size();
    
    // Compute 2^k mod MOD
    ll answer = power_mod(2, k, MOD);
    
    cout << answer;
}

