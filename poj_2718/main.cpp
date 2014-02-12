//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2718
// time spend: 16:38 - 17:32 08:30 - 09:30 11:00 - 
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

int vc;
char va[MAXC];
bool g[MAXC];

char line[1000];

void getinput(){
    gets(line);
    // printf("line=%s\n", line);
    for (int i = 0; i < 1000; ++i)
        {
            if (i % 2 == 0) va[i/2] = line[i];
            if (line[i] == '\0') { vc = (i+1)/2; break; }
        }
    // printf("count = %d\n", vc);
    // printf("%s", va);
    // printf("\n");
}

int solvemin(int k){
    char a[MAXC];
    char b[MAXC];
    memset(a, 0, MAXC);
    memset(b, 0, MAXC);
    int na=0, nb=0;

    // create table
    for (int i = 0; i < vc; ++i)
        {
            if ((k >> i) % 2 == 0) { a[na++] = va[i]; }
            else {b[nb++] = va[i]; };
        }

    // printf("on: %d\n", k);
    // printf("%s\n", a);
    // printf("%s\n", b);

    // iter all posible combination
    int minv = INF;
    do {
        // permu a
        if (a[0] == '0' && na > 1) continue;

        // find min?
        

        // do {
        //     if (b[0] == '0' && nb > 1) continue;
        //     // printf("%d - %d\n", atoi(a), atoi(b));
        //     minv = min( abs(atoi(a) - atoi(b)), minv );
        // } while(std::next_permutation(b, b+nb));

    } while(std::next_permutation(a, a+na));

    // printf("minv: %d\n", minv);
    return minv;
}

int findb(int k){
    int v = 0;
    for (int i = 0; i < vc; ++i)
        {
            if ((k >> i) % 2 == 1)  v++;
        }
    return v;
}

void solve(){
    int minv = INF;
    // for each possible sep
    for (int i = 0; i < (1 << (vc-1))-1; ++i)
        {
            // find min
            int k = i+1;
            int c = findb(k);
            // printf("k=%d, c= %d\n", k, c);

            // only consider seq near item middle
            if (abs(c - vc/2) > 1) continue;

            minv = min(minv, solvemin(k));
        }
    printf("%d\n", minv);
};

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    gets(line);
    for (int i = 0; i < t; ++i)
        {
            getinput();
            solve();
        }
    return 0;
}
