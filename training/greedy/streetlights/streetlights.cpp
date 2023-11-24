#include <stdio.h>
#include <assert.h>

#define MAXN 100000



int kindle(int N, int M, int K, int L[]) {
    // insert your code here
    int c=0,i,b,app=0;
    //primo intervallo
    for(i=0;i<M;i++){
        c+=L[i];
    }

    for(i=0;i+M-1<N;i++){
        //conta num accese
        // printf("\ni: %d",i);
  
        // printf("\nc: %d",c);
        if(c<K){
            // printf("\nnel ciclo\n");
            
            for(b=(i+M)-1;c<K;b--){
                // printf("\nb: %d",b);
                if(L[b]==0){
                    L[b]=1;
                    c++;
                    app++;
                }
            }
            //  printf("\nc: %d",c);
            

            // for(int k=0;k<N;k++){
            //      printf("\L[k]: %d",L[k]);
            // }
        }
        c-=L[i];
        c+=L[i+M]; 

    }
    
    return app;
    //return 42;
}


int L[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &L[i]));

    fprintf(fw, "%d\n", kindle(N, M, K, L));
//    printf( "\n%d\n", kindle(N, M, K, L));
    fclose(fr);
    fclose(fw);
    return 0;
}
