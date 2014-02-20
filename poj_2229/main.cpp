//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2229
// time spend: 14:33-15:02 
// result: 6
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

const double MAXI = 1000000000;

int N;

int dp[MAXN];

int count(int n){
    int r = 1;
    for (int i = 2; i < n; ++i)
        {
            int p = i;
            int o = 0;
    
            while(p > 0){
                o += (p%2==0);
                p >>= 1;
            }
            // printf("n=%d, o=%d\n", i, o);
            r += o;
        }
    return r;
};

void solve(){
    printf("%d\n", count(N));
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
