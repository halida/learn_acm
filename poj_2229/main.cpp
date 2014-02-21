//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2229
// time spend: 14:33-15:02 16:34-17:30 9:44-11:12 = 3:00
// 考虑了半天，还是看了disscuss才弄懂
// 解法：单数和前一个一样，复数 = 1+1的形式和没有1+1的形式，1+1形式=i-2，没有1+1所有除以2就等同i/2了。
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

const int MAXN = 1000000;

const long long MAXI = 1000000000;

int N;

long long dp[MAXN];

void solve(){
    // printf("%d\n", count(N));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++)
        {
            if (i%2==0) {
                dp[i] = dp[i/2] + dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
            dp[i] %= MAXI;
            // printf("%d=%lld\n", i, dp[i]);
        }
    printf("%lld\n", dp[N]);
}

void scan(){
    scanf("%d", &N);
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
