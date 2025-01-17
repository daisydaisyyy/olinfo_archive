#include <bits/stdc++.h>
using namespace std;


int f(int N, string &S) {
	vector<char> dp(N + 1); 
	char dir = '.';
	dp[N] = '.';

	for(int i = N-1; i >= 0; i--) {
		if(S[i] == '?') dp[i] = dp[i+1]; // misterioso, continua nella direzione corrente
		else dp[i] = S[i];
	}
	int arrampica = 1; 

	for(int i = 0; i < N; i++) {
		if(S[i] == '>') {
			if(dir == '<') { // direzione opposta, arrampicati
				arrampica++; 
				dir = '.';
			} else dir = '>';
		}
		else if(S[i] == '<') {
			if(dir == '>') { // direzione opposta, arrampicati
				arrampica++; 
				dir = '.';
			} else dir = '<';
		} else { // bloccata
			if(dir == '>') S[i] = '<'; 
			else if(dir == '<') S[i] = '>';
			else if(dp[i] == '<') S[i] = '>'; 
			else S[i] = '<';
			i--;
		}
	}
	return arrampica;
}


int arrampicate(int N, string S){
    string s = "";
	int ans = 0;
	for(auto c : S) {
		if(c == '#') {
			ans += f(s.size(),s);
			s = "";
		}
		else if(c != '=') s.push_back(c);
	}
	ans += f(s.size(), s);
	return ans;
}



int main() {
	ifstream cin("input2.txt");

    int N;
    assert(cin >> N);
    
    string S;
    assert(cin >> S);

    cout << arrampicate(N, move(S)) << '\n';

}



