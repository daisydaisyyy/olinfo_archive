#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long s,t;
    if(!(cin>>n>>s>>t)) return 0;
    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if( (t & (~s)) != 0 ){
        cout<<0<<"\n";
        return 0;
    }

    int MAXB = 30;
    vector<int> cnt(MAXB);
    for(int b=0;b<MAXB;b++){
        for(int i=0;i<n;i++) if( (a[i]>>b)&1 ) cnt[b]++;
    }
    vector<ll> pow2(n+1);
    pow2[0]=1;
    for(int i=1;i<=n;i++) pow2[i]= (pow2[i-1]*2) % MOD;
    ll ans = 1;
    for(int b=0;b<MAXB;b++){ // per ogni bit con 1 in s conta quanti ospiti r hanno gia' a_i a 1
        if( ((s>>b)&1) == 0 ) continue;
        int r = cnt[b];
        int m = n - r; // ospiti liberi
        int tb = (t>>b)&1;
        int req = (tb - (r&1)) & 1;
        ll ways = 0;
        if(m==0){
            ways = (req==0 ? 1 : 0);
        } else { // check parity if its == req
            ways = pow2[m-1];
            if(r==0 && req==0){
                ways = (ways - 1 + MOD) % MOD;
            }
        }
        ans = (ans * ways) % MOD;
        if(ans==0) break;
    }
    cout<<ans%MOD<<"\n";
    return 0;
}
