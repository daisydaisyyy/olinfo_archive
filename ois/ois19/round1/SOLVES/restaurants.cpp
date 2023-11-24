#include <stdio.h>
#include <assert.h>

int N;              // number of restaurateurs
int vote, vtot;     // current vote and partial total of current restaurateur
int ibest, vbest;   // current best restaurateur with best vote

int main() {
/*
    uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/

    assert(1 == scanf("%d", &N));
    ibest = vbest = -1; // at first, no restaurateur is best
    for(int i=0; i<N; i++) {
        vtot = 0;
        for(int j=0; j<=N; j++) {
            // read every vote, adding to the current total (excluding the -1)
            assert(1 == scanf("%d", &vote));
            vtot += vote > 0 ? vote : 0;
        }
        // if it improves the best, save it
        if (vtot > vbest) {
            vbest = vtot;
            ibest = i+1;
        }
        printf("%d\n", ibest);
    }
    return 0;
}
