#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>

using namespace std;

const int MAXN = 1002;
const int MAXM = 1002;
int dp[MAXN][MAXM];

int solve(vector<int>& V,  vector<int>& G, int v, int g) {
    if(v == 0) return 0; // v == 0, restano solo guide che spendono 0
    if(g == 0) return v; // guide == 0 ho il num di visitatori * 1 euro

    if(dp[v][g] == -1) { // max profitto non settato per quello stato 
        int temp = max(solve(V, G, v, g-1), solve(V, G, v-1, g) + 1); // 2: entra un visitatore da solo, 1: entra una guida da sola
        if(V[v-1] >= G[g-1]) dp[v][g] = temp; // faccio entrare il max di un visitatore o guida da solo 
        else dp[v][g] = max(temp, solve(V,G,v-1,g-1)+2); // faccio entrare guida + vis insieme
    }
    return dp[v][g];

}



int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;
    
    for (t = 1; t <= T; t++) {
        
        int nv, ng;

        cin >> nv >> ng;
        memset(dp, -1, sizeof dp);

        // int risposta = 0;  // memorizza qui la risposta
        vector<int> V(nv), G(ng);

        for (int i=0; i<nv; i++) 
            cin >> V[i];
        
        for (int i=0; i<ng; i++) 
            cin >> G[i];
        
        cout << "Case #" << t << ": " << solve(V, G, nv, ng) << endl;
    }
}
