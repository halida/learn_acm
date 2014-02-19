//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3040
// time spend: 12:32 - 12:52 18:05 - 18:38 13:25 - 14:48 = 2:16
//
// 解法：先从大到小，不超过的情况下尽量多取，然后从小到大超过了取
// 还是看了提示之后做出来的。。
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

const int MAXN = 20;

typedef long long coin;

int N;
coin C;

typedef pair<coin, coin> P;
vector<P> cs;

void solve(){
    int result = 0;

    while(true){
        int costs[MAXN];
        memset(costs, 0, sizeof(costs));

        // loop fill
        coin r = C;
        for (int i = 0; i < N; ++i)
            {
                // find fill count
                coin c = r / cs[i].first;
                c = min(cs[i].second, c);

                r -= c * cs[i].first;
                costs[i] += c;
                if (r == 0) break;
            }

        // loop back fill all
        for (int i = N-1; i >= 0; --i)
            {
                if (r <= 0) break;

                coin c = (r / cs[i].first) + 1;
                c = min(cs[i].second - costs[i], c);
                r -= c * cs[i].first;
                costs[i] += c;
            }
        // not enough now
        if (r > 0) { break;}


        // find count
        coin mm = INF;
        // printf("\n\nfirst get\n");
        for (int i = 0; i < N; ++i)
            {
                // printf("%lld*%d\n", cs[i].first, costs[i]);
                if (costs[i] <= 0) continue;
                // printf("getting: %lld\n", cs[i].second / costs[i]);
                mm = min( mm, cs[i].second / costs[i]);
            }
        // printf("count: %lld\n", mm);

        // caculate
        result += mm;
        for (int i = 0; i < N; ++i)
            {
                cs[i].second -= costs[i] * mm;
            }
    }

    printf("%d\n", result);
};

void scan(){
    scanf("%d %lld", &N, &C);
    for (int i = 0; i < N; ++i)
        {
            P p;
            scanf("%lld %lld", &p.first, &p.second);
            cs.push_back(p);
        }
    sort(cs.begin(), cs.end());
    reverse(cs.begin(),cs.end());
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
