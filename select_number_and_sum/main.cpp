//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

bool solve(int a[], unsigned int size, int m){
    for (int i = 0; i < size; ++i)
        {
            for (int j = i+1; j < size; ++j)
                {
                    for (int k = j+1; k < size; ++k)
                        {
                            for (int l = k+1; l < size; ++l)
                                {
                                    if (a[i] + a[j] + a[k] + a[l] == m) {
                                        printf("%d + %d + %d + %d = %d\n", a[i], a[j], a[k], a[l], m);
                                        return true;
                                    }
                                }
                        }
                }
        }
    return false;
}

int binary_search(int a[], unsigned int size, int m){
    int l=0, r=size-1;
    while ( l <= r){
        int mid = (l + r) / 2;
        if (mid < 0 ) mid = 0;
        // printf("%d, %d, %d = %d %d\n", l, r, mid, m, a[mid]);

        if (a[mid] == m) return mid;
        if (a[mid] >  m)
            {
                r = mid-1;
            }
        else 
            {
                l = mid+1;
            };
    }
    return -1;
}

bool fastsolve(int a[], unsigned int size, int m){
    // 2 level array init
    int a2[size * (size-1)];
    int pa2 = 0;
    for (int i = 0; i < size; ++i)
        {
            for (int j = i+1; j < size; ++j)
                {
                    a2[pa2] = a[i] + a[j];
                    pa2 ++;
                    // printf("%d=%d\n", i*size + j, a2[i*size + j]);
                }
        }

    // sort
    // for (int i = 0; i < pa2; ++i) {
    //     printf("%d\n", a2[i]);
    // }
    std::sort(a2, a2 + pa2);

    // query
    for (int i = 0; i < size; ++i)
        {
            for (int j = i+1; j < size; ++j)
                {
                    int v = binary_search(a2, pa2, (m - a[i] - a[j]));
                    // printf("search for  %d = %d\n", m - a[i] - a[j], v);
                    if (v >= 0) {
                        // int k = a2[v % size];
                        // int l = a2[v / size];
                        // printf("%d + %d + %d + %d = %d\n", a[i], a[j], a[k], a[l], m);
                        return true;
                    }
                }
        }
    return false;
}


int main(int argc, char *argv[])
{
    int a1[] = {1, 2, 3, 4, 4, 5, 6};
    assert(fastsolve(a1, 7, 15) == true);
    assert(solve(a1, 7, 150) == false);

    return 0;
}
