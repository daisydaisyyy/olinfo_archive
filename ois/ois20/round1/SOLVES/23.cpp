/*
	Autor:         Moroianu
	Solutie:       100p
	Complexitate:  O(NMAX + T) Timp si O(sqrt(NMAX)) memorie
*/
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
namespace Solver {
	int pmax2, pmax3;
	const int VMAX = 100000000;
 
	vector <int> Solver(vector <int> q) {
		vector <pair <int, int>> sorted;
	
		for (int i = 0; i < q.size(); i++)
			sorted.push_back({ q[i], i });
		
		sort(sorted.begin(), sorted.end());
 
		pmax2 = 1, pmax3 = 1;
 
		while (pmax2 * pmax2 < VMAX)
			pmax2 *= 2;
		while (pmax3 * pmax3 < VMAX)
			pmax3 *= 3;
 
		vector <int> pop2(pmax2 + 1), pop3(pmax3 + 1);
		for (int i = 1; i <= pmax2; i++)
			pop2[i] = (i & 1) + pop2[i / 2];
		for (int i = 1; i <= pmax3; i++)
			pop3[i] = i % 3 + pop3[i / 3];
 
		vector <pair <int, int>> ans;
		int last = 0, act = 0;
 
		for (auto i : sorted) {
			/// ma duc pana la i.first
			while (last < i.first) {
				last++;
				int p2 = pop2[last % pmax2] + pop2[last / pmax2];
				int p3 = pop3[last % pmax3] + pop3[last / pmax3];
				if (p2 == p3)
					act++;
			}
 
			ans.push_back({ i.second, act });
		}
 
		sort(ans.begin(), ans.end());
 
		vector <int> r(ans.size());
		for (int i = 0; i < r.size(); i++)
			r[i] = ans[i].second;
		return r;
	}
}
 
int main()
{
//	ifstream in("23.in");
//	ofstream out("23.out");
 
	int t;
	cin >> t;
 
	vector <int> v(t);
 
	for (auto& i : v)
		cin >> i;
 
	auto ans = Solver::Solver(v);
	string add = "";
 
	for (auto i : ans)
		cout << add << i, add = " ";
	cout << '\n';
 
	return 0;
}
