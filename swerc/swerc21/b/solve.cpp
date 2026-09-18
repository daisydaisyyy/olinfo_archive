#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
vector<int> T;
vector<int> a;
void solve(int kick, int pos, int watched, bool skip)
{
    if (dp[kick] == -1)
        return;
    //let skip = solve(kick + 1, )
}

int main()
{
    int n, v;
    cin >> n >> v;

    dp.resize(n);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        T.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
        dp.push_back(-1);
}