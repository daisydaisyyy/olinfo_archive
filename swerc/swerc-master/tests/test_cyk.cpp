#include "Strings/cyk.hpp"

using namespace std;

int main() {
    auto res = cyk({{'S', "AB"}, {'S', "BC"}, {'A', "BA"}, {'A', "a"}, {'B', "CC"}, {'B', "b"}, {'C', "AB"}, {'C', "a"}}, 'S', "ababa");
    assert(res);
    res = cyk({{'S', "AB"}, {'A', "AA"}, {'B', "BB"}, {'A', "a"}, {'B', "b"}}, 'S', "aaabb");
    assert(res);
    return 0;
}
