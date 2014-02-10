//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>

const int N = 4;
const int K = 4;

const char tr[] = {'+', '-', '*', '/'};

float calc(int k, float a, float b){
    float v = -1;
    switch(k){
    case 0: v = a+b; break;
    case 1: v = a-b; break;
    case 2: v = a*b; break;
    case 3: v = (b == 0) ? 0 : a/b; break;
    }
    // printf("haha: %d %d %d= %d\n", a, b, k, v);
    return v;
}

void solve(int ar[]){
    int perm[N];
    for (int ii = 0; ii < N; ++ii) perm[ii] = ar[ii];
    do {
        int i,j,k,l;
        i = perm[0];
        j = perm[1];
        k = perm[2];
        l = perm[3];
        // printf("got %d %d %d %d\n", i,j,k,l);

        for (int cali = 0; cali < (4*4*4); ++cali)
            {
                int a = cali % 4;
                int b = (cali >> 2) % 4;
                int c = (cali >> 4);

                float f1 = calc(a, i, j);
                float f2 = calc(b, f1, k);
                float v = calc(c, f2, l);
                // printf("%d %d %d\n", a, b, c);
                // printf("%d %d %d\n", a, i, j);
                // printf("%d %c %d %c %d %c %d = %d\n", i, tr[a], j, tr[b], k, tr[c], l, v);
                if (v == 24.0) {
                    // printf("%f %f %f\n", f1, f2, v);
                    printf("((%d %c %d) %c %d) %c %d = 24\n", i, tr[a], j, tr[b], k, tr[c], l);
                    return;
                }
            }
    } while (std::next_permutation(perm, perm + N));
}

int main(int argc, char *argv[])
{
    int a[] = {1,8,3,9};
    solve(a);
    return 0;
}
