// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<pair<int,int>> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first;

    
    for (int i = 0; i < N; ++i)
        cin >> v[i].second;

    long long ans = 0;

    // INSERT YOUR CODE HERE
	vector<pair<int, int>> ranges;
	for (int i = 0; i < N; i++) {
		ranges.push_back({v[i].first - v[i].second, v[i].second}); // start coord of the rectangle
		ranges.push_back({v[i].first + v[i].second, -v[i].second}); // end coord
	}

	sort(ranges.begin(), ranges.end());
	multiset<int> active; 
	active.insert(0); 
	int last = -1e9; 

	for(auto [start, end] : ranges) { 
		ans += 2LL * (start - last) * (*active.rbegin()); 
		if(end > 0) active.insert(end); // only computed the start, leave active to see if another overlaps
		else active.erase(active.find(-end)); // already checked this rectangle
		last = start;
	}


    cout << ans << endl;

    return 0;
}
