// Computes the GCD among all numbers, then prints all its divisors
// checking up to the square root.

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

// constraints
#define MAXN 100

// input data
int N, i;
long long C[MAXN];

long long gcd(long long a, long long b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%lld", &C[i]));

    long long sol = C[0];
    for(i=1; i<N; i++)
        sol = gcd(sol, C[i]);

    vector<long long> divisors;
    for(long long div = 1; div * div <= sol; div++)
        if (sol % div == 0) {
            divisors.push_back(div);
            if (sol / div != div)
                divisors.push_back(sol / div);
        }
    sort(divisors.begin(), divisors.end());
    for (long long div: divisors)
        printf("%lld ", div);
    
    printf("\n");
    return 0;
}
