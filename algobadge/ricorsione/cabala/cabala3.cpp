#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long fast_atoi( const char * str )
{
    long long val = 0;
    while( *str ) {
        val = val*10 + (*str++ - '0');
    }
    return val;
}

long long occulta(int N, int M, string n, int res) {
    long long l;
    for (int i = 3; i < 10; i=i+3){
        if ((n != "" ? n[n.size()-1] : '/') != char(i+48)){
            if ((((n != "" ? fast_atoi(n.c_str()) : 0)*10)+i)%M > res)
                res = (((n != "" ? fast_atoi(n.c_str()) : 0)*10)+i)%M;
            if ((n+char(i+48)).size() < N){
                l = occulta(N, M, n+char(i+48), res);
                if (l > res)
                    res = l;
            }
        }
    }
    return res;
}



int main() {
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input2.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        
        fprintf(fw, "%d ", occulta(N, M, "", -1));
        // maxR = -1;
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}