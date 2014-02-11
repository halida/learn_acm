//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <algorithm>
#include <vector>
#include <deque>
#include <map>

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_S = 100+100;

int w;
int h;

char m[MAX_S][MAX_S]; // map
bool u[MAX_S][MAX_S]; // used

typedef pair<int, int> pos;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

pos getnext(int i, pos p){
    p.first += dx[i];
    p.second += dy[i];
    return p;
}

void walk(int x, int y){
    vector<pos> s;
    s.push_back(pos(x, y));
    char tile = m[y][x];

    while(!s.empty()){
        pos p = s.back();
        s.pop_back();

        if(u[p.second][p.first]) continue;
        u[p.second][p.first] = true;

        for (int i = 0; i < 4; ++i)
            {
                pos next = getnext(i, p);
                if (next.first < 0 || next.first >= w || next.second < 0 || next.second >= h)continue;
                if (m[next.second][next.first] != tile) continue;
                
                s.push_back(next);
            }
    }
}

void solve(){
    memset(u, 0, MAX_S*MAX_S);

    int count = 0;
    for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
                {
                    if(u[i][j]) continue;
                    count ++;
                    walk(j, i);
                }
        }
    printf("%d\n", count);
};

int main(int argc, char *argv[])
{
    while(true){
        scanf("%d %d", &h, &w);
        if(w <= 0) break;
        for (int i = 0; i < h; ++i)
            {
                scanf("%s", m[i]);
            }
        solve();
    }
    return 0;
}
