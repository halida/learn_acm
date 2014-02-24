//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3181
// time spend: 9:15-10:36 14:34-15:17 = 2:03
// 思考：
// Cn = Cn-1 + Cn-2 + ... Cn-k (k <= K,n-1) + 1(if n <= K)
// C1 = 1
// 然后优化掉最后的一个加法
//
// 卡关：
// 出现高精度！
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

const int MAXN = 1000;
const int MAXK = 100;

unsigned long long bigsize = 1e+16;
unsigned long long bigsizen = 9;

class Big {
public:
    unsigned long long up;
    unsigned long long down;

    Big(int v){
        this->up = 0;
        this->down = v;
    };
    Big(){this->up = 0; this->down = 0;};

    Big operator+=(Big nAdd)
    {
        this->up += nAdd.up;
        this->down += nAdd.down;

        this->up += this->down / bigsize;
        this-> down %= bigsize;

        return *this;
    }

    void show(){
        // printf("%llu\n", bigsize);
        if (this->up > 0){
            printf("%llu%016llu", up, down);
        } else {
            printf("%llu", down);
        }
    };
};

int N, K;
Big dp[MAXN+1][MAXK+1];

void solve(){
    memset(dp, 0, (MAXN+1)*(MAXK+1)*sizeof(int));
    for (int i = 1; i <= K; ++i) { dp[0][i] = 1; dp[1][i] = 1; }
    for (int i = 0; i <= N; ++i) dp[i][1] = 1;

    for (int i = 2; i <= N; ++i)
        {
            Big s = 1;
            for (int j = 2; j <= K; ++j)
                {
                    if(j <= i) s += dp[i-j][j];
                    dp[i][j] = s;
                }
        }

    // for (int i = 0; i <= N; ++i)
    //     {
    //         for (int j = 1; j <= K; ++j)
    //             {
    //                 printf("%lld ", dp[i][j]);
    //             }
    //         printf("\n");
    //     }
    dp[N][K].show();
    printf("\n");
};

void scan(){
    scanf("%d %d", &N, &K);
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
