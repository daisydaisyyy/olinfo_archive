#include<bits/stdc++.h>
using namespace std;



int main() {
	ifstream cin("input0.txt"); 
	cin >> n >> m; 
	vector<int> x(n);
	for(auto i : &x) cin >> i;
	vector<int> p(m + 1);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int const& i, int const &j) { return x[i] > x[j]; }); // sort idxs descending order

	auto xx = [&] (int const& i) { return x[p[i]]; };  // sort x values in descending order

	int k = 0; 
	for(int i = 1; i < m; i++) {
		if(xx(i) > m / i) { 
			k = i; // smallest idx such that x[i] > m / i -> can take >1 books from a section
			break;
		}
	}

	if(k == 0) {
		cout << "Alessia" << endl; 
		vector<bool> chosen(n, false);
		for(int t = 1; t <= n; t++) {
			int y = xx(t); // best lenght
			int last = 0; 
			int a = 0; 
			for(int i = 1; i <= m; i++) { 
				if(chosen[p[i]]) last = i; 
				if(!chosen[p[i]] && i - last == y) { // found correct interval
					a = last + 1; // update section start
					break;
				}
			}
			cout << y << " " << a << endl;
			int b; cin >> b; // read subj selected by b
			chosen[b] = true;
		}
	} else {
		cout << "Bernardo" << endl;
		for(int i = 1; i <= m; i++) {
			int a, y; 
			cin >> y >> a; // read len, section start
			bool taken = false; 
			if(i % xx(k) == 0) { // can take more books from subj i
				cout << i << endl;
				taken = true; 
				break;
			}
		}
		if(!done) cout << a << endl; // if not possible, print prev section start
	}

	return 0;

}
