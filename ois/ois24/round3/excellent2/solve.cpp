// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
constexpr int MOD = 1e9+7;
using namespace std;

int solve(int n) {
	vector<int> ans(3,0);
	ans[0] = 1;
	vector<int> base(3,1);
	base[0] = 0;

	for(; n != 0; n >>= 1) {
		if(n & 1) {
			vector<int> old_ans = ans; 
			ans = {0,0,0};
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j <3; j++) {
					ans[(i+j) % 3]  = (ans[(i+j) % 3] + (long long) old_ans[i] * base[j]) % MOD;
				}
			}

		}

		vector<int> old_base = base; 
		base = {0,0,0}; 
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				base[(i+j) % 3]  = (base[(i+j) % 3] + (long long) old_base[i] * old_base[j]) % MOD;
			}
		}
	}
	return ans[0];
}



int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        long long N;
        cin >> N;
        
        cout << solve(N) << endl;
    }

    return 0;
}
