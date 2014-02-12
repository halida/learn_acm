//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=3187
// time spend: 16:30 - 16: 59 = 0:30
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

const int MAXC = 10;

int n, s;
int a[MAXC];
int t[MAXC];

void show(){
    for (int i = 0; i < n; ++i)
        {
            printf("%d", a[i]);
            if (i != n-1) { printf(" "); }
            else { printf("\n"); }
        }
}

int count(){
    memcpy(t, a, n*sizeof(int));

    // for (int i = 0; i < n; ++i)
    //     {
    //         printf("%d ", t[i]);
    //     }
    // printf("\n");
    for (int i = 0; i < n-1; ++i)
        {
            for (int j = 0; j < n-i-1; ++j)
                {
                    t[j] = t[j] + t[j+1];
                }
        }
    return t[0];
}

void solve(){
    for (int i = 0; i < n; ++i)
        {
            a[i] = i+1;
        }

    do {
        int v = count();
        if (v == s) { show(); break; }
    } while(std::next_permutation(a, a+n));
    // printf("-1");
};

int main(int argc, char *argv[])
{
    scanf("%d %d", &n, &s);
    solve();

    // n = 10;
    // for (int i = 0; i < n; ++i)
    //     {
    //         a[i] = i+1;
    //     }
    // a[0] = 9;
    // a[8] = 1;
    // printf("c= %d\n", count());

    return 0;
}
