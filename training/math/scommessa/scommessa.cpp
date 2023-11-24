#include <stdio.h>
#include <assert.h>
#include<iostream>
#include<vector>
using namespace std;


vector<int> c

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d", &N));
    for (i = 0; i < N; i++)
        assert(1 == fscanf(fr, "%d", &c[i]));

    //fprintf(fw, "%d\n",);
    fclose(fr);
    fclose(fw);
    return 0;
}
