#include <iostream>
#include <vector>

using namespace std;

int solve(){
    int N;
    cin >> N;
    vector<int> V(N);
    for(int &x: V){
        cin >> x;
    }

    int risposta = 42;

    // aggiungi codice...

    return risposta;
}

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}

