//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <assert.h>

#include <algorithm>
#include <deque>
#include <map>

#include <iostream>
#include <stdio.h>

const int MAX_K = 100000;
const int MAX_N = 100;

int dp[MAX_K + 1];
int n = 3;
int a[] = {3,5,8};
int m[] = {3,2,2};
int k = 17;

void solve(){
    memset(dp, -1, sizeof(dp));
    dp[0] = m[0];
    // int r = k;

    for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= k; ++j)
                {
                    if (dp[j] >= 0) {
                        dp[j] = m[i];
                    } else if ( j < a[i] || dp[j - a[i]] <= 0) {
                        dp[j] = -1;
                    } else {
                        dp[j] = dp[j - a[i]] - 1;
                    };
                }
            // r -= a[i] * (m[i]-dp[k]);
            // printf("get a=%d count %d, remain %d\n", a[i], m[i]-dp[k], r);
        }

    // show result
    // for (int i = 0; i < k+1; ++i)
    //     {
    //         printf("%d=%d \n", i, dp[i]);
    //     }
    printf("result: %d\n", dp[k]);
}

int main(int argc, char *argv[])
{
    solve();
    return 0;
}
