#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;

int codifica(int N) {
    // Mettete qui il codice della soluzione
    int n = N;
    int sol = 0,rem;
    if(N%10 == 0)   n /= 10;

    //cout << n << endl;
    while(n != 0){
        // cout << "n: " << n << endl;
        
        rem = n%10;
        n /= 10;
        sol += rem;
        // cout << "n2: " << n << endl;
        // cout << "rem: " << rem << endl;
        if(n == 0){
            break;
        }
        sol *= 10;
        
        // cout << sol << endl;
        
    }
    return sol + N;
}


int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));

    fprintf(fw, "%d\n", codifica(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
