#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K, i;
int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &K));
    int C[N];
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    int T[K], Q[K];
    for(i=0; i<K; i++)
        assert(2 == scanf("%d %d", &T[i], &Q[i]));

    ll price = 0;
    vector<ll> bin(K, 0);

    for(int i = 0; i < K; i++) {
        if(bin[T[i]] + Q[i] > C[T[i]]) {
            price += C[T[i]] - bin[T[i]];
            bin[T[i]] = Q[i];
        }
        else bin[T[i]] += Q[i];
    }

    // last day
    for(int i = 0; i < N; i++) 
        if(bin[i] != 0) price += C[i] - bin[i];
    
    printf("%ll\n", price);


}
