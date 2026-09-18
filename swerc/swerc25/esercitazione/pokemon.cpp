#include<iostream>
#include<set>
#include<string>
using namespace std;

set<string> s;


int main() {
    int n; cin >> n; string a;
    while(n--) {
        cin >> a;
        s.insert(a);
    }

    cout << s.size()+1 << endl;
}