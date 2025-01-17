/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;
// constraints
#define MAXN 10000
#define DIGITS 10
// input data
int N, M, i;
char op1[2*MAXN], op2[2*MAXN], res[2*MAXN];
bool taken[10];
int assigned[10];
bool found;

void map_op(int p, int r) { // p cifra, r resto 
	if(p >= N) {
		if((M > N && r == 1) || (M == N && r == 0)) {
			found = true; 
		}

		if (N > 1 && (assigned[op1[N-1]] == 0 || assigned[op2[N-1]] == 0)) {
			found = false;
		}
		return;
	}

	if(assigned[op1[p]] == -1 && assigned[op2[p]] == -1) {
		if(op1[p] != op2[p]) {
			// both digits are different and not assigned
			// bruteforce one and get the other
			for(int d = 0; d < DIGITS && !found; d++) {
				int a = d, b = (res[p] - r - d + 10) % 10;
				if (a == b || taken[a] || taken[b]) {
					continue; // wrong digit 
				} 
 
				taken[a] = taken[b] = true; 
				assigned[op1[p]] = a; 
				assigned[op2[p]] = b;
				map_op(p + 1, (a + b + r) / 10); 
				
				if(!found) {
					taken[a] = taken[b] = false; 
					assigned[op1[p]] = assigned[op2[p]] = -1;
				}
			}
		} else { 
			if ((res[p] - r + 10) % 2 == 1) 
				return;

			// same letters, only 2 values are good
			for (int k = 0; k < 2 && !found; k++) {
				int d = ((res[p] - r + 10) / 2 + k * 5) % 10;
				if (!taken[d]) {
					taken[d] = true;
					assigned[op1[p]] = d; 
					map_op(p + 1, (d + d + r) / 10); 

					if(!found) {
						taken[d] = false; 
						assigned[op1[p]] = -1;
					}
				}
			}
		}
	} else {
		// at most one assigned, swap op1 and op2
		bool swapped = false; 
		if(assigned[op2[p]] == -1) {
			swap(op1[p], op2[p]); 
			swapped = true;
		}

		if(assigned[op1[p]] == -1) {
			// first not assigned, get digit from the 2nd
			int d = (res[p] - r - assigned[op2[p]] + 10) % 10; 
			if (!taken[d]) {
				assigned[op1[p]] = d;
				taken[d] = true;
				map_op(p+1, (assigned[op2[p]] + d + r) / 10); 

				if(!found) {
					assigned[op1[p]] = -1; 
					taken[d] = false;
				}
			}
		} else {
			// both letters assigned, check if right 
			if ((assigned[op1[p]] + assigned[op2[p]] + r) % 10 == res[p]) {
				map_op(p+1, (assigned[op1[p]] + assigned[op2[p]] + r) / 10);
			}
		}

		if(swapped) {
			swap(op1[p], op2[p]);
		}
	}
}


int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%s", &op1[0]);
    scanf("%s", &op2[0]);
    scanf("%s", &res[0]);
    N = strlen(op1);
	M = strlen(res);
    assert(strlen(op1) == strlen(op2));

    // insert your code here
    // NOTE: both operands and result are read as strings
	for(i = 0; i < N; i++) {
		op1[i] -= 'A';
		op2[i] -= 'A';
	}

	for(i = 0; i < M; i++) {
		res[i] -= '0';
	}

	for(i = 0; i < DIGITS; i++) {
		assigned[i] = -1;
	}

	// reverse digits order (put lsb first)
	reverse(op1, op1+N);
	reverse(op2, op2+N); 
	reverse(res, res+M);

	map_op(0, 0);
   
	//assert(found); 
    for(i = N - 1; i >= 0; i--) {
		printf("%d",assigned[op1[i]]); 
	}
	cout << endl; 

	for(i = N - 1; i >= 0; i--) {
		printf("%d", assigned[op2[i]]);
	}
	cout << endl;

    return 0;
}
