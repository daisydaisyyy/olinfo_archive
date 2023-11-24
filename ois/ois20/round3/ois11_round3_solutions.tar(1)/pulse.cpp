/*
Author: Pop Ioan Cristian -- Politehnica University of Bucharest
Solution: Breadth First Search
Time Complexity: O(N*N+P)
Memory Complexity: O(N*N)
*/

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
    int x, y;
};

int dx[] = {-1, 0, 1, 0, 0}, dy[] = {0, 1, 0, -1, 0};
bool p[7][13][13], ok[60][502][502], viz[60][502][502];
queue <point> q, oldq;

int nxt(int x) {
    return (x + 1) % 60;
}

int main()
{
//    freopen("pulse.in", "r", stdin);
//    freopen("pulse.out", "w", stdout);

    p[0][6][6] = 1;
    for (int t = 1; t < 6; ++t) {
        for (int i = 6 - t; i <= 6 + t; ++i)
            for (int j = 6 - t; j <= 6 + t; ++j) {
                p[t][i][j] = p[t - 1][i][j];

                if (p[t][i][j] == 0)
                for (int k = 0; k < 4; ++k) {
                    if (p[t - 1][i + dx[k]][j + dy[k]] == 1) {
                        p[t][i][j] = 1;
                        break;
                    }
                }
            }
    }

    int n, k, x, y, r;
    scanf("%d %d", &n, &k);
    for (int l = 1; l <= k; ++l) {
        scanf("%d %d %d", &x, &y, &r);
        for (int t = 0; t < r; ++t)
            for (int i = 6 - t; i <= 6 + t; ++i)
                if (i + x - 6 > 0 && i + x - 6 <= n)
                    for (int j = 6 - t; j <= 6 + t; ++j)
                         if (j + y - 6 > 0 && j + y - 6 <= n)
                             for (int q = 0; t + r * q < 60; ++q)
                                ok[t + r * q][i + x - 6][j + y - 6] = max(ok[t + r * q][i + x - 6][j + y - 6], p[t][i][j]);
    }

    /*for (int t = 0; t < 60; ++t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                printf("%d ", ok[t][i][j]);
            printf("\n");
        }
        printf("\n");
    }*/

    point aux, nou;
    aux.x = aux.y = 1;
    viz[0][1][1] = 1;
    oldq.push(aux);

    for (int t = 0; ; ++t) {
        while (!oldq.empty()) {
            aux = oldq.front();
            oldq.pop();
            for (int dir = 0; dir < 5; ++dir) {
                nou.x = aux.x + dx[dir];
                if (nou.x < 1 || nou.x > n)
                    continue;
                nou.y = aux.y + dy[dir];
                if (nou.y < 1 || nou.y > n)
                    continue;

                if (ok[nxt(t)][nou.x][nou.y] == 0 && viz[nxt(t)][nou.x][nou.y] == 0) {
                    if (nou.x == n && nou.y == n) {
                        printf("%d\n", t + 1);
                        return 0;
                    }
                    viz[nxt(t)][nou.x][nou.y] = 1;
                    q.push(nou);
                }
            }
        }
        if (q.empty())
        {
            printf("No solution\n");
            break;
        }

        while (!q.empty()) {
            oldq.push(q.front());
            q.pop();
        }
    }
    return 0;
}
