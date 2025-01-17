/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <iterator> 
#include <set>
#include <algorithm>
// constraints
#define MAXN 100000
#define INF 2000000000
using namespace std;
// input data
int N, D, i;
int L[MAXN], P[MAXN], S[MAXN], T[MAXN], sending[MAXN];
set<pair<int,int>> incoming; // P[i], sending signal

/*
	P = initial power L = max db received D = decrease 

intervals: Si, Si + Ti ecc
*/


int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input1.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &D));
    for(i=0; i<N; i++) {
        assert(4 == scanf("%d %d %d %d", &L[i], &P[i], &S[i], &T[i]));
		L[i] += D * i; // set delay time 
		P[i] += D * i; 
		sending[i] = INF;
    }
    // insert your code here
	sending[0] = S[0]; 
	incoming.emplace(P[0], sending[0]);
	
	for(i=1; i < N; ++i) {
		auto it = incoming.upper_bound({L[i],-1}); // confront with the treshold 
		if(it == incoming.end()) continue; // not received 
		// set time and next sending 
		int best = it->second; // set best time 
		sending[i] = S[i] + T[i] * ((best - S[i] + T[i]) / T[i]); // time of sending after received 
		it = incoming.upper_bound({P[i],-1}); // first with >= power 
		if(it != incoming.end() and it -> second <= sending[i]) continue; // not found or too low power 
		if(it != incoming.begin() or it -> first == P[i]) {
			if(it == incoming.end() or it -> first > P[i]) --it; // mark last with not greater pw 
			while(it -> second >= sending[i]) { // if worse than current 
				it = incoming.erase(it); 
				if(it == incoming.begin()) break; // finished checking all antennas 
				else --it; // check another
			}
		}
		incoming.emplace(P[i], sending[i]); // add current incoming message

	} 
    
    printf("%d\n", sending[N-1] == INF ? -1 : sending[N-1]); // print the result
    return 0;
}
