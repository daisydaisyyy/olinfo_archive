#include <stdio.h>
#include <assert.h>
#include<algorithm>
#define MAXN 100000
//using namespace std;

int sfangate(int N, int V[]) {
    int somma=0,i,j=0;
    std::sort(V,V+N);

    for(i=0;i<N;i++){
        somma+=V[i];
    }
    printf("\nsomma: %d",somma);
    i=0;
    while(somma<=0){
        if(V[i]<0) {
            somma+=(V[i]*(-1))*2;
            printf("\nsomma: %d",somma);
            
            j++;
            
        }
        i++;
    }
    printf("\nj: %d",j);
    return j;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}

