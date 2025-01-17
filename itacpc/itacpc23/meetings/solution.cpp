// @check-accepted: task

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ii = pair<int,int>;

int test(const vector<ii> &m, int c) {
    set<ii> active;
    int del = 0;

    for(int i = 0; i < m.size(); ++i) {
        while(!active.empty() && active.begin()->first < m[i].first) active.erase(active.begin());
        active.insert(ii(m[i].second, i));
        if(active.size() > c) {
            active.erase(prev(active.end()));
            ++del;
        }
    }

    return del;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ii> m(N);
    for(ii &x: m) cin >> x.first >> x.second;

    sort(m.begin(), m.end());

    int lb = 0, ub = N;
    while(lb < ub) {
        int mid = (lb + ub) / 2;
        if(test(m, mid) <= K) {
            ub = mid;
        } else {
            lb = mid + 1;
        }
    }

    cout << lb << "\n";

    return 0;
}
