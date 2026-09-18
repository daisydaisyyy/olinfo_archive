#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> shops;
int main()
{
    int m, n, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        shops.push_back(x);
    }

    vector<pair<int, int>> intervals;
    int next = 0, prev = 0, huts = 0, i = 1;
    intervals.push_back({0, shops[0]});
    while (i < n && next < m && prev < m)
    {
        // next
        if (i > shops[next] && next < m-1)
        {
            prev = next;
            next++;
        }

        int res;
        if (next < m)
        {
            int dist_next = shops[next] - huts;
            int dist_prev = huts - shops[prev];
            res = min(dist_next, dist_prev);
        }
        else
            res =  huts - shops[prev];
        intervals.push_back({huts - res, huts + res});
        huts += 100;
        i++;
    }
}
