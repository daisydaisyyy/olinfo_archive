/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
// constraints
#define MAXN 100000

// input data
int N, i, j;
int H[MAXN];
vector<vector<int>> adj, rev;
vector<int> mint, delta_end;
/* 
 * se parallelizzo due task (task1 > task2) posso avere un delay di task2 
 * pari a task1 - task2
 */

//finds minimum time
int minTime(int x) {
	cout << x << endl;
	if(mint[x] != -1)
		return mint[x]; 

	mint[x] = 0;
	for(int r:rev[x]) { // exams to do before current one
		cout << "r: " << r << endl;
		mint[x] = max(mint[x], minTime(r) + H[r]); //calc min time among taking each task
	}
	
	return mint[x];
}

int maxDeltaEnd(int x) {
	if(delta_end[x] != -1)
		return delta_end[x];

	delta_end[x] = H[x]; // set default delta at H[i] (necessary time to start)
	for(int a:adj[x]) { // exams to do after that 
		delta_end[x] = max(delta_end[x], maxDeltaEnd(a) + H[x]);
	}
	return delta_end[x];
}



int main() {
	//  uncomment the following lines if you want to read/write from files
	// freopen("input0.txt", "r", stdin);
	//  freopen("output.txt", "w", stdout);

	ifstream cin("input0.txt");
	//assert(1 == scanf("%d", &N));
	adj.resize(N);
	rev.resize(N);
	int a;
	for (i = 0; i < N; i++) {
		cin >> a;
		H[i] = a;
	}
	for (i = 0; i < N; i++) {
		int k;
		cin >> k;
		for (j = 0; j < k; j++) {
			int s;
			cin >> s;
			// TODO: process dependency s --> i
			adj[s].push_back(i);
			rev[i].push_back(s);
		}
	}

	// insert your code here
	int M = 0; 
	mint.assign(N,-1);
	delta_end.assign(N,-1);

	for(i = 0; i < 1; i++) {
		M = max(M, minTime(i) + H[i]);
		cout << M << endl;
	}// find max between current and taking another task 
	for(i = 0; i < N; i++) {
		cout << M - maxDeltaEnd(i); // print max delta permitted
	}

	return 0;
} 
