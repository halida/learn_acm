//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <algorithm>
#include <deque>
#include <vector>
#include <map>

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_S = 100;

short int m[MAX_S][MAX_S];
bool tm[MAX_S][MAX_S]; //already walked

int ux, uy;
int w, h;

typedef pair<int, int> pos;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

pos newd(int i, pos p){
    p.first += dx[i];
    p.second += dy[i];
    return p;
}

void solve(){
    memset(tm, 0, MAX_S*MAX_S);

    deque<pos> nc;

    nc.push_back(pos(ux, uy));
    int ps = 0;
    
    while(!nc.empty()){
        pos p = nc.back();
        nc.pop_back();

        // checked
        if(tm[p.second][p.first]) continue;

        //walked
        // printf("%d,%d\n", p.first, p.second);
        tm[p.second][p.first] = true;
        ps ++;

        for(int i=0; i<4; i++){
            pos np = newd(i, p);
            // out of map
            if( 0 > np.first || 0 > np.second || w <= np.first || h <= np.second) continue;

            // checked
            if(tm[np.second][np.first]) continue;
            // blocked
            if(m[np.second][np.first] == 1) continue;

            // to go
            nc.push_back(np);
            // printf("%d,%d\n", np.first, np.second);
        }
    }
    printf("%d\n", ps);
};

int main(int argc, char *argv[])
{
    while(true){
        scanf("%d %d", &w, &h);
        if (w <= 0) break;

        // get map
        memset(m, 0, MAX_S*MAX_S);

        for (int i = 0; i < h; ++i)
            {
                char line[MAX_S];
                scanf("%s", line);
                // printf("ho:%d, %s_\n", i, line);
                for (int j = 0; j < w; ++j)
                    {
                        if(line[j] == '#') {
                            m[i][j] = 1;
                        }
                        if(line[j] == '@') {
                            uy = i;
                            ux = j;
                        }
                    }
            }

        solve();
    }
}
