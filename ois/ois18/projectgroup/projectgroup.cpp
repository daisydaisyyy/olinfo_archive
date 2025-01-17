#include <stdio.h>
#include <assert.h>

#define MAXN 10000
#define MAXM 10000

int N, M;
int a[MAXN], b[MAXN];

int main() {
    FILE *fr, *fw;
    int i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    for(i=0; i<M; i++) {
        assert(2 == fscanf(fr, "%d %d", &a[i], &b[i]));
    }

    // Insert your code here.
    fprintf(fw, "%d\n", 1);
    fprintf(fw, "%d %d %d\n", 0, 1, 2);

    fclose(fr);
    fclose(fw);
    return 0;
}
