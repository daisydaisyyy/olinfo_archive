#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int* V;
static int B;

// Declaring functions
//int quadri(int N, long long M, int* V);


int quadri(int N, long long M, int V[]) {
    // Scrivete qui la vostra soluzione
    //N=num quadri M=max valore
    int j=0,B=N,i=0; //B=best case (N)
    long long int sum=0;
    bool check=false; //per entrare nel ciclo


    while(B!=0&&!check){
        check=true;
        //if(B==N-1)  check=true;
        for(i=0;i+(B-1)<N&&check;i++){ //provo con lo stesso numero di B sui sottoarray
        
            //fprintf(fw, "\n\n\nB: %d", B);
            sum=0;
            for(int k=i;k<=i+(B-1)&&sum<M;k++){ //scorro i singoli subarray
                sum+=V[k];
                // fprintf(fw, "\nV[k]: %d\n", V[k]);
            }
            if(sum>M){
                check=false;
                B--;
            } 
           
            // fprintf(fw, "sum: %d\n", sum);
            // fprintf(fw, "check: %d\n", check);

            
        }
        //  fprintf(fw, "\nesco\n");
        // if(!check)  {
        //     B--;
        //     //check=true;
        // }
       
        
    }
    //    fprintf(fw, "check: %d\n", check);   
    //if(!check)  B=0;
    // if(B<0) B=0;
    return B;

    
}

int main() {
    fr = fopen("input2.txt", "r");
    fw = fopen("output.txt", "w");

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d %lld", &N, &M);
	V = (int*)malloc(N * sizeof(int));
	for (i0 = 0; i0 < N; i0++) {
	    fscanf(fr, "%d", &V[i0]);
	}

	// Calling functions
	B = quadri(N, M, V);

	// Writing output
	fprintf(fw, "%d\n", B);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
