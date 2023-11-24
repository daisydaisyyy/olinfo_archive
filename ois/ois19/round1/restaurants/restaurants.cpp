/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// input data
int N, i, j;
int vote, best = 0;

int main() {

    //uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int winner = 1;

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++) {
        int temp = 0;
        for(j=0; j<=N; j++) {
            assert(1 == scanf("%d", &vote));
            // TODO: Do something with 'vote'
            if(vote != -1)  temp += vote;

        }
        if(temp > best)  {
            best = temp;  
            winner = i + 1;
        }
        printf("%d\n", winner);
    }

    return 0;
}
