//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1862
// time spend: 09:10 - 09:29
//
// lg f(a, b) = lg2 + 1/2*lg(a) + 1/2*lg(b)
// lg f(c, d) = lg2 + 1/2*lg(a) + 1/2* ( lg2 + 1/2*lg(a) + 1/2*lg(b) )
// 最先算的数压缩最大
// 排序，先算大的数，这样结果最小
//----------------------------------------------------------
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int INF = 1 << 29;

const int MAXN = 100;
const int MAXR = 10000;

int N;
int ns[MAXN];

float count(float a, float b){
    return 2 * sqrt(a * b);
}

void solve(){
    float r = ns[0];
    for (int i = 1; i < N; ++i)
        {
            // printf("%.3f\n", r, ns[i]);
            r = count(r, ns[i]);
        }
    printf("%.3f\n", r);
};

void scan(){
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        {
            scanf("%d", &ns[i]);
        }
    sort(ns, ns+N);
    reverse(ns, ns+N);
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
