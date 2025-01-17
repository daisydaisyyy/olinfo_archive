/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 10000

// input data
int N, i;
int T[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
    //freopen("input1.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &T[i]));

    // insert your code here
	int time = T[0];
	int idx = 0;
	for(i = 1 ; i < N ; i ++) {
		//printf("next item: %d\n", T[i]);
		if(time > T[i] + i) {
			//printf("item: %d\n", i);
			idx++; 
			time = T[i] +i;
			//printf("time: %d\n",time-1);
		}  
	}
    
    printf("%d %d\n", time, idx); // print the result
    return 0;
}
