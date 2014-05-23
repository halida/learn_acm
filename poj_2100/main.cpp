//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2100
// time spend: 14:20-15:03 硬算，TLA了，发现只需要pair而不是deque -15:31 = 1:10
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

typedef unsigned long long int BigSize;
BigSize n = 0;

typedef pair<BigSize, BigSize> Answer;
vector<Answer> result; 

void solve(){
    BigSize t = n;
    Answer c;
    c.first = 0;
    c.second = 0;
    BigSize l = sqrt((double)n) + 100;

    for (BigSize i = 1; i <= n; ++i)
        {
            BigSize v = i * i;
            // printf("t=%lld, i=%lld,v=%lld\n", t, i, v);

            while(t < v) {
                if (c.first > c.second) { // i bigger than n
                    return;
                }
                t += c.first * c.first;
                c.first ++;
            }

            t -= v;
            c.second = i;
            if (t == 0){
                // add result;
                result.push_back(c);
            }
        }
}

void show_result(){
    printf("%d\n", (int)result.size());
    for (int i = 0; i < result.size(); ++i)
        {
            Answer v = result[i];
            if (v.first == 0) v.first++;
            printf("%lld ", v.second-v.first+1);

            for (BigSize j = v.first; j <= v.second; ++j)
                {
                    printf("%lld", j);
                    if (j!=v.second) printf(" ");
                }
            printf("\n");
        }
}

int main(int argc, char *argv[])
{
    scanf("%lld", &n);
    solve();
    show_result();

    return 0;
}

