//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1151
// time spend: 12:20-12:53
// 增加一个map，判断重复的区块，面积剪掉重复的
// 一维线段树：10*5 = 10,维护当前区块的面积
// 二维线段树，2个线段树分别维护，都覆盖了才覆盖
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

const int MAXT = 1000;
const int MAXW = 30;

int T;
int W;

int a[MAXT];
int dp[2][MAXW+1];

void solve(){
    memset(dp, 0, 2*MAXW);

    for (int i = 0; i < T; ++i)
        {
            for (int k = 0; k <= W; ++k)
                {
                    for (int j = 0; j < 2; ++j)
                        {
                            if (k!=W) {
                                dp[j][k] = max(dp[j][k], dp[(j+1)%2][k+1]);
                            }
                            dp[j][k] += (a[i] == (j+1) ? 1 : 0);
                            // printf("%d,", dp[j][k]);
                        }
                    // printf("\t");
                }
            // printf("\n");
        }
    printf("%d\n", max(*max_element(dp[0], dp[0]+W), *max_element(dp[1], dp[1]+W)));
};

void scan(){
    scanf("%d %d", &T, &W);
    for (int i = 0; i < T; ++i)
        {
            scanf("%d", &a[i]);
        }
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
