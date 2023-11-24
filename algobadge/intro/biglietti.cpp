#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) { //ncorse,corse in carnet, costo biglietti, costo carnet
	int c=0; 
	while(N>0){
		if(N<=M){
			if(N*A<B){
				c+=N*A;				
			}
			else	c+=B;
			N=0;
		}else{
			if(M*A<B)	c+=M*A;
			else c+=B;
			N-=M;
		}	
	}	
	return c;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
