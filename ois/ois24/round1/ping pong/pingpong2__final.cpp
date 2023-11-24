
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // ifstream cin("input0.txt");
    //ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int A, B;
        cin >> A >> B;
        
        if (A > 33 && B < 11) {
            cout << "-1 -1" << endl;
            continue;
        }

        if (A < 33) {
            cout << "-1 -1" << endl;
            continue;
        }

        if (A == B) {
            cout << "-1 -1" << endl;
            continue;
        }
        
        // A vince con 3 set
        if (A == 33 && B <= 30) {
            for (int i = 0; i < 3; i++) {
                if (B >= 10) {
                    cout << "11 10" << endl;
                    B -= 10;
                }
                else {
                    cout << "11 " << B << endl;
                    B = 0;
                }
            }
            continue;
        }

        // A vince con 4 set
        if (A > 33 && B >= 11) {
            // cout << "Concede set" << endl;
            // 5 set
            if (B >= 22) {
                while (B >= 22) {
                    long long dist = A - 33;
                    if (dist <= 10) {
                        cout << dist << " 11" << endl;
                        A -= dist;
                        B -= 11;
                    }
                    else {
                        if (B < 33) {
                            cout << "-1 -1" << endl;
                            continue;
                        }
                    }
                }
                for (int k = 0; k < 3; k++) {
                    if (B > 10) {
                        cout << "11 10" << endl;
                        B -= 10;
                    }
                    else {
                        cout << "11 " << B << endl;
                        B = 0;
                    }
                }
                continue;
            }
            // 4 set
            else if (B >= 11)
            {
                B -= 11;
                long long dist = A - 33;
                cout << dist << " 11" << endl;
                for (int k = 0; k < 3; k++) {
                    if (B > 10) {
                        cout << "11 10" << endl;
                        B -= 10;
                    }
                    else {
                        cout << "11 " << B << endl;
                        B = 0;
                    }
                }
            }
            
            continue;
        }

        cout << "-1 -1" << endl;

    }

    return 0;
}