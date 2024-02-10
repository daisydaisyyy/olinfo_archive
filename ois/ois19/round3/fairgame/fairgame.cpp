/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <iostream>
#include <assert.h>
#include<fstream>
#include<queue>
#include <climits>
using namespace std;
#define MAXV 5000000 * 2
/*
N = rock num 
K = max q 
M = pay amount 
P = win money gain (takes last)
Q = lost money gain

*/
// input data
int N, K, M, P, Q;
deque<pair<int,long long>> A, B; // index, money

int solve() {
    A.emplace_back(0,Q-P); // initial diff
    for(int i = 0; i <= N; i++) {
        while(!A.empty() and A.front().first + K < i ) A.pop_front();
        while(!B.empty() and B.front().first + K < i ) B.pop_front();

        long long best = -MAXV;
        if(!A.empty()) // A takes rock 
            best = max(best, -A.front().second - (i&1) * M); // if i odd, subtract money (A turn)
        
        if(!B.empty()) // B takes rock
            best = max(best, -B.front().second - (1 - i&1) * M); // if i even, subtract money (B turn)

        if (i&1) {
            while (!B.empty() && B.back().second >= best) B.pop_back();
            B.emplace_back(i, best); // (set best for that turn)
        } else {
            while (!A.empty() && A.back().second >= best) A.pop_back();
            A.emplace_back(i, best);
        }

    }
    return ((N&1) ? B.back().second : A.back().second);


} 




int main() {
//  uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(5 == scanf("%d%d%d%d%d", &N, &K, &M, &P, &Q));

    // insert your code here
    
    printf("%d\n", solve()); // print the result
    return 0;
}
