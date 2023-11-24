// Starting from position 0, determines the (unique) match and advances
// the current position by the length of the matched codeword.

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;
const int MAXN = 100;
const int MAXL = 1000;
const int MAXC = 100;
char input[MAXN][MAXL+1];
char codes[10][MAXC+1];
int codes_len[10];

int matching_idx(char* input) {
    for (int i = 0; i < 10; i++)
        if (strncmp(input, codes[i], codes_len[i]) == 0)
            return i;
    // No matching found, should never happen
    assert(false);
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    for (int i = 0; i < 10; i++) {
        cin >> codes[i];
        codes_len[i] = strlen(codes[i]);
    }

    for (int i = 0; i < N; i++) {
        int start = 0, end = strlen(input[i]);
        while (start < end) {
            int idx = matching_idx(&input[i][start]);
            cout << idx;
            start += codes_len[idx];
        }
        // Consumed the whole input string
        assert(start == end);
        cout << endl;
    }
}
