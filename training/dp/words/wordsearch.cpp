#include <bits/stdc++.h>
using namespace std;

/*
S = words
H = lines W = letters in a line
matrix HxW

res % 1 000 000 007

parti da una cella e trova tutte le combo???
store in cache?
*/


const int MAXH = 100;
const int MAXW = 100;
const int MAXS = 1000;
const int MOD = 1000000007;
string S;
int H, W;
char M[MAXH][MAXW + 1];
int cache[MAXH][MAXW][MAXS];

int find(int r, int c, int k) {
    if(r < 0 or r >= H or c < 0 or c >= W) return 0;

    int &res = cache[r][c][k]; // k = index of curr cell + direction (8 possible directions starting from a cell)
    if(res != -1) return res;

    res = 0;

    if(M[r][c] == S[k]) { // found matching char
        if(k + 1 == S.length()) res = 1; // found entire word 
        else {
            for(int dr = -1; dr <= 1; dr++) { // 3 possible rows to try (-1 = prv, 0 = same, 1 = next)
                for(int dc = -1; dc <= 1; dc++) { // 3 possible cols to try
                    if(dr != 0 or dc != 0) {
                        res = (res + find(r + dr, c + dc, k + 1)) % MOD; // try all possible directions from the starting cell
                    }
                }
            }
        }
    }

    return res;
}




int main() {
    cin >> S;
    cin >> H >> W;

    for (int i=0; i<H; i++) {
        cin >> M[i];
    }


    memset(cache, -1, sizeof cache);
    int answer = 0;

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            answer = (answer + find(i, j, 0)) % MOD;
        }
    }

    cout << answer << endl;
}
