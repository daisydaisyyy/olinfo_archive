// @check-accepted: task

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

const int maxn = 1e5;
int n, k;
pair <int, int> a[maxn];

bool check(int x)
{
	multiset <int> s;

	int rem = 0;
	for (int i = 0; i < n; i++)
	{
		if ((int)s.size() == 0 || (*s.begin()) >= a[i].first)
			s.insert(a[i].second);
		else
		{
			multiset <int> :: iterator it = s.lower_bound(a[i].first);
			it--;

			s.erase(it);
			s.insert(a[i].second);
		}

		if ((int)s.size() > x)
		{
			multiset <int> :: iterator it = s.end();
			it--;

			s.erase(it);
			rem++;
		}

	}

	return (rem <= k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a, a + n);

	int lo = 0, hi = n;
	while (hi - lo > 1)
	{
		int mid = (lo + hi) >> 1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}

	cout << hi << '\n';

	return 0;
}
