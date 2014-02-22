//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1742
// time spend: 18:55-19:53 18:25-20:27 = 3:00
//
// (m, n)
// 循环m，循环coin值a, 数量c，看m-ia可以不(i=1-c) m*n
// 硬搜： m * n * c = 10 ** 10
// 每次搜索 n*c 如果没有数量限制，可以检查 m - Ai
// 循环每个coin，循环m，根据数量，检查前一个v，标注现在v-1
//
// 卡关：没有发现可以重新利用dp
// memset用错
// TLE 发现printf没有删除
//----------------------------------------------------------
#include <algorithm>
// #include <vector>
// #include <deque>
// #include <queue>
// #include <map>

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 1 << 29;

const int MAXN = 100;
const int MAXM = 100000;

int ac[MAXN];
int aa[MAXN];

int N;
int M;

typedef struct {
    char up;
    char down;
} T;

int dp[MAXM+1];
bool ok[MAXM+1];

void solve(){
    int all = 0;

    memset(ok, 0, (M+1)*sizeof(bool));
    for (int j = 0; j < N; ++j)
        {
            memset(dp, 0, (M+1)*sizeof(int));

            int c = ac[j];
            int a = aa[j];

            // first
            if (!ok[a]) {ok[a] = true; all++; dp[a] = 1;};

            for (int i = a; i <= M; ++i)
                {
                    if (ok[i]) continue;
                    int pre = dp[i - a];

                    // printf("rep: %d, ok:%d, dp:%d\n", i-a, ok[i-a], dp[i-a]);
                    if (ok[i - a] && (pre < c)) {
                        // printf("set: %d=%d, with c:%d\n", i, pre+1, c);
                        ok[i] = true; all++;
                        dp[i] = pre + 1;
                    }
                }
        }

    printf("%d\n", all);
};

bool scan(){
    scanf("%d %d", &N, &M);
    if (N == 0) return false;

    for (int i = 0; i < N; ++i) scanf("%d", &aa[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &ac[i]);
    return true;
}

int main(int argc, char *argv[])
{
    while( scan() ) solve();
    return 0;
}
