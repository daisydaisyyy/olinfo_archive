/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <valarray>
#include <iostream>
#include <string>
// constraints
#define MAXN 1000000
using namespace std;
// input data
int N;
string S;

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    cin >> S;
    

    // insert your code here
    
    //store digits as coordinates
    int x[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    int y[] = {0, 3, 3, 3, 2, 2, 2, 1, 1, 1};

    int start = 0;
    int answ = 0;
    for(char c : S) {
        int to = c - '0';

        answ += abs(x[start] - x[to]) + abs(y[start] - y[to]);
        start = to;

        // press digit
        answ += 1;
    }

    printf("%d\n", answ);  // change 42 with actual answer
    return 0;
}
