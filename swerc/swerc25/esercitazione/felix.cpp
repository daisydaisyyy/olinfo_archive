#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
#define MAXN 200000
#define MAXLEN 100000
ll dp[MAXN][2];
int n;
vector<ll> lens;




int main() {
    cin >> n;
    int i = n;
    int x;
    while(i--) {
        cin >> x;
        lens.push_back(x);
    }

    int len = lens[0];
    
    int sum = 0;
    for(int i = 1; i < n; i++) {
        sum += lens[i];
    
        if(sum >= len) {
            len = sum;
            sum = 0;
        }
    }

    cout << len << endl;
}