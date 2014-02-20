//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3262 
// time spend: 10:01 - 11:35
//
// 抽象成(0,0) - (SumT, SumD)的曲线面积，往下的曲线对应的面积最小
// result : 86
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

const int MAXN = 100000;
const int MAXT = 2000000;
const int MAXD = 100;
int N;

typedef pair<int, int> P;
P tds[MAXN];

bool compare(P a, P b){
    float ca = a.first/(float)a.second;
    float cb = b.first/(float)b.second;

    bool result = (ca < cb);
    // printf("a: %d,%d b: %d,%d = %d\n",
    //        a.first, a.second, b.first, b.second,
    //        result);
    return result;
}

void solve(){
    // optimized
    sort(tds, tds+N, &compare);
    for (int i = 0; i < N; ++i)
        {
            // printf("%d %d\n", tds[i].first, tds[i].second);
        }

    // sum all d
    long long rd = 0;
    for (int i = 0; i < N; ++i)
        {
            rd += tds[i].second;
        }

    long long result = 0;
    for (int i = 0; i < N; ++i)
        {
            rd -= tds[i].second;
            result += rd * tds[i].first * 2;
        }
    printf("%lld\n", result);
};

void scan(){
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        {
            scanf("%d %d", &tds[i].first, &tds[i].second);
        }
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
