#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//#define MAXN 200001

//vector<int> s; 
//vector<ll> dp(MAXN, -1);

/*ll solve(int i) {
	if(i == s.size()) return 0; 
	if(dp[i] != -1) return dp[i];
	// 2 brews, calculate the minimum amount of time to brew all the coffees (s[i] is the num of brews necessary) 
	if(s[i] == 1) {
		//dp[i] = min(solve(i+1)))
	}



}*/


int main() {
	//ifstream cin("1.in");
	int n; 
	cin >> n; 
	//s.resize(n);
	//dp.resize(n);
	string x;
	int tot = 0;
	for(int i = 0; i < n; i++) { 
		cin >> x;
		if(x == "espresso") { tot += 1;}
		else if(x == "espresso-doppio") {tot += 2;}
		else if(x == "cappuccino") { tot += 1;}
		else if(x == "affogato") { tot += 2;}
		else if(x == "dead-eye") { tot += 3;}
		else if(x == "irish-coffee") {
			tot += 2;
			
		}
	}

	int double_shots_used = tot / 2;
    int remaining_shots = tot % 2;
    int total_presses = double_shots_used + remaining_shots;

    cout << total_presses << endl;

	return 0;

}
