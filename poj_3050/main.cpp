//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3050
// time spend: 17:00 - 17:19 = 0:19
//----------------------------------------------------------
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 1 << 29;

const int SIZE = 5;

int m[SIZE][SIZE];

map<int, bool> mm;

void scanmap(){
    for (int i = 0; i < SIZE; ++i)
        {
            scanf("%d %d %d %d %d", &m[i][0], &m[i][1], &m[i][2], &m[i][3], &m[i][4]);
        }
}

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void check(int x, int y, int h, int v){
    if (h == 0) {
        if (! mm[v] ) mm[v] = true;
        return;
    }
    for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE) continue;
            check(nx, ny, h-1, v*10 + m[ny][nx]);
        }
}

void solve(){
    for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
                {
                    check(j, i, 5, m[i][j]);
                }
        }
    printf("%d\n", (int)mm.size());
}

int main(int argc, char *argv[])
{
    scanmap();
    solve();

    return 0;
}
