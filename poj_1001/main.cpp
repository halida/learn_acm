//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1001
// time spend: 07:46-09.17 = 1:31 7:56-9:35 = 1:39
//----------------------------------------------------------
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long LL;

char s[10];
int n = 0;

const int c = 1;
const int mul = 10;

void show(vector<LL> mv){
    cout << "mul: ";
    for (int i = 0; i < mv.size(); ++i)
        {
            printf("%ld, ", mv[i]);
        }
    printf("\n");
}

void solve(){
    // printf("val: '%s' ** %d\n", s, n);
    // scan value to int and p
    int v = 0;
    int p = 0;
    for (int i = 0; i < strlen(s); ++i)
        {
            if (s[i] == '.') {
                p = strlen(s) - 1 - i;
            } else {
                v *= 10;
                v += int(s[i] - '0');
            }
        }
    // remove 0's
    while((v % 10 == 0) && (p > 0)){
        v /= 10;
        p --;
    }
    // cout << "spl: " << v << ", " << p << endl;

    // multiply
    vector <LL> mv;
    mv.push_back(v);

    if (n == 0) {
        mv[0] = 1;
    } else {
    }

    // multi first
    for (int i = 0; i < n; ++i)
        {
            int len = mv.size();

            // mul
            if (i < n-1) {
            for (int j = 0; j < len; ++j)
                {
                    mv[j] *= v;
                }
            }

            // mod
            int j = 0;
            while(j < mv.size()) {
                // printf("%d, %d\n", j, mv.size());
                int mod = mv[j] / mul;
                if (mod <= 0) {j++; continue;};

                if (j >= mv.size()-1) {
                    // at last
                    mv.push_back(mod);
                } else {
                    mv[j+1] += mod;
                }
                mv[j] %= mul;
                j++;
            };
        }

    // show(mv);

    int mp = p*n;
    int mm = mv.size();
    int pf = mm - mp;
    // printf("mp: %d, mm: %d, pf: %d\n", mp, mm, pf);

    // add pf
    if (mp > 0) {
    if (mp < mm){
        std::vector<LL>::iterator it;
        it = mv.begin();
        it += mp;
        mv.insert(it, -1); // -1 as pts
    } else {
        for (int i = 0; i < (mp-mm); ++i)
            {
                mv.push_back(0);
            }
        mv.push_back(-1);
    }
    }

    // show result
    for (int i = mv.size()-1; i >= 0; --i)
        {
            if (mv[i] == -1){
                printf(".");
            } else {
                printf("%ld", mv[i]);
            }
        }
    printf("\n");
}


int main(int argc, char *argv[])
{
    while(cin>>s>>n) {
        solve();
    }
    return 0;
}

