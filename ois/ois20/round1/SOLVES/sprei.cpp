	
/*
{1}
Autor: Moroianu
Punctaj intented: 100p
{1}
*/
 
#include <iostream>
#include <map>
#include <vector>
#include <cassert>

using namespace std;
 
/// Cuplaj este o structura clasica care calculeaza cuplajul maxim al unui graf bipartit
/// Desi nu pare ca se foloseste de faptul ca e bipartit graful, este fix algoritmul clasic dar putin modificat ca sa fie mai usor de bagat
struct Cuplaj {
    int n;
    vector <int> cuplat, viz;
    vector <vector <int>> adia;
 
    int cuplaj(int nod) {
        if (viz[nod])
            return 0;
        viz[nod] = 1;
        for (auto i : adia[nod]) {
            if (cuplat[i] == -1) {
                cuplat[i] = nod, cuplat[nod] = i;
                return 1;
            }
        }
        for (auto i : adia[nod]) {
            if (cuplaj(cuplat[i])) {
                cuplat[i] = nod, cuplat[nod] = i;
                return 1;
            }
        }
        return 0;
    }
 
    void AddEdge(int a, int b) {
        adia[a].push_back(b);
        adia[b].push_back(a);
    }
 
    int GetMinimalVertexSpecialCover() {
        /// daca un nod e singur tot trebuie sa il iau
        bool madesmth = 1;
        int cuplaj_maxim = 0;
        while (madesmth) {
            madesmth = 0;
            fill(viz.begin(), viz.end(), 0);
            for (int i = 0; i < n; i++)
                if (!viz[i] && cuplat[i] == -1 && cuplaj(i))
                    madesmth = 1, cuplaj_maxim++;
        }
        return cuplaj_maxim;
    }
 
    Cuplaj(int n = 0) : n(n), cuplat(n, -1), viz(n), adia(n) { }
};
 
 
const int mod[] = { (int)1e9 + 7, (int)1e9 + 9 };
int N, M, B;
vector <vector <int>> powB, hashes;          /// power of B and hashes of POZ, with double hashing
vector <vector <int>> POZ;                   /// input vector POZ
map <vector <int>, int> who_has_hash;        /// map that knows for a certain hash how has it
Cuplaj cuplaj;                               /// instantiation of the Matching struct
 
/// computes the powB, hases and who_has_has vectors
void CalcH()
{
    hashes = vector <vector <int>> (N, vector <int> (2));
    powB = vector <vector <int>> (M, vector <int> (2));
    powB[0][0] = powB[0][1] = 1;
 
    for (int i = 1; i < M; i++)
        for (int c = 0; c <= 1; c++)
            powB[i][c] = 1LL * B * powB[i - 1][c] % mod[c];
 
    for (int id = 0; id < N; id++)
        for (int c = 0; c <= 1; c++)
            for (int i = 0; i < M; i++)
                hashes[id][c] = (hashes[id][c] + 1LL * powB[i][c] * POZ[id][i]) % mod[c];
 
    who_has_hash.clear();
    for (int id = 0; id < N; id++) {
        assert(who_has_hash.find(hashes[id]) == who_has_hash.end());
        who_has_hash[hashes[id]] = id;
    }
}
 
/// computes the edges (direct mutations) that exist in the given configuration
void GetMutations()
{
    for (int id = 0; id < N; id++) {
        for (int i = 0; i < M; i++) {
            if (POZ[id][i] == B - 1)
                continue;
            vector <int> newh = hashes[id];
            for (int c = 0; c <= 1; c++)
                newh[c] = (newh[c] + powB[i][c]) % mod[c];
 
            if (who_has_hash.find(newh) != who_has_hash.end())
                cuplaj.AddEdge(id, who_has_hash[newh]);              
        }
    }
}
 
int Solver()
{
//    ifstream in(sin);
//    ofstream out(sout);
    cin >> N >> M >> B;
 
    POZ = vector <vector <int>> (N, vector <int> (M));
    for (auto & i : POZ)
        for (auto & j : i)
            cin >> j;
 
    CalcH();
    cuplaj = Cuplaj(N);
    GetMutations();
 
    int ans = cuplaj.GetMinimalVertexSpecialCover();
 
    cout << ans << '\n';
 
//    in.close();
//    out.close();
    return ans;
}
 
int main()
{
    Solver();
    return 0;
}
