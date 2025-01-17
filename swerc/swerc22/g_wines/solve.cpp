#include<bits/stdc++.h>
using namespace std;

// a, b, vini 
// almeno n vini (a-b+1>=n) 
// non gli stessi
// stesso num di w
// output = quanti vini w nell'intervallo

int main() {
	//ifstream cin("input0.txt"); 
	int n; string s; 
	cin >> n >> s;

	int curr_w = 0; 
	int max_w; 

	for(int i = 0; i < n; ++i) 
		curr_w += int(s[i] == 'W');
	
	max_w = curr_w; 

	for(int i = 1; i < n; ++i) {
		curr_w -= int(s[i-1] == 'W'); // remove first w
		curr_w += int(s[i + n - 1] == 'W'); // add next w 
		max_w = max(max_w, curr_w);
	}
	cout << max_w << endl;


	return 0;

}
