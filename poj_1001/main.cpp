//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1001
// time spend: 15:10-
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

const int INF = 1 << 29;

char s[10];
int n;
int sv;
int dot;

void solve(){
    // locate dot
    sv = 0;
    dot = 0;
    int sl = strlen(s);
    for (int i = 0; i < sl; ++i)
        {
            if (s[i] == '.')
                {
                    dot = (sl-i-1);
                }
            else
                {
                    sv *= 10;
                    sv += s[i] - '0';
                }
        }
    // printf("%d, %d, %d \n", dot, sv, n);

    // caculate
    vector<long long> result;
    result.push_back(1);

    const int OO = 100000;

    for (int i = 0; i < n; ++i)
        {
            int rrs = result.size();
            for (int j = 0; j < rrs; j++)
                {
                    result[j] *= sv;
                }

            long long overflow = 0;
            for (int j = 0; j < rrs; ++j)
                {
                    overflow = result[j] / OO;
                    result[j] %= OO;
                    if (j < rrs-1) {
                        result[j+1] += overflow;
                    }
                }
            if (overflow > 0){
                result.push_back(overflow);
            }
        }
    // int rsf = result.size();
    // for (int i = 0; i < rsf; ++i)
    //     {
    //         printf("%lld ", result[rsf - i - 1]);
    //     }
    // printf("\n");

    deque<int> ls;
    int rs = result.size();
    for (int i = 0; i < rs; ++i)
        {
            int v = result[i];
            // printf("%d\n", v);
            for (int j = 0; j < 5; ++j)
                {
                    ls.push_back(v % 10);
                    v /= 10;
                }
        }
    while(ls.back() == 0) ls.pop_back();
    // for (int i = 0; i < ls.size(); ++i) printf("%d", ls[i]);
    // printf("\n");
    // return;

    int level = n * dot;
    const int DOT = 22;
    if (level != 0) {
        if (level > ls.size()) {
            for (int i = 0; i < (level - ls.size()); ++i) ls.push_back(0);
            ls.push_back(DOT);
            ls.push_back(0);
        } else {
            ls.insert(ls.begin()+level, DOT);
        }
        while(ls.front() == 0) ls.pop_front();
    }

    // for (int i = 0; i < ls.size(); ++i) printf("%d", ls[i]);
    // printf("\n");
    // return;

    for (int i = ls.size()-1; i >= 0 ; --i)
        {
            if (ls[i] == DOT) {
                printf(".");
            } else {
                printf("%d", ls[i]);
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

