int N, M, C_0, a, b, c, i;
int P[MAXN];
vector<pair<int, int>> adj[MAXN];
int main()
{
  assert(3 == scanf("%d %d %d", &N, &M, &C_0));
  for (i = 0; i < N; i++)
  {
    assert(1 == scanf("%d", &P[i]));
  }
  for (i = 0; i < M; i++)
  {
    assert(3 == scanf("%d %d %d", &a, &b, &c));
    adj[a].push_back({b, c});
  }

  adj[N - 1].push_back({N, 0});

  vector<vector<int>> dist(N + 1, vector<int>(MAXC, 2e9));
  priority_queue<tuple<int, int, int>> q;
  vector<vector<bool>> visited(N + 1, vector<bool>(MAXC, false));

  q.push({0, 0, C_0});
  dist[0][C_0] = 0;

  while (!q.empty())
  {
    auto [cost, source, curr_coins] = q.top();
    q.pop();

    if (visited[source][curr_coins])
      continue;
    visited[source][curr_coins] = true;
    cost *= -1;

    for (auto [dest, coins] : adj[source])
    {
      for (int hint = 0; hint <= curr_coins; hint++)
      {
        int new_dist = max(cost, P[source] >> hint); // take the puzzle or cost / 2 spending a coin
        int new_coins = curr_coins - hint + coins;

        if (new_dist < dist[dest][new_coins])
        {
          dist[dest][new_coins] = new_dist;
          q.push({-new_dist, dest, new_coins});
        }
      }
    }
  }
  printf("%d\n", *min_element(dist[N].begin(), dist[N].end())); // print the result
  return 0;
}
