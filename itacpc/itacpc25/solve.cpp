#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> A;
ll n, k;


int main() {
    cin >> n >> k;
    ll x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        A.push_back(x);
    }


    sort(A.begin(), A.end());
    ll power = 0;
    for(int i = 1; i < k && A.size() > 2; i++) {
        // cout << "k: " << i << endl;
        // cout << A[n - i] << " " << A[0] << endl;
        // cout << A[n - i] - A[0] << endl;
        A[n - i] -= A[0];
        power = A[n - i];
        A.erase(A.begin());
        sort(A.begin(), A.end());
    }

    cout << power << endl;


}

/*
2 3 5 6

*/