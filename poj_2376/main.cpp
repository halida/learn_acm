//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2376
// time spend: 08:14 - 09:43 = 1:30
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

// typedef struct {
//     int s, e;
// }range;

typedef pair<int, int> range;

const int MAXN = 25000;
const int MAXT = 1000000;

int n, t;

range cows[MAXN];
// vector<int> ps[MAXT+1];

void solve(){
    sort(cows, cows+n);

    int s = 1;
    int c = 0;

    while(s <= t){
        int maxe = 0;
        for (int i = 0; i < n; ++i)
            {
                if (cows[i].first > s) break;
                maxe = max(maxe, cows[i].second);
            }

        if (maxe < s) { printf("-1\n"); return; }

        // printf("maxe: %d\n", maxe);
        s = maxe + 1;
        c++;
    }

    printf("%d", c);
}

void scan(){
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &cows[i].first, &cows[i].second);
        }
    // printf("scan: %d, %d\n", n, t);
}

int main(int argc, char *argv[])
{
    scan();
    solve();

    return 0;
}
