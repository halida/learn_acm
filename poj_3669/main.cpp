//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3669
// time spend: 14:53 - 16:13 : 1:20
//----------------------------------------------------------
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 1 << 29;

const int MAX_S = 300 + 4;
const int MAX_M = 50000;

int mc;

int dp[MAX_S][MAX_S]; // map with min time to get to point
bool mv[MAX_S][MAX_S];

typedef struct {
    int x, y;
    int t;
} pos;


const int dxt[] = {-1, 0, 1, 0};
const int dyt[] = {0, 1, 0, -1};

pos getnext(int i, pos p){
    p.x += dxt[i];
    p.y += dyt[i];
    return p;
}

void solve(){
    memset(mv, 0, MAX_S*MAX_S);

    queue <pos> q;
    pos p; p.x = 0; p.y = 0; p.t = 0;
    q.push(p);

    while(!q.empty()){
        p = q.front();
        q.pop();

        // check checked
        if (mv[p.y][p.x]) continue;
        mv[p.y][p.x] = true;

        for (int i = 0; i < 4; ++i)
            {
                pos n = getnext(i, p);
                n.t = p.t + 1;
                // only in quadrant 1 
                if (n.x < 0 || n.y < 0) continue;
                // check checked
                if (mv[n.y][n.x]) continue;
                // check hit
                if (dp[n.y][n.x] <= n.t) continue;
                // check safe
                if (dp[n.y][n.x] == INF) { printf("%d\n", n.t); return; }

                q.push(n);
            }
    }
    // cannot avoid
    printf("%d", -1);
}

int main(int argc, char *argv[])
{
    scanf("%d", &mc);
    // init map
    for (int i = 0; i < MAX_S; ++i)
        {
            for (int j = 0; j < MAX_S; ++j)
                {
                    dp[i][j] = INF;
                }
        }

    // minimum time to hit point
    for (int i = 0; i < mc; ++i)
        {
            int mx, my, mt;
            scanf("%d %d %d", &mx, &my, &mt);

            dp[my][mx] = min(dp[my][mx], mt);
            pos t; t.x = mx; t.y = my;
            for (int j = 0; j < 4; ++j)
                {
                    pos n = getnext(j, t);
                    if (n.x < 0 || n.y < 0 || n.x >= MAX_S || n.y >= MAX_S ) continue;
                    dp[n.y][n.x] = min(dp[n.y][n.x], mt);
                }
        }

    // show map
    // for (int i = 0; i < MAX_S; ++i)
    //     {
    //         printf("\n");
    //         for (int j = 0; j < MAX_S; ++j)
    //             {
    //                 if (dp[i][j] == INF) { printf(". "); }
    //                 else { printf("%d ", dp[i][j]); }
    //             }
    //     }
    solve();

    return 0;
}
