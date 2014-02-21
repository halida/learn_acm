//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3280
// time spend: 11:28-11:45 14:03-17:23 = 3:39
//
// a-b M * M
// 没有注意 没有中间值的状况
// 数组边界没有看清楚
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

const long long INF = 1 << 29;

const int MAXN = 26;
const int MAXM = 2000;

int N;
int M;

char am[MAXM]; // chars

map <char, int>ma;

long long dp[MAXM+1][MAXM];

void show(){
    for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < M; ++j)
                {
                    printf("%5lld ", (dp[i][j] == INF) ? -1 : dp[i][j]);
                }
            printf("\n");
        }
}

void solve(){

    // set to INF
    for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < M; ++j)
                {
                    if (i == j || i == j+1) {dp[i][j] = 0;}
                    else{dp[i][j] = INF;}
                }
        }

    for (int i = -1; i < M; ++i)
        {
            for (int j = 0; j < M; ++j)
                {
                    int a = j;
                    int b = j+i;
                    if (b >= M) break;
                    if (b < 0) continue;
                    long long me = b<0 ? 0 : dp[a][b];

                    // - a + a
                    if (a > 0){
                        long long v = me + ma[am[a-1]];
                        if (b >= 0){
                            dp[a-1][b] = min(dp[a-1][b], v);
                        }
                    }

                    // - b + b
                    if (b < M){
                        long long v = me + ma[am[b+1]];
                        dp[a][b+1] = min(dp[a][b+1], v);
                    }

                    // same
                    if (a > 0 && b < M && am[a-1] == am[b+1]){
                        dp[a-1][b+1] = min(dp[a-1][b+1], me);
                    }
                    // show(); printf("\n");
                }
        }

    // show();
    printf("%lld\n", dp[0][M-1]);
};

void scan(){
    scanf("%d %d", &N, &M);
    while(getc(stdin) != '\n'); // clear return
    for (int i = 0; i < M; ++i){ scanf("%c", &am[i]); };

    for (int i = 0; i < N; ++i)
        {
            char c;
            int add; int del;
            cin >> c >> add >> del;
            ma[c] = min(add, del);
            // printf("%c=%d\n", c, ma[c]);
            // printf("%c=%d\n", c, md[c]);
        }
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
