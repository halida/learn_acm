//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3616
// time spend: 15:38-16:28 = 0:50
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

const int MAXM = 1000;
const int MAXN = 1000000;
const int MAXE = 1000000;

typedef struct{
    int s, e;
    int eff;
}inter;

int N, M, R;

inter data[MAXM];
long dp[MAXM];

bool compare(inter a, inter b){
    return (a.e < b.e);
}

void solve(){
    sort(data, data+M, &compare);
    // for (int i = 0; i < M; ++i)
    //     {
    //         printf("%d %d %d\n", data[i].s, data[i].e, data[i].eff);
    //     }

    for (int i = 0; i < M; ++i)
        {
            long m = 0;
            for (int j = 0; j < i; ++j)
                {
                    if (data[j].e + R > data[i].s) continue;
                    m = max(dp[j], m);
                }
            dp[i] = m + data[i].eff;
        }

    printf("%ld\n", *max_element(dp, dp+M));
};

void scan(){
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 0; i < M; ++i)
        {
            inter it;
            scanf("%d %d %d", &it.s, &it.e, &it.eff);
            data[i] = it;
        }
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
