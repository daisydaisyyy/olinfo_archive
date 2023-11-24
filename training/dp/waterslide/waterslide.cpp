#include <bits/stdc++.h>
#define MAXM 200000
using namespace std;
/*
the index of the pool where most of the people will arrive
N = junctions
M = slides
P = pools
The launch pad has index 0, the ending pools have a number between N − P and N − 1. 
The next M lines contain two integers Ai , Bi each: the starting and ending junction of each slide (respectively).
start = curr slide, end = next slide
pool: N - P < pool < N - 1
*/
int N, M, P;
int paths[MAXM];
int A[MAXM];
int B[MAXM];
// int i = 0;

void find_pool(int start, int end, int i) {
 
    if(end >= N - P) { // pool
        paths[(end) - (N - P)]++;
        return;
    }
    bool check = false;
    int j = i;
    //  && A[j] == start
    for(; j <= N; j++) {
        if(A[j] == start) {
            for(; i <= N; i++) {
                if(A[i] == end) {
                    find_pool(end, B[i], i); // try all paths from the current end
                    check = true;
                }
            // else if(check) // if i finish all next paths
            //     break;     
            
            }
        }
        
    }
      
            
    
    return;
}

/*
    starting from 0, find all paths to the pools
    if B[i] == pool -> cache[pool]++
    else 
*/






int main() {
    FILE *fr, *fw;
    int i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &P));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));
    
    memset(paths, 0, sizeof paths);
    find_pool(A[0], B[0], 0);
    int idx = 0, maxP = 0;
    for(int k = 0; k < P; k++) {
        if(maxP < paths[k]) {
            idx = k + (N - P);
            maxP = paths[k];
        }
            
            
    }

    fprintf(fw, "%d\n",idx);
    fclose(fr);
    fclose(fw);
    return 0;
}
