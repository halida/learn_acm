//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2385
// time spend: 15:03-15:30 11:15-11:27 = 0:39
// 动态规划，少处理了一个边界条件浪费了12分钟
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
