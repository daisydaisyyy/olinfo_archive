#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph(26);
vector<int> state; // 0 = not visited, 1 = visiting, 2 = done
bool cycle = false; 

void dfs(int v) {
    state[v] = 1;
    for (int u : graph[v])
        if (!state[u])
            dfs(u);
        else if(state[u] == 1) cycle = true;
    state.push_back(v);
    state[v] = 2;
}

void insert(char n1, char n2, char s) {
    int a = n1 - 'a';
    int b = n2 - 'a';
    if (s == '>') graph[a].push_back(b);
    else graph[b].push_back(a);
}

int main() {
    int n;
    cin >> n;
    char a, sign, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> sign >> b; // legge "a", ">", "b"
        insert(a, b, sign);
    }

    state.assign(26,0);
    for(int i = 0; i < 26; i++) {
        if(state[i] == 0)
            dfs(i);
    }

    if(cycle)
        cout << ":(";
    else cout << ":)";
    cout << endl;




}
