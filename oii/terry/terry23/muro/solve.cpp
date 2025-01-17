#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
#define INF 1001
// new : col+1
// max col = N-L[i]+1
// ci = max(ci+1, N-L[i]+1)
void solve(int t) {
    int N, Q;
    cin >> N >> Q;
	int ans=0;

    vector<int> L(Q);
    for (int i = 0; i < Q; i++) {
        cin >> L[i];
		ans = min(ans + 1, N - L[i]+1);
    }

    // aggiungi codice...
	
	
    

    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    //freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
