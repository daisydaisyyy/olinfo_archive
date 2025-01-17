// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

ull solve_total(ull n){ // xor patterns repeat every 4 numbers
    ull mod = n % 4;
    if(mod == 0) return n;
    if(mod == 1) return 1;
    if(mod == 2) return n + 1;
    return 0;
}


ull solve_max(ull t, ull n){
    ull x = 0;
    bool less = false;
    for(int i = 63; i >= 0; i--){ // iterate through all bits
        ull bit_n = (n >> i) & 1;
        ull bit_t = (t >> i) & 1;
        ull desired_bit = 1 - bit_t;
        
        if(less) {
            if(desired_bit){
                x |= (1ULL << i);
            }
        }
        else{
            if(desired_bit < bit_n){
                if(desired_bit == 1){
                    x |= (1ULL << i);
                }
                less = true;
            }
            else if(desired_bit == bit_n){
                if(desired_bit == 1){
                    x |= (1ULL << i);
                }
                
            }
            else{
                // desired_bit > bit_n
                if(bit_n){
                    x |= (1ULL << i);
                }
                // else set to 0
            }
        }
    }
    return t ^ x;
}



int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int Q;
    cin >> Q;
    
	while(Q--) { 
		ull a;
		cin >> a;
		ull total = solve_total(a);

		ull max_xor = solve_max(total, a);

		cout << total << " " << max_xor << endl;
	}

    return 0;
}
