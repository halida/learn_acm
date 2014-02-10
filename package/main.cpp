//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>


const int size = 12;
const int maxw = 20;
const int maxv = 10;
const unsigned int INF = 2^15;
int w[] = {2,5,6,3,1,2,3,4,6,7,1,2};
int v[] = {9,7,5,8,3,4,7,1,2,3,8,6};

int dp[size+1][maxw+1];
int short direction[size+1][maxw+1];

int vp[size+1][maxv * size + 1];

void max_by_value(){
    memset(vp, INF, sizeof(vp));
    vp[0][0] = 0;

    for (int i = 1; i < size+1; ++i)
        {
            for (int j = 0; j < maxv * size + 1; ++j)
                {
                    int res = 0;
                    if (j < v[i-1]) {
                        res = 0;
                    } else {
                        res = std::min(
                                       vp[i-1][j],
                                       vp[i][j - v[i-1]] + w[i-1]
                                       );
                    };
                    vp[i][j] = res;
                    printf("%2d ", res);
                }
            printf("\n");
        }

    int s = 0;
    int sj;
    for (sj = maxv*size; sj >= 0; --sj)
        {
            if (vp[size][sj] <= maxw) break;
        }
    printf("max value: %d\n", sj);
};

int max_value(int i, int j){ // item and remain weight
    if (dp[i][j] >= 0) return dp[i][j];

    int res = 0;
    if (i >= size) {
        res = 0;
    }
    else if (w[i] > j) {
        res = max_value(i+1, j); 
    }
    else {
        int ui = max_value(i+1, j-w[i]) + v[i];
        int ni = max_value(i+1, j);

        if (ui > ni) {
            direction[i][j] = 1;
        }
        res = std::max(ui, ni);
    }

    dp[i][j] = res;
    return res;
}

void print_result(){
    int j=maxw;
    int cv=0;
    for(int i=0; i<size; i++){
        if (direction[i][j] > 0) {
            cv += v[i];
            printf("choose item %d with w=%d, v=%d, cw=%d, cv=%d\n", i, w[i], v[i], j, cv);
            j -= w[i];
        }
    }
    printf("\n\n");
}

void dpf(){
    memset(dp, 0, sizeof(dp));
    memset(direction, 0, sizeof(direction));

    for (int i = size-1; i >= 0; --i)
        {
            for (int j = 0; j <= maxw; ++j)
                {
                    int res = 0;
                    if (w[i] > j) {
                        res = dp[i+1][j];
                    } else {
                        res = std::max(dp[i+1][j],
                                       dp[i+1][j-w[i]] + v[i]);
                        if (res != dp[i][j]) direction[i][j] = 1;
                    };
                    dp[i][j] = res;
                    // printf("%3d ", res);
                }
            // printf("\n");
        }
}

void m1(){
    memset(dp, -1, sizeof(dp));
    memset(direction, 0, sizeof(direction));
    printf("max value is : %d\n", max_value(0, maxw));
    print_result();

    dpf();
    printf("max value is : %d\n", dp[0][maxw]);
    print_result();
}




int main(int argc, char *argv[])
{
    m1();
    max_by_value();
    return 0;
}



