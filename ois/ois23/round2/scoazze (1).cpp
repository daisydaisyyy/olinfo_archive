// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>

using namespace std;

// constraints
#define MAXN 200000
#define MAXK 200000

// input data
int N, K, i;

int main() {
//  uncomment the following lines if you want to read/write from files
 freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &K));
    int C[N];
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    int T[K], Q[K];
    for(i=0; i<K; i++)
        assert(2 == scanf("%d %d", &T[i], &Q[i]));

    int price = 0;
    vector<int> bin(K, 0);
     
    for (int i = 0; i < K; i++) {
        if (bin[T[i]] + Q[i] > C[T[i]]) {
            price += C[T[i]] - bin[T[i]];
            bin[T[i]] = Q[i];
        }
        else 
        {
            bin[T[i]] += Q[i];

        }
    }

    for (int i = 0; i < N; i++) {
        if (bin[i] != 0) {
            price += C[i] - bin[i];
        }
    }

    
    printf("%d\n", price); // print the result
    return 0;
}
