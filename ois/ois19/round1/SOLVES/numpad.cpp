/*
 * Simulate the ant movement, starting from position 0. The positions
 * from 0 to 9 are encoded with coordinates for simplicity.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    int x[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    int y[] = {0, 3, 3, 3, 2, 2, 2, 1, 1, 1};

    // starting position
    int start = 0;

    int answer = 0;
    for (char c: s) {
        int to = c - '0';

        // move to the new position
        answer += abs(x[start] - x[to]) + abs(y[start] - y[to]);
        start = to;

        // press the button
        answer += 1;
    }

    cout << answer << endl;
}
