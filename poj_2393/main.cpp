//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2393
// time spend: 16:53 - 17:29 = 0:36
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

int S, N;

const int MAXN = 10000;
const int MAXC = 5000;
const int MAXS = 100;

int C[MAXN];
int Y[MAXN];
long long p = 0;

void solve(){
    int s = 0;

    // for each week
    for (int i = 0; i < N; ++i)
        {
            int mini = 0;
            int minc = INF;
            // for each possible production day
            for (int j = s; j < i+1; ++j)
                {
                    int cost = C[j] + (i - j)*S;
                    
                    // find min cost
                    if (minc > cost){
                        mini = j;
                        minc = cost;
                    }
                }
            // update cost
            p += Y[i] * ( minc );
            // P[mini] += Y[i];
            s = mini;
        }

    // show result
    printf("%lld\n", p);
};

void scan(){
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; ++i)
        {
            scanf("%d %d", &C[i], &Y[i]);
        }
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
