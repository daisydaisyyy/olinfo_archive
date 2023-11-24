#include <stdio.h>
#include <assert.h>
#include <algorithm>
#define MAXN 1000

using namespace std;

/*
v = tokens
(si, sj) -> si%sj=0 || sj%si=0

*/
int cache[MAXN];


int main() {
    int n;
    int v[MAXN];

    assert(1 == scanf("%d", &n));
    for (int i=0; i<n; i++)
        assert(1 == scanf("%d", &v[i]));

    // insert your code here
    // sort
    sort(v, v+n);
    cache[0] = 1; // min res possible
    for(int i = 0; i < n; i++){ // try all combinations of a fixed position with all the other positions 
        for(int j = 0; j < i; j++){ // try all the other positions
            if(v[i] % v[j] == 0 && cache[j] + 1 > cache[i]){ // check if there is a better result for the current fixed num (i)
                cache[i] = cache[j] + 1; // update best res for that fixed pos
            }
        }
    }

    // find max in cache
    int maxS = 0, maxidx = 0; 
    for(int i = 0; i < n; i++){
        if(cache[i] > maxS){
            maxS = cache[i];
            maxidx = i;
        }
    }







    printf("%d", maxS);
    
    return 0;
}
