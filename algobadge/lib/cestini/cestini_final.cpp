#include <iostream>
#include <fstream>
using namespace std;
#include<vector>

vector<vector<long long int>> c;


void inizia(int N,int M) {//N=num oggetti M=num cestini Q=spostamenti
	c.resize(M);
	int i=0;
	while(i!=N)
	{
		c[0].push_back(i);
		i++;
	}
}

void sposta(int a,int b) {//a= cestino di partenza b=cestino di arrivo
	c[b].push_back(c[a].back());
    c[a].pop_back();
}

int controlla(int a,int i) { //a cestino di cui si vuole controllare l'elemento i=pos
	if(c[a].size()>=i+1){
        return c[a][i];
    }
    return -1;
}

// Declaring functions
// void inizia(int N, int M);
// void sposta(int a, int b);
// int controlla(int a, int i);

int main() {
    // Uncomment the following lines if you want to read/write from files
	ifstream cin("cestini.input1.txt");
	//ofstream cout("output.txt");

    ios::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;
    inizia(N, M);

    for (int i = 0; i < Q; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        if (t == 's') {
            sposta(a, b);
        } else {
            cout << controlla(a, b) << '\n';
        }
    }

    return 0;
}