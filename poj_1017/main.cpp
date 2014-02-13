//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1017
// time spend: 19:02 - 19:42 = 0:40
//
// check:
// 4 5 6 each once
// 4: 5*2 or 20
// 3: 1/4, remain: 1: 5*2, 2: 3*2, 3: 1*2
// 6: 9*2
// 10*2 3+5 less if sep 3*3 to 2*3 + 1*3
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

int a1, a2, a3, a4, a5, a6;

void solve(){
    int r = a6 + a5 + a4;
    int c2= a4*5;
    int c1= a5*11;

    // for 3*3
    r += a3 / 4;
    a3 %= 4;
    if (a3 > 0) r++;

    switch(a3){
    case 0:
        break;
    case 1:
        c2+=5; c1+=7;
        break;
    case 2:
        c2+=3; c1+=6;
        break;
    case 3:
        c2+=1; c1+=5;
        break;
    }

    // for 2*2
    if (a2 > c2) {
        a2 -= c2;

        r += a2/9;
        a2 %= 9;
        if (a2 > 0) {
            r++;
            c1 += 36 - a2*4;
        }
    } else {
        c2 -= a2;
        c1 += c2 * 4;
    }
    // printf("c1:%d, c2:%d\n", c1, c2);

    // for 1*1
    a1 -= c1;
    if (a1 > 0) {
        r += a1 / 36;
        if (a1 % 36 > 0) r++;
    }

    printf("%d\n", r);
};

bool scan(){
    scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
    return ( a1 + a2 + a3 + a4 + a5 + a6 != 0);
}

int main(int argc, char *argv[])
{
    while(scan()){solve();}
    
    return 0;
}
