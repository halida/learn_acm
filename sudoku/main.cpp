//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2676
// time spend: 14:32 - 15:03 = 31 minutes
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

const int N = 9;
const int D = 100;
const int E = 9;

int input[N][N];

bool possible(int p, int y, int x){
    // vertical
    for (int i = 0; i < E; ++i)
        {
            if (i == x) continue;
            if (input[y][i] == p) return false;
        }

    // horizontal
    for (int i = 0; i < E; ++i)
        {
            if (i == y) continue;
            if (input[i][x] == p) return false;
        }

    // square
    int px = (x/3) * 3;
    int py = (y/3) * 3;
    // printf("x=%d,y=%d,px=%d,py=%d\n",x,y,px,py);
    for (int i = 0; i < 3; ++i)
        {
            int ny = py+i;
            for (int j = 0; j < 3; ++j)
                {
                    int nx = px+j;
                    // printf("%d,%d=%d ", ny, nx, input[ny][nx]);
                    if (ny == y && nx == x) continue;
                    if (input[ny][nx] == p) return false;
                }
        }
    return true;
}

int find_next(){
    for (int i = 0; i < E; ++i)
        {
            for (int j = 0; j < E; ++j)
                {
                    if (input[i][j] == 0) return i*D+j;
                }
        }
    return D-1;
}

bool solve(){
    int v = find_next();
    int i = v/D;
    int j = v%D;
    // printf("check %d, %d\n", i,j);

    if (j == D-1) return true;

    for (int p = 1; p <= N; ++p)
        {
            if ( possible(p, i, j) )
                {
                    // printf("try value %d on %d, %d\n", p, i,j);
                    input[i][j] = p;
                    if ( solve() ) return true;
                }
            input[i][j] = 0;
        }
    return false;
};

void scan(){
    memset(input, 0, N*N);
    char c;
    for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                {
                    scanf("%c", &c);
                    input[i][j] = c-48;
                }
            scanf("%c", &c);
        }

}

int main(int argc, char *argv[])
{
    scan();
    solve();

    for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                {
                    printf("%d ", input[i][j]);
                }
            printf("\n");
        }

    return 0;
}
