//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=1001
// time spend: 07:46-09.17 = 1:31
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

typedef long long LL;

char s[10];
int n;

const int c = 5;
const int mul = 100000;

int exp(int v){
    int r = 1;
    for (int i = 0; i < v; ++i)
        {
            r *= 10;
        }
    return r;
}

int getl(LL v){
    if (v == 0) return 0;
    char buffer[10];
    int n = sprintf(buffer, "%lld", v);
    return n;
};

void ppp(int v, int l, int t){
    printf("ppp: %d, %d, %d\n", v, l, t);

    int vl = getl(v);
    int d = exp(vl) / 10;

    for (int i = 0; i < l; ++i)
        {
            if (t == i) printf(".");
            int m = v / d;
            v -= m * d;
            d /= 10;
            printf("%d", m);
        }
}

void solve(){
    printf("val: '%s' ** %d\n", s, n);

    // scan value to int and p
    LL v = 0;
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
    cout << "spl: " << v << ", " << p << endl;

    // multiply
    vector <LL> mv;
    mv.push_back(v);

    // multi first
    for (int i = 0; i < n-1; ++i)
        {
            int len = mv.size();
            // mul
            for (int j = 0; j < len; ++j)
                {
                    mv[j] *= v;
                }
            // mod
            for (int j = 0; j < len; ++j)
                {
                    LL mod = mv[j] / mul;
                    if (mod <= 0) continue;

                    if (j >= mv.size()-1) {
                        mv.push_back(mod);
                    } else {
                        mv[j+1] += mod;
                    }
                    mv[j] %= mul;
                }
        }
    if (n == 0) mv[0] = 0;

    cout << "mul: ";
    for (int i = 0; i < mv.size(); ++i)
        {
            printf("%lld, ", mv[i]);
        }
    printf("\n");

    int mp = p*n;
    int mm = mv.size() * c - c + getl(mv[mv.size()-1]);
    int pf = mm - mp;
    printf("pts: %d, %d\n", mp, mm);

    // when p*n > lm, puts zeros
    if (mp >= mm) {
        printf("0.");
        for (int i = 0; i < (mp-mm); ++i)
            {
                printf("0");
            }
    }

    // puts results and p accordinary
    int t = pf;
    for (int i = mv.size()-1; i >=0; --i)
        {
            int v = mv[i];
            int l = c;
            char s[10];
            if (i==mv.size()-1){
                sprintf(s, "%d", v);
            } else {
                sprintf(s, "%05d", v);
            }
            // add t
            if (0<t && t<strlen(s))
                {
                    char tmp = '.';
                    for (int i = t; i <= strlen(s); ++i)
                        {
                            tmp = s[i];
                            s[i] = tmp;
                        }
                }
            // remove end 0
            // todo
            printf("%s", s);
            t -= l;
        }
    printf("\n");

    printf("\n");
}


int main(int argc, char *argv[])
{
    while(cin>>s>>n) {
        solve();
    }
    return 0;
}

