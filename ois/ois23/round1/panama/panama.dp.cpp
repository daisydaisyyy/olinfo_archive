// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// input data
int N, Q,j=0,m=0,k=0,sum=0;
vector<int> V;


//se abbiamo una sottosequenza che parte da start ed è lunga lenght qual è la migliore sottosequenza contigua?
int dp(int start,int lenght){
    //int sum;
    // cout<<"start: "<<start<<endl;
    // cout<<"lenght: "<<lenght<<endl;
    if(lenght==0)  return V[start]; //lunghezza=0, ho finito di controllare il subarray
    else{
            //somma di tutto il subarray
            //sum=0;
            //cout<<"sum: "<<sum<<endl;
            if((start+k)%2!=0) sum-=V[start-1];
            else sum-=-V[start-1];
            cout<<"sum: "<<sum<<endl;
            cout<<"V[start-1]: "<<V[start-1]<<endl;
            // cout<<"m: "<<m<<endl;
            // cout<<"k: "<<k<<endl;
            k++;
            return max(sum,max(dp(start,m),dp(start+m+1,lenght-1))); 
    }

}

int main() {
    //  uncomment the following lines if you want to read/write from files
      ifstream cin("input0.txt");
    //   ofstream cout("output.txt");

    cin >> N >> Q;
    V.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> V[i];

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            // insert your code here
            V[a]=b;
        } else {
            int l, r;
            cin >> l >> r;
            // insert your code here
            ::sum=0;
            for(int i=l;i<=l+(r-l);i++){
                //cout<<"i-start: "<<i-start<<endl;
                if((i-l)%2==0) ::sum+=V[i];
                else ::sum-=V[i];
                //  cout<<"V[i]: "<<V[i]<<endl;
            }
            cout<<"totSum: "<<::sum<<endl;
            cout<<max(::sum,dp(l,r-l))<<endl;
        }
    }

    return 0;
}
