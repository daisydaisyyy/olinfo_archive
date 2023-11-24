#include <stdio.h>
#include <assert.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define MAXN 10000
int i,j;
int interroga(int N, int K, int D[]) {
    // Mettete qui il codice della soluzione
    vector <int> v;
    for( i=0;i<N;i++){
        v.push_back(D[i]);
    }

    sort(v.begin(),v.end());
    // for(auto it:v){
    //     cout<<it<<endl;
    // }

    int max=v.back()-v.front();
    for(i=0;i+(K-1)<N;i++){
        // cout<<endl<<"v[i+K]-v[i]: "<<v[i+(K-1)]-v[i];
        // cout<<endl<<"v[i+K]: "<<v[i+(K-1)];
        // cout<<endl<<"v[i]: "<<v[i];
        if(v[i+(K-1)]-v[i]<max) max=v[i+(K-1)]-v[i];
    }
 
    return max;
}

int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for (i = 0; i < N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", interroga(N, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
