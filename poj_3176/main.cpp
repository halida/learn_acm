//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3176
// time spend: 14:18-14:31 = 0:13
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

const int MAXN = 350;

int N;

int data[MAXN][MAXN];

int dp[MAXN+1];

void solve(){
    memset(dp, 0, MAXN+1);
    for (int i = N-1; i >= 0; --i)
        {
            for (int j = 0; j < i+1; ++j)
                {
                    dp[j] = max(dp[j], dp[j+1]) + data[i][j];
                }
        }
    printf("%d\n", dp[0]);
};

void scan(){
    memset(data, 0, MAXN*MAXN);
    scanf("%d", &N);
    // printf("%d\n", N);
    for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < (i+1); ++j)
                {
                    scanf("%d", &data[i][j]);
                    // printf("%d= %d,", j, data[i][j]);
                }
            // printf("\n");
        }
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
