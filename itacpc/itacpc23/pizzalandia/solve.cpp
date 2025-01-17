#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
ll INF = 1e18;

ll dist(pair<ll,ll> a, pair<ll,ll> b) {
	return llabs(a.first - b.first) + llabs(a.second - b.second);
}

ll dist_train(pair<ll,ll> train, pair<ll,ll> p, ll x, ll y) {

	ll cost = 0;
	cout << train.first << " " << train.second << endl;
	while(true) {
		//cout << train.first << " " << train.second << endl;
		// train on left border, moves clockwise 
		if(train.first == 0) {
			// p on top 
			if(p.first == 0 and p.second >= train.second) 
				return cost + p.second - train.second; 
			
			cost += y - train.second; // moving to the top of left border 
			train.second = y;
		}

		if(train.second == y) {
			// person on the right 
			if(p.second == y and p.first >= train.first) 
				return cost + p.first - train.first;

			// top right corner 
			cost += x - train.first; 
			train.first = x;
		}

		if(train.first == x) { // train below us 
			if(p.first == x and train.second >= p.second) 
				return cost + train.second - p.second; 
			cost += train.second; 
			train.second = 0;
		}

		// train on the left
		if(train.second == 0) {
			if(p.second == 0 and train.first >= p.first) 
				return cost + train.first - p.first; 
			cost += train.first;
			train.first = 0;
		}
	}
}


int main() {
	ifstream cin("input0.txt");

	int T; cin >> T; 
	while(T--) {
		ll x,y,tx,ty,wx,wy;
		cin >> x >> y >> tx >> ty >> wx >> wy;
		cout << x << " " << y << " " << tx << " " << ty << " " << wx << " " << wy << endl;
		ll ans = INF;
		ll loop = (x+y) * 2; // time to do an entire loop
		vector<pair<ll,ll>> points = {{0,wy},{x,wy},{wx,0},{wx,y}};
		for(auto point : points) {
			ll arrival = dist_train({tx,ty},point,x,y); 
			if(arrival >= dist({wx,wy},point)) ans = min(ans, arrival); 
			else ans = min(ans, arrival + loop);
		}
		cout << ans << endl;
	}

}
