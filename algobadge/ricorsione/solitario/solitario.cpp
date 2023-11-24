#include <stdio.h>
#include <assert.h>
#include<iostream>
#include<vector>
using namespace std;
vector <int> column;
vector <int> diag1;
vector <int> diag2;
int N, M;
bool table[10][10];

bool allowed(int row, int col) {
    //horizontal
    if(col - 2 >= 0 && table[row][col-2] && table[row][col-1]) return false;

    // vertical
    if(row - 2 >= 0 && table[row-2][col] && table[row-1][col]) return false;

    //diagonal to left
    if(row - 2 >= 0 && col - 2 > 0 && table[row-2][col-2] && table[row-1][col-1]) return false;

    // diagonal to right
    if(row - 2 >= 0 && col + 2 < M && table[row-2][col+2] && table[row-1][col+1]) return false;

    return true;

}


int riempi(int row, int col) {
    // base case: griglia finita
    if(row >= N)    return 0;
    int new_row = (col + 1 == M) ? row + 1 : row;
    int new_col = (col + 1) % M;

    //not x
    int not_x = riempi(new_row, new_col);
    int with_x = 0;

    // write x
    if(allowed(row, col)) {
        table[row][col] = true;
        with_x = 1 + riempi(new_row, new_col);
        // reset
        table[row][col] = false;
    }
    return max(with_x, not_x);



}



int gioca(int N, int M) {
    int sol, j;
    // for (int i = 0; i < N; i++) {
    //     for( j = 0; j < M; j++)
    //     sol = max(sol, riempi(i, j));
    // }
    sol = riempi(0, 0);
    return sol;
}


int main() {
    FILE *fr, *fw;

    column.resize(M,0);
    diag1.resize(M,0);
    diag2.resize(M,0);
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));

    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
