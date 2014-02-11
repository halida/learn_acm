//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0033
//----------------------------------------------------------
#include <algorithm>
#include <vector>
#include <deque>
#include <map>

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXL = 10;

int numbers[MAXL];

bool can_solve(int i, int a, int b){
    int v = numbers[i];
    if (i >= MAXL) return true;

    if (v > a && can_solve(i+1, v, b)) return true;
    if (v > b && can_solve(i+1, a, v)) return true;
    return false;
}

bool solve(){
    return can_solve(0, -1, -1);
};

int main(int argc, char *argv[])
{
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; ++i)
        {
            scanf("%d %d %d %d %d %d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5], &numbers[6], &numbers[7], &numbers[8], &numbers[9]);
            bool result = solve();
            if ( solve() ){ printf("YES\n"); }
            else { printf("NO\n"); }
        }
    return 0;
}
