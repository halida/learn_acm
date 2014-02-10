//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <deque>
#include <map>
#include <stdio.h>

const int SIZE = 4;
const int INF = 2^30;

typedef int CHESS[SIZE][SIZE];

CHESS S = {{0,1,2,2}, {1,1,2,2}, {1,1,2,2}, {1,1,2,2}};
CHESS T = {{0,2,1,2}, {2,1,2,1}, {1,2,1,2}, {2,1,2,1}};

int SS;
int ST;

std::map<int, int> dp;
std::map<int, bool> fp;
// int dp[3^22];
// char sp[3^22];
// bool fp[3^22];

int c2s(CHESS c){
    int r = 0;
    int e = 0;
    for (int i = 0; i < SIZE*SIZE; ++i)
        {
            r <<= 1;
            // printf("%d ", c[i/SIZE][i%SIZE]);
            // if (i%SIZE == 3) printf("\n");
            switch(c[i/SIZE][i%SIZE]){
            case 0:
                e = i;
                break;
            case 1:
                break;
            case 2:
                r += 1;
                break;
            };
        }
    // printf("e = %d\n", e);
    r <<= 4;
    r += e;
    return r;
}

void print_chess(CHESS c){
    printf("chess: %x\n", c2s(c));
    for (int i = 0; i < SIZE*SIZE; ++i)
        {
            printf("%d ", c[i/SIZE][i%SIZE]);
            if (i%SIZE == 3) printf("\n");
        };
}

void s2c(int s, CHESS c){
    memset(c, 1, sizeof(CHESS));
    int e = s % 16;
    s >>= 4;
    for (int i = SIZE*SIZE-1; i >= 0; --i)
        {
            if (s % 2 == 0){
                c[i/SIZE][i%SIZE] = 1;
            } else {
                c[i/SIZE][i%SIZE] = 2;
            }
            s >>= 1;
        };
    c[e/SIZE][e%SIZE] = 0;
    // printf("%x\n", s);
    // print_chess(c);
}

const int DIRX[] = {0, 1, 0, -1};
const int DIRY[] = {-1, 0, 1, 0};
const int REVERSE_DIR[] = {2, 3, 0, 1};
const char DIR_NAME[] = {'U', 'R', 'D', 'L'};

bool get_nt(CHESS ct, int d, CHESS nt){
    memcpy(nt, ct, sizeof(CHESS));

    // get e
    int e = -1;
    int ex, ey;
    for (int i = 0; i < SIZE*SIZE; ++i)
        {
            if (ct[i/SIZE][i%SIZE] == 0) {
                e = i;
                break;
            }
        };
    if (e == -1) exit(-1);

    ey = e/SIZE;
    ex = e%SIZE;

    int dx = DIRX[d];
    int dy = DIRY[d];

    int nx = ex+dx;
    int ny = ey+dy;

    // move e
    if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) return false;
    int t = nt[ny][nx];
    nt[ny][nx] = 0;
    nt[ey][ex] = t;

    // print_chess(ct);
    // print_chess(nt);
    // printf("e=%d\n\n",e);
    return true;
}

void show_step(){
    int cs = ST;
    CHESS ct;
    s2c(cs, ct);

    int steps[dp[ST]-1];

    int oo = 100;
    while(cs != SS && oo > 0){
        oo --;
        for (int d = 0; d < 4; d++)
            {
                CHESS tt;
                get_nt(ct, d, tt);
                int ts = c2s(tt);
                if (dp[ts] == dp[cs] - 1){
                    // printf("%x to %x with direction: %c\n", cs, c2s(tt), DIR_NAME[d]);
                    // print_chess(tt);

                    steps[ dp[cs] -2 ] = REVERSE_DIR[d];
                    // printf("%d\n", dp[cs]);
                    cs = c2s(tt);
                    s2c(cs, ct);
                }
            }
    }

    cs = SS;
    for (int i = 0; i < dp[ST]-1; ++i) {
        s2c(cs, ct);

        int d = steps[i];

        CHESS tt;
        get_nt(ct, d, tt);
        cs = c2s(tt);

        // printf("move: %c\n", DIR_NAME[d]);
        // print_chess(tt);
        printf("%c", DIR_NAME[d]);
    }
    printf("\n");
}


void solve(){
    // memset(dp, INF, sizeof(dp));

    std::deque<int> a;

    SS = c2s(S);
    ST = c2s(T);
    printf("SS = %x\n", SS);
    printf("ST = %x\n", ST);

    a.push_back(SS);
    printf("a.size = %d\n", (int)a.size());
    dp[SS] = 1;

    int oo = 20000;
    CHESS ct, nt;
    int cs, ns;
    do {
        // oo --;

        cs = a.front();
        a.pop_front();

        s2c(cs, ct);
        if (fp[cs]) continue;
        fp[cs] = true;
        if (cs == ST) break;

        // print_chess(ct);
        // printf("step of %x: %d\n", cs, dp[cs]);
        for (int d=0; d<4; d++) {
            if (! get_nt(ct, d, nt) ) continue;
            int ns = c2s(nt);
            // print_chess(nt);

            if (dp[ns] == 0 or dp[cs]+1 < dp[ns]){
                dp[ns] = dp[cs]+1;
            };
            // printf("ns = %x, fp[ns]= %d\n", ns, fp[ns]);
            if (! fp[ns]) a.push_back(ns);
        };

        // printf("a.size = %d\n", static_cast<int>(a.size()));
    } while ( oo > 0 && a.size() > 0 );

    printf("oo = %d\n", oo);
    printf("a.size = %d\n", static_cast<int>(a.size()));
    printf("dp.size = %d\n", static_cast<int>(dp.size()));
    printf("step: %d\n", dp[cs]-1);
    print_chess(ct);
    printf("\n\n");

    show_step();
}


int main(int argc, char *argv[])
{
    solve();
    return 0;
}
