// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 200001
using namespace std;

long long N, sol, rows[MAX_N], cols[MAX_N]; 
pair<long, long> stars[MAX_N];


int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input0.txt");
//  ofstream cout("output.txt");

    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> stars[i].first >> stars[i].second; 
		rows[stars[i].first]++;
		cols[stars[i].second]++;
	}

	for(int i = 0; i < N; i++)
		sol += (rows[stars[i].first]-1)*(cols[stars[i].second]-1); 

    cout << sol << endl; // print the result
    
    return 0;
}

