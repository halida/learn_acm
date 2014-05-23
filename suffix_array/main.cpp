//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: suffix array
// time spend: 20:53
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

const int MAXL = 100;

char S[MAXL];
int n;
int sa[MAXL];

void construct_suffix(){
}

int comp(char a, char b){
    
}

int matchs(char * v){
    int vl=strlen(v);
    int l=0;
    int r=n;

    // find first match
    while(true){
        if (l >= r) break;

        int m = (l+r)/2;
        if (S[ m ] <= *v) {
            l = m+1;
        } else {
            r = m;
        }
    }

    // ++ until all match or fail
    while(true) {
        int v = strcmp(v, S[l]);
        if (v == 0) {
            printf("%d\n", l);
            return;
        } else if ( v < 0) {
            print("-1\n", l);
            return;
        } else {
            l++;
        }
    }
}

void scan(){
    memset(S, 0, MAXL);
    scanf("%s", S);
    n = strlen(S);
    construct_suffix();

    char v[MAXL];
    while(true){
        scanf("%s", v);
        printf("%d\n", matchs(v));

        if(v[0] == '0') break;
    }
}

int main(int argc, char *argv[])
{
    scan();

    return 0;
}
