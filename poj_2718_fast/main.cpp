//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// url: http://poj.org/problem?id=2718
// time spend: 15:00 - 16:20 = 1:20
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
deque <int> va;

char line[1000];

void getinput(){
    gets(line);
    // printf("line=%s\n", line);
    for (int i = 0; i < 1000; ++i)
        {
            if (i % 2 == 0) va.push_back(line[i] - '0');
            if (line[i] == '\0') { vc = (i+1)/2; break; }
        }
    // printf("count = %d\n", vc);
    // printf("%s", va);
    // printf("\n");
}


int toi(vector<int> a){
    int v = 0;
    for (int i = 0; i < a.size(); ++i)
        {
            v *= 10;
            v += a[i];
        }
    return v;
}


int check(vector <int> a, vector <int> b){
    // printf("va size %d\n", (int)va.size());
    // the form biggest in small and smallest in bigger
    for (int i = 0; i < va.size()/2; ++i)
        {
            a.push_back(va[i]);
        }
    for (int i = va.size()-1; i >= va.size()/2; --i)
        {
            if (i<0) break;
            b.push_back(va[i]);
        }

    int va = toi(a), vb = toi(b);
    int minv = va-vb;
    // printf("a=%d,b=%d, min:%d\n", va, vb, minv);
    // printf("%d\n", minv);
    return minv;
}

void solve(){
    vector <int> a;
    vector <int> b;
    // for (int i = 0; i < va.size(); ++i)
    //     {
    //         printf("%d,", va[i]);
    //     }
    // printf("\n");
    // printf("vc=%d\n", vc);

    // if odd, find smallest one as head
    if (vc % 2 == 1) {
        if (va[0] != 0) {
            a.push_back(va[0]);
            va.pop_front();
        } else {
            a.push_back(va[1]);
            va.erase(va.begin()+1, va.begin()+2);
        }

        int mmv = check(a, b);
        printf("%d\n", mmv);

    } else {
        // if even, find nearest ones

        int minv = INF;
        int mini = 0;
        for (int i = 0; i < va.size()-1; ++i)
            {
                if ((va[i+1] - va[i]) > minv) continue;
                if(va[i] == 0 && va.size() > 2) continue; // 0 cannot place on head
                minv = min(minv, va[i+1] - va[i]);
                mini = i;
            }
        // printf("mini: %d\n", mini);

        // and check it
        int mmv = INF;
        for (int i = 0; i < va.size()-1; ++i)
            {
                if ((va[i+1] - va[i]) > minv) continue;
                if(va[i] == 0 && va.size() > 2) continue; // 0 cannot place on head
                int p = va[i+1];
                int q = va[i];

                a.push_back(p);
                b.push_back(q);

                va.erase(va.begin() + i, va.begin() + i + 2);
                // printf("va:%d, a:%d, b:%d\n", (int)va.size(), (int)a.size(), (int)b.size());
                mmv = min(mmv, check(a, b));
                // cleanup
                va.insert(va.begin() + i, p);
                va.insert(va.begin() + i, q);
                a.clear();
                b.clear();
                // printf("va:%d, a:%d, b:%d\n", (int)va.size(), (int)a.size(), (int)b.size());
            }
        printf("%d\n", mmv);
    }
};

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    gets(line);
    for (int i = 0; i < t; ++i)
        {
            va.clear();
            getinput();
            solve();
        }
    return 0;
}
