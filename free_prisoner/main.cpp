//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <algorithm>
// #include <deque>
// #include <map>

#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 2<<20;

const int MAX_P = 100;
const int DPS = MAX_P + 2;

const int p = 20;
const int q = 3;
const int a[] = {1, 3, 6, 14, 21};

int dp[DPS][DPS];

void showdp(){
    for (int i = 0; i < q+2; ++i)
        {
            for (int j = 0; j < q+2; ++j)
                {
                    printf("%d\t", dp[i][j]);
                }
            printf("\n");
        }
}

void solve(){

    for (int i = 0; i < q+2; ++i)
        {
            for (int j = 0; j < q+2; ++j)
                {
                    int s = j, e = j+i;
                    if (e >= q+2) break;

                    if (i<=1) {
                        dp[s][e] = 0;
                        continue;
                    };

                    int minv = INF;
                    for(int k = 0; k < sizeof(a); ++k){
                        if (k <= s || k >= e) continue;
                        int newv = a[e]-a[s]-1 + dp[s][k] + dp[k][e];
                        printf("newv: %d\n", newv);
                        minv = min(minv, newv);
                    };
                    dp[s][e] = minv;
                    printf("(%d - %d) = (%d - %d)= %d\n", s, e, a[s], a[e], minv);
                };
        };

    printf("result: %d\n", dp[0][MAX_P+1]);

    showdp();
}

int main(int argc, char *argv[])
{
    solve();
    return 0;
}
