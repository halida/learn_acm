//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1328
// time spend: 09:54 - 11:36 14:25 - 14:37 = 2:42 + 0:12 = 2:54
// failed: 
// - compile error: sqrt format
// - x,y float
// - d float
// - output format mismatch
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

const float INF = 10000;

const int MAXN = 1000;

typedef pair<float, float> pos;

pos islands[MAXN];
int n;
float d;

float cover(float x, float y){
    return x + sqrt((float)(d*d - y*y));
}

bool iscover(float prex, float x, float y){
    if (prex == -INF) return false;

    float dx = x - prex;
    if (dx < 0) dx = -dx;
    return (d*d - y*y >= dx*dx);
}

int solve(){
    sort(islands, islands+n);

    float prex = -INF;
    int c = 0;

    for (int i = 0; i < n; ++i)
        {
            float x= islands[i].first;
            float y= islands[i].second;

            // no possible
            if (y > d) { return -1; };

            // covered
            if ( iscover(prex, x, y) ) { continue; };

            if (prex > x) {
                // on left move prex left to cover
                prex = cover(x, y);
            } else { // on right
                // right up or out range cover new
                prex = cover(x, y);
                c++;
            };

            // printf("x: %d, y: %d\n", x, y);
            // printf("c: %d, prex: %3f\n", c, prex);
        }

    return c;
};

bool scan(){
    scanf("%d %f", &n, &d);
    for (int i = 0; i < n; ++i)
        {
            scanf("%f %f", &islands[i].first, &islands[i].second);
        }

    // printf("n=%d, d=%d\n", n, d);
    return (n > 0);
}

int main(int argc, char *argv[])
{
    int c = 1;
    while( scan() ) {
        printf("Case %d: %d\n", c, solve());
        c++;
    }
    return 0;
}
