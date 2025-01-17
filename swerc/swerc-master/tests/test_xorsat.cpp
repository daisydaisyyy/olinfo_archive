#define NSAT 4
#include "Generic/xorsat.hpp"

using namespace std;

int main() {
	//(a⊕c⊕d) ∧ (b⊕¬c⊕d) ∧ (a⊕b⊕¬d) ∧ (a⊕¬b⊕¬c) 
	vector<vector<u32>> v = {{0, 4, 6}, {2, 5, 6}, {0, 2, 7}, {0, 3, 5}};
	auto r = xorsat(v);
	cout << r.size() << endl;
	for (auto b : r)
		cout << b << " ";
	cout << endl;
	
	//(a⊕c⊕d) ∧ (b⊕¬c⊕d) ∧ (a⊕b⊕¬d) ∧ (a⊕¬b⊕¬c) ∧ (¬a⊕b⊕c)
	v = {{0, 4, 6}, {2, 5, 6}, {0, 2, 7}, {0, 3, 5}, {1, 2, 4}};
	r = xorsat(v);
	cout << r.size() << endl;
	for (auto b : r)
		cout << b << " ";
	cout << endl;
	
	//(a⊕c⊕d)
	v = {{0, 4, 6}};
	r = xorsat(v);
	cout << r.size() << endl;
	for (auto b : r)
		cout << b << " ";
	cout << endl;

}