/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>
// constraints
#define MAXN 10000
using namespace std;
// input data
int N, B, i;
int V[MAXN];
vector<unordered_map<int,int>> dp;

int f(int idx, int spent) {
    if(idx == N) {
        if(spent < B) {
            return numeric_limits<int>::max();
        }
        else return spent;
    }

    auto it = dp[idx].find(spent);

    if(it != dp[idx].end()) // if already calculated
        return it -> second;

    
    int result = min(
        f(idx + 1, spent + V[idx]),
        f(idx + 1, spent)
    );

    dp[idx][spent] = result;
    return result;

}


int main() {
//  uncomment the following lines if you want to read/write from files
 freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &B));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &V[i]));

    // insert your code here
   
    
    printf("%d\n", f(0, 0)); // change 42 with actual answer
    return 0;
}
