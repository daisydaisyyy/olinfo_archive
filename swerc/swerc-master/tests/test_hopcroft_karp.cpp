#include "Graphs/hopcroft_karp.hpp"

int main() 
{ 
    init(10);

    add_edge(1, 2);
    add_edge(1, 3); 
    add_edge(2, 1); 
    add_edge(3, 2); 
    add_edge(4, 2); 
    add_edge(4, 4);

    auto r = run();
    // vector<int> ans = {2, 0, 1, 3, -1};
    // assert(r == ans);

    for (int i = 0; i < 10; i++) {
        cout << match[i] << endl;
    }

    return 0;
} 
