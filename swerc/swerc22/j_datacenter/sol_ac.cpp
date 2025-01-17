#include <bits/stdc++.h>

using namespace std;
#define MAXN 105
#define F first
#define S second
typedef pair<int, int> pii;
typedef pair<int, pii> node;

int n, m, k;
int diam;
int c[MAXN];
int vis[MAXN][2];
vector<int> nei[MAXN];

int dist(int odd, int even) {
  if (even == -1 || odd == -1)
    return max(even + k, odd + k);
  int mx = min(odd + k, even);
  for (int i = 0; i <= k; i++)
    mx = max(mx, min(odd + k - i, even + i));
  return mx;
}

void calc(int ini) {
  queue<node> q;
  q.push(node(ini, pii(0, 0)));

  for (int i = 0; i < n; i++)
    vis[i][0] = vis[i][1] = -1;

  while (!q.empty()) {
    node nx = q.front();
    q.pop();

    int cr = nx.F;
    int dis = nx.S.F;
    int par = nx.S.S;

    if (vis[cr][par] != -1 && vis[cr][par] <= dis)
      continue;

    vis[cr][par] = dis;

    for (int i = 0; i < int(nei[cr].size()); i++) {
      int ncr = nei[cr][i];
      int ndis = dis + 1;
      int npar = (par + (c[cr] != c[ncr])) % 2;

      if (vis[ncr][npar] != -1 && vis[ncr][npar] <= ndis)
	continue;
      q.push(node(ncr, pii(ndis, npar)));
    }
  }

  for (int i = 0; i < n; i++)
    diam = max(diam, dist(vis[i][0], vis[i][1]));
}

int main() {
  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < n; i++)
    scanf("%d", &c[i]);

  int a, b;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    a--, b--;
    nei[a].push_back(b);
    nei[b].push_back(a);
  }

  diam = 0;
  for (int i = 0; i < n; i++)
    calc(i);

  printf("%d\n", diam);
  
  return 0;
}
