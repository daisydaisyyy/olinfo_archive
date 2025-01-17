
#include <assert.h>
#include <stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;
// constraints
#define MAXN 100000
#define MAXM 100000

// input data
int N, M, i, value = 0, dish;
pair<int,int> H[MAXN];
int T[MAXM], tc[MAXM], p[MAXN]; // tc = current time, p = stove assigned to dish

int main() {
//  uncomment the following lines if you want to read/write from files
	freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &M));
	printf("n, n : %d %d", N,M);
    for (i = 0; i < N; i++) {
        assert(1 == scanf("%d", &H[i].first));
        H[i].second = i;
    }
    sort(H, H+N);
    for (i = 0; i < M; i++) assert(1 == scanf("%d", &T[i]));

    // insert your code here
	for(dish = N-1; dish != 0; dish--) { 
		printf("dish: %d\n", dish);
		int stove = -1, end = 10000;
		for(i = 0; i < M; i++) {
			printf("\ntc: %d\n", tc[i]);
			int tmp = tc[i] + H[dish].first * T[i]; 
			if(tmp < end) end = tmp; stove = i; //choose best time and stove for the dish 
			
		}
		p[H[i].second] = stove;
		tc[stove] = end; 
		value = max(value, end);
	}



    printf("value: %d\n", value);                         // change 42 with actual answer
    for (i = 0; i < N; i++) printf("%d ", p[i]);  // change 42 with actual answer
    printf("\n");
    return 0;
}
