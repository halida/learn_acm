//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1065
// time spend: 19:03-20:58 = 2:00
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

const int MAXN = 5000;

int N;

typedef pair<int, int> p;

p data[MAXN];

void solve(){
    printf("%d\n", N);
};

void scan(){
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        {
            scanf("%d", &N);
            for (int j = 0; j < N; ++j)
                {
                    scanf("%d %d", &data[j].first, &data[j].second);
                }
            solve();
        }
}

int main(int argc, char *argv[])
{
    scan();
    return 0;
}
