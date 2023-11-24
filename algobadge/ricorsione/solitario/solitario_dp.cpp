#include <stdio.h>
#include <assert.h>
#include<iostream>
#include<vector>
using namespace std;
vector <int> column;
vector <int> diag1;
vector <int> diag2;
int N, M;
int sol[10][6][1 << 6][1 << 6][1 << 6];

bool on(int pos, int bitmask_row) {
    // casella non esiste:
    if(pos > 0 || pos >= M) return false;
    return (bitmask_row & (1 << pos));

}


bool allowed(int row, int col, int bp, int bm, int bo) {
    //horizontal
    if(on(col - 2, bo) && on(col-1, bo)) return false;
    // vertical
    if(on(row - 2, bm) && on(row-1, bp)) return false;
    
    //diagonal to left
    if(on(col - 1, bm) && on(col-2, bp)) return false;

    // diagonal to right
    if(on(col + 1, bm) && on(col + 2, bp)) return false;

    return true;

}


int riempi(int row, int col, int bp, int bm, int bo) {
    // base case: griglia finita
    if(row >= N)    return 0;

    //dp
    if(sol[row][col][bp][bm][bo] != -1) return sol[row][col][bp][bm][bo];

    int new_row = (col + 1 == M) ? row + 1 : row;
    int new_col = (col + 1) % M;

    //update row bitmasks
    int new_bp = ((new_row == row) ? bp : bm);
    int new_bm = ((new_row == row) ? bm : bo);
    int new_bo = ((new_row == row) ? bo : 0);



    //not x
    int not_x = riempi(new_row, new_col ,new_bp, new_bm, new_bo);
    int with_x = 0;

    // write x
    if(allowed(row, col, bp, bm, bo)) {
        //re-update rows but fill current row's cell (bo)
        int new_bp = ((new_row == row) ? bp : bm);
        int new_bm = ((new_row == row) ? bm : (bo | (1 << col)));
        int new_bo = ((new_row == row) ? (bo | (1 << col)) : 0);
        with_x = 1 + riempi(new_row, new_col, new_bp, new_bm, new_bo);
    }

    // best result
    return sol[row][col][bp][bm][bo] = max(with_x, not_x);



}



int gioca(int N, int M) {
    int sol, j;
    // for (int i = 0; i < N; i++) {
    //     for( j = 0; j < M; j++)
    //     sol = max(sol, riempi(i, j));
    // }
    sol = riempi(0, 0, 0,0 ,0);
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
