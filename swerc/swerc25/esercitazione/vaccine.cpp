#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

vector<string> v;

bool isPal(string s) {
    int i = 0; int j = s.size() - 1;
    while(i < j) {
        if(v[i] != v[j])
            return false;
    }
    return true;
}

void next_perm() {


}


int main() {
    int n; cin >> n;
    cout << n << endl;
    string s;
    while (n--) {
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());
    int i = 0, counter = 0; string concat;
    do {
         concat = "";
        // for(auto &x:v) concat += x;
        if(isPal(concat)) counter++;
    } while(next_permutation(v.begin(),v.end()));

    cout << counter << endl;
}