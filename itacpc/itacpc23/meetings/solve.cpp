#include<bits/stdc++.h>
using namespace std;

//typedef pair<int,int> ii; 
using ii = pair<int,int>;
int solve(const vector<ii> &m, int mid) {
	set<ii> active;
	int deleted = 0;
	for(int i = 0; i < m.size();++i) {
		// if overlapping, delete it 
		while(!active.empty() and active.begin() -> first < m[i].first) active.erase(active.begin());
		active.insert({m[i].second,i}); // insert current end time and idx
		// too many meetings evaluated
		if(active.size() > mid) {
			active.erase(prev(active.end()));
			++deleted;
		}
	}

	return deleted;
}


int main() {
	ifstream cin("input/input5.txt"); 
	int n,k;
	cin >> n >>	k; 
	vector<ii> meetings(n); 
	for(auto &x : meetings) cin >> x.first >> x.second; 
	int l = 0, r = n, mid;
	sort(meetings.begin(),meetings.end());
	// strat: check if something overlaps? 
	while(l < r) { // binary search to find the best interval where to delete meetings
		mid = (l+r)/2; 
		if(solve(meetings,mid) <= k) r = mid;
		else l= mid + 1;
	}
	cout << l << endl;

	return 0;

}
