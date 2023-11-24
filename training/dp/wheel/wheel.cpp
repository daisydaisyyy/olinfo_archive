#include <stdio.h>
#include <assert.h>

#define MAXN 40000
#define MAXQ 40000

FILE *fr, *fw;
 //Q=turni
    //K=numero giri
    //W=numeri nella ruota

void info(int mn, int mx) {
    fprintf(fw, "%d %d\n", mn, mx);
}


void dp(){

}


void win(int N, int W[], int Q, int K[]) {
    // insert your code here



    // info(4,2);
    // info(42,42);
}




int W[2*MAXN];
int K[MAXN];

int main() {
    int N, Q, i;
   
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<2*N; i++)
        assert(1 == fscanf(fr, "%d", &W[i]));
    assert(1 == fscanf(fr, "%d", &Q));
    for(i=0; i<Q; i++)
        assert(1 == fscanf(fr, "%d", &K[i]));

    win(N, W, Q, K);
    fclose(fr);
    fclose(fw);
    return 0;
}
