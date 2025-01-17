#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
 * 1 
 * 121 
 * 1213121 
 * (center = idx, the rest is the same as the previous one repeated on left and right)
 */
int d, n;

ll get_s(int num) {
	if(num < 10) return num; 
	return (num % 10) + get_s(num / 10);
}

int main() {
	ifstream cin("input/input1.txt"); 
	cin >> d >> n; 
	ll res = d;
	for(int i = 2; i <= n; i++) {
		res = (2 * res) + get_s(i);
	}
	cout << res << flush << endl;
	
	return 0;

}
