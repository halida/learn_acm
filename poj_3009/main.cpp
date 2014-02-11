//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// http://poj.org/problem?id=3009
//----------------------------------------------------------
#include <algorithm>
#include <vector>
#include <deque>
#include <map>

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 1 << 29;

const int MAX_S = 20 + 2;

int m[MAX_S][MAX_S]; // map
int u[MAX_S][MAX_S]; // cache for min step

int w, h;

int sx, sy;
int gx, gy;

const int dxt[] = {-1, 0, 1, 0};
const int dyt[] = {0, 1, 0, -1};


void move(int x, int y, int s){
    if (s >= 10) return;
    for (int i = 0; i < 4; ++i)
        {
            int dx = dxt[i];
            int dy = dyt[i];
            int nx = x;
            int ny = y;

            // cannot move
            if (m[ny+dy][nx+dx] != 0) continue;

            // find point
            while(true){
                int nnx = nx+dx;
                int nny = ny+dy;

                // out of map
                if (nnx < 0 || nnx >= w || nny < 0 || nny >= h) {
                    break;
                }

                // hit
                if (m[nny][nnx] == 1) {
                    // hit and stop
                    u[ny][nx] = min(s+1, u[ny][nx]);
                    m[nny][nnx] = 0;
                    move(nx, ny, s+1);
                    m[nny][nnx] = 1;
                    break;
                }

                // touch goal
                if (nny == gy && nnx == gx){
                    u[nny][nnx] = min(s+1, u[nny][nnx]);
                    return;
                }

                nx += dx;
                ny += dy;
            }
        }
}

void solve(){
    // find start and goal, and init
    for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
                {
                    u[i][j] = INF;
                    if (m[i][j] == 2) { sx = j; sy = i; m[i][j] = 0; }
                    if (m[i][j] == 3) { gx = j; gy = i; m[i][j] = 0; }
                }
        }
    // printf("start=%d,%d goal=%d,%d\n",sx, sy, gx, gy);
    u[sy][sx] = 0;
    move(sx, sy, 0);

    if (u[gy][gx] == INF) u[gy][gx] = -1;
    printf("%d\n", u[gy][gx]);
};

int main(int argc, char *argv[])
{
    while(true){
        scanf("%d %d", &w, &h);
        // printf("%d, %d\n", w, h);
        if (w <= 0) break;
        for (int i = 0; i < h; ++i)
            {
                for (int j = 0; j < w; ++j)
                    {
                        scanf("%d", &m[i][j]);
                    }
            }

        solve();
    }
    return 0;
}
