#include "Generic/twosat.hpp"
#include "test_utils.hpp"

using namespace std;

int main() {
  vector<vector<u32>> c = {{0, 2}, {1, 4}, {3, 4}};
  test_sat(c, twosat(c), true);
  c = {{0, 2}, {1, 2}, {0, 3}, {1, 3}};
  test_sat(c, twosat(c), false);

  return 0;
}
