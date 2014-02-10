//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <assert.h>
#include <algorithm>
#include <iostream>

using namespace std;

int solve(int array[], unsigned int size);

int main(int argc, char *argv[]) {
    int a1[] = {1, 2, 3, 4, 4, 5, 6};
    assert(solve(a1, sizeof(a1) / sizeof(int)) == 15);

    int a2[] = {1, 2, 3, 14, 5, 6, 111};
    assert(solve(a2, sizeof(a2) / sizeof(int)) == 14);

    int a3[] = {6, 111, 1111, 2222};
    assert(solve(a3, sizeof(a3) / sizeof(int)) == 0);

    int a4[] = {};
    assert(solve(a4, sizeof(a4) / sizeof(int)) == 0);

    return 0;
};

int solve(int a[], unsigned int size){
    std::sort(a, a+size);
    for (int i = size-1; i>=2; --i){
        if (a[i] > a[i-1] + a[i-2]) continue;
        return a[i] + a[i-1] + a[i-2];
    }
    return 0;
};
