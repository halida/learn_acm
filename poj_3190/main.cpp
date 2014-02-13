//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3190
// time spend: 14:39 - 15:28 16:20-16:51 1:20
// failed:
// - forget to optimize on min
// - slow, then use priority_queue
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

const int MAXN = 50000;
const int MAXI = 1000000;

int s[MAXN]; // stalls assign

typedef pair <int, int> sm;
std::priority_queue< sm, vector<sm>, greater<sm> > se;


typedef pair < int, int > interval;

int n;
interval ps[MAXN];

void solve(){

    int stalls = 0;

    // for each item
    for (int i = 0; i < n; ++i)
        {
            int is = ps[i].first;
            int ie = ps[i].second;
            sm t;

            // check min stall
            if (!se.empty() ){
                t = se.top();
                // printf("%d - %d\n", t.first, t.second);
            } else {
                t.first = INF;
            }

            // if all conflict, new stall
            if (t.first > is) {
                t.first = ie;
                t.second = stalls;
                se.push(t);
                s[i] = stalls;
                stalls ++;
                // printf("%d-%d: %d, stalls:%d\n", is, ie, s[i], stalls);
            } else {
                // if find min, update new end
                se.pop();
                s[i] = t.second;
                t.first = ie;
                se.push(t);
            }
        }

    printf("%d\n", stalls);
    for (int i = 0; i < n; ++i)
        {
            printf("%d\n", s[i]+1);
        }
};

void scan(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &ps[i].first, &ps[i].second);
        }
}

int main(int argc, char *argv[])
{
    scan();
    solve();
    return 0;
}
