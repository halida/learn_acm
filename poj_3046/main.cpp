//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3046
// time spend: 20:45-22:16 11:32-13:29 08:23-9:07 = 4:15
//
// T * MAXA = 1000 * 100 * 1000
// T * C * (MAXA = T*C) = 100 * 100 * 1000
//
// 卡关：
// 找规律找了很久
// 找优化算法找了很久
// 没有看到结果6位的提示
// 6位在运算的时候溢出了
//
// 算法：
// 默认方法：
// for i = 1 - alla:
// for all T:
// for k = max(1, i-olda), min(c, i):
//     i - k <= olda
//     i - k >= 0
//     i - c <= i - k <= i
//         n[i] += o[i-k]
//
// 优化递推，发现不用每个都加，而是维护一个待加量
//
// 找规律
//
// {}
// {1}
// {1,1}

// 2*3
// {}
// {1}, {2} + o[0]
// {1,1}, {1,2}, {2,2} + o[0] + o[1]
// {2,2,2} + o[0]

// {}
// {1} {2} + o[0]
// {1,1} {1,2} {2,2} + o[0] + o[1]
// {1,1,2} {1,2,2} + o[1] + +o[2]
// {1,1,2,2} + o[2]

// {}
// {1} {2} {3} +o[0]
// {1,1} {1,2} {2,2} {2,3} {1,3} +o[1]
// {1,1,2} {1,2,2} {1,1,3} {1,2,3} {2,2,3}  +o[2]
// {1,1,2,2} {1,1,2,3} {1,2,2,3} + o[3]
// {1,1,2,2,3} + o[4]
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

const int MAXN = INF;

const int MAXT = 1000;
const int MAXA = 100*MAXT;
const int MOD = 1000000;

int T, A, S, B;

int af[MAXT];

long dp1[MAXA+1];
long dp2[MAXA+1];

void solve(){
    memset(dp1, 0, sizeof(int) * A);
    memset(dp2, 0, sizeof(int) * A);
    long *dp = dp1;
    long *odp = dp2;

    int olda = 0;
    dp1[0] = 1;
    dp2[0] = 1;

    for (int j = 0; j < T; ++j)
        {
            long t = 0;
            int c = af[j];
            if (c==0) continue;

            for (int i = 1; (i <= min(olda + c, B)); ++i)
                {
                    if (i-1 <= olda) t += odp[i-1];
                    if (i > c) t -= odp[i-c-1];
                    dp[i] = (t + odp[i]) % MOD;
                    // printf("t:%d=%d ", t, dp[i]);
                }
            // printf("\n");

            olda += c;

            // swap
            long *tt = dp;
            dp = odp;
            odp = tt;
        }

    long all = 0;
    for (int i = S; i <= B; ++i)
        {
            all += odp[i];
            all %= MOD;
        }
    printf("%ld\n", all);
};

void scan(){
    memset(af, 0, MAXT*sizeof(int));
    scanf("%d %d %d %d", &T, &A, &S, &B);
    for (int i = 0; i < A; ++i)
        {
            int d;
            scanf("%d", &d);
            af[d-1] ++;
        }
    // for (int i = 0; i < T; ++i)
    //     {
    //         printf("%d=%d\n", i, af[i]);
    //     }
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
