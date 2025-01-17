#include "Mathematics/ntt.hpp"
#include <cassert>

using namespace std;

void test(vector<u64> a, vector<u64> b, vector<u64> s, u64 base = 10) {
    a.resize(a.size() * 2, 0);
    b.resize(b.size() * 2, 0);
    auto c = mul(a, b, base);
    assert(c == s);
}

int main() {
    test({3, 2, 1, 0}, {7, 3, 0, 0}, {21, 23, 13, 3, 0, 0, 0, 0});
    test({15, 15}, {15, 15}, {225, 450, 225, 0}, 16);
    test({1, 1, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 2, 1, 1, 1, 0}, 2);
    return 0;
}
